/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <mnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 07:34:24 by cchudant          #+#    #+#             */
/*   Updated: 2020/01/13 20:04:21 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_builtin_entry	g_builtins[] = {
	{ .name = "echo", .fn = &builtin_echo },
	{ .name = "exit", .fn = &builtin_exit },
	{ .name = "pwd", .fn = &builtin_pwd },
	{ .name = "cd", .fn = &builtin_cd },
	{ .name = "export", .fn = &builtin_export },
	{ .name = "unset", .fn = &builtin_unset },
	{ .name = "env", .fn = &builtin_env },
	{ .name = NULL, .fn = NULL },
};

static int		get_argc(char **cmd)
{
	int i;

	i = 0;
	while (cmd[i])
		i++;
	return (i);
}

int				handle_builtin(t_minishell *mn, t_prog *prog,
					t_fdcls fdin, t_fdcls fdout)
{
	int				i;
	t_builtin_ctx	ctx;
	t_builtin_entry *builtin;

	i = -1;
	builtin = NULL;
	while (g_builtins[++i].name)
		if (!ft_strcmp(g_builtins[i].name, prog->cmd[0]))
			builtin = &g_builtins[i];
	if (!builtin)
		return (0);
	ctx = (t_builtin_ctx) {
		.argv = prog->cmd, .argc = get_argc(prog->cmd), .mn = mn,
		.fdout = fdout, .fdin = fdin
	};
	if (!get_redir(prog, &ctx.fdin, &ctx.fdout))
		return (1);
	*get_last_return_status() = (*builtin->fn)(&ctx);
	if (ctx.fdin.must_close)
		close(ctx.fdin.fd);
	if (ctx.fdout.must_close)
		close(ctx.fdout.fd);
	return (1);
}
