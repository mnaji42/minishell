/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchudant <cchudant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 07:34:24 by cchudant          #+#    #+#             */
/*   Updated: 2020/01/13 18:29:33 by cchudant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			open_redir(t_redir *redir)
{
	int ret;
	int flags;

	if (redir->dir == REDIR_IN)
		flags = O_RDONLY;
	else if (redir->dir == REDIR_OUT)
		flags = O_WRONLY | O_CREAT | O_TRUNC;
	else
		flags = O_WRONLY | O_CREAT | O_APPEND;
	if ((ret = open(redir->file, flags, 0666)) < 0)
	{
		ft_putstr("minishell: ");
		ft_putstr(strerror(errno));
		ft_putstr(": ");
		ft_putendl(redir->file);
	}
	return (ret);
}

int			get_redir(t_prog *prog, t_fdcls *in, t_fdcls *out)
{
	int i;

	i = -1;
	while (++i < prog->nb_redir)
	{
		if (prog->redir[i].dir == REDIR_IN)
		{
			if (in->must_close)
				close(in->fd);
			if ((*in = (t_fdcls) { open_redir(&prog->redir[i]), 1 }).fd < 0)
				return (0);
		}
		else
		{
			if (out->must_close)
				close(out->fd);
			if ((*out = (t_fdcls) { open_redir(&prog->redir[i]), 1 }).fd < 0)
				return (0);
		}
	}
	return (1);
}

static int	exec_child_entrypoint(t_minishell *mn, t_prog *prog,
				t_fdcls fdin, t_fdcls fdout)
{
	char *path;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (!get_redir(prog, &fdin, &fdout) && free_all(&mn->ln, mn, NULL) >= 0)
		exit(1);
	if (!(path = get_executable(prog->cmd[0])))
		exit(127);
	if (fdin.fd != 0)
		dup2(fdin.fd, 0);
	if (fdin.fd != 1)
		dup2(fdout.fd, 1);
	if (fdin.fd != 2)
		dup2(fdout.fd, 2);
	if (fdin.fd > 1)
		close(fdin.fd);
	if (fdout.fd > 1)
		close(fdout.fd);
	execve(path, prog->cmd, env_get_as_array());
	free_all(&mn->ln, mn, NULL);
	ft_putstr("minishell: ");
	ft_putendl(strerror(errno));
	exit(1);
}

static void	exec_proc(t_minishell *mn, t_processus *proc)
{
	int	i;
	int	fds[2];
	int	last_fds[2];

	i = -1;
	while (++i < proc->nb_prog)
	{
		last_fds[0] = fds[0];
		last_fds[1] = fds[1];
		close_u(i > 0 ? last_fds[1] : -1);
		if (i < proc->nb_prog - 1)
			pipe(fds);
		if (!handle_builtin(mn, &proc->prog[i],
				(t_fdcls) { i > 0 ? last_fds[0] : 0, 0 },
				(t_fdcls) { i < proc->nb_prog - 1 ? fds[1] : 1, 0 }) &&
				!wrap_fork())
		{
			close_u(i < proc->nb_prog - 1 ? fds[0] : -1);
			exec_child_entrypoint(mn, &proc->prog[i],
					(t_fdcls) { i > 0 ? last_fds[0] : 0, 0 },
					(t_fdcls) { i < proc->nb_prog - 1 ? fds[1] : 1, 0 });
		}
		close_u(i > 0 ? last_fds[0] : -1);
	}
	wait_children();
}

void		exec_group(t_minishell *mn, t_group *grp)
{
	if (grp->type == GRP_PROC)
		exec_proc(mn, grp->proc);
	else if (grp->type == GRP_AND)
	{
		exec_group(mn, grp->left);
		if (!*get_last_return_status())
			exec_group(mn, grp->right);
	}
	else if (grp->type == GRP_OR)
	{
		exec_group(mn, grp->left);
		if (*get_last_return_status())
			exec_group(mn, grp->right);
	}
	else if (grp->type == GRP_PAR)
		exec_group(mn, grp->left);
}
