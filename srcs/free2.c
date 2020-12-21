/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchudant <cchudant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:52:54 by cchudant          #+#    #+#             */
/*   Updated: 2020/01/13 18:39:49 by cchudant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			free_line_cut(char **line_cut, int ret)
{
	int		i;

	i = 0;
	while (line_cut[i])
	{
		ft_strdel(&line_cut[i]);
		i++;
	}
	free(line_cut);
	line_cut = NULL;
	return (ret);
}

int			return_free_line(char **line, int i, int full, char *error)
{
	int		end;

	end = i;
	while (i >= 0)
		ft_strdel(&line[i--]);
	if (full == 1)
	{
		i = 99;
		while (i > end)
			ft_strdel(&line[i--]);
	}
	free(line);
	line = NULL;
	if (error)
		ft_putstr(error);
	return (0);
}

int			free_programme(t_prog *prog, int ret)
{
	int		i;

	if (!prog)
		return (ret);
	i = -1;
	while (++i < prog->nb_redir)
		ft_strdel(&prog->redir[i].file);
	i = -1;
	while (prog->cmd && prog->cmd[++i])
		ft_strdel(&prog->cmd[i]);
	if (prog->cmd)
		free(prog->cmd);
	free(prog->redir);
	return (ret);
}
