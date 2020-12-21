/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchudant <cchudant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 22:11:47 by cchudant          #+#    #+#             */
/*   Updated: 2020/01/13 21:25:36 by cchudant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_childlist	*g_children = NULL;

static void			sigint_handler(int s)
{
	t_childlist *child;

	(void)s;
	child = g_children;
	while (child)
	{
		kill(child->pid, SIGINT);
		child = child->next;
	}
}

static void			sigquit_handler(int s)
{
	t_childlist *child;

	(void)s;
	child = g_children;
	while (child)
	{
		kill(child->pid, SIGQUIT);
		child = child->next;
	}
}

void				wait_children(void)
{
	int			status;
	t_childlist	*tmp;

	while (g_children)
	{
		waitpid(g_children->pid, &status, 0);
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			waitpid(g_children->pid, &status, 0);
		if (WTERMSIG(status) == 3)
		{
			ft_putstr("Quit: ");
			ft_putnbr(WTERMSIG(status));
			ft_putstr("\n");
		}
		if (WIFEXITED(status))
			*get_last_return_status() = WEXITSTATUS(status);
		tmp = g_children->next;
		free(g_children);
		g_children = tmp;
	}
}

int					wrap_fork(void)
{
	t_childlist	*el;
	pid_t		pid;

	if ((pid = fork()))
	{
		if (!(el = malloc(sizeof(t_childlist))))
			return (-1);
		el->next = g_children;
		el->pid = pid;
		g_children = el;
	}
	return (pid);
}

void				init_signals(void)
{
	signal(SIGINT, &sigint_handler);
	signal(SIGQUIT, &sigquit_handler);
}
