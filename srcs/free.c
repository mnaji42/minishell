/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchudant <cchudant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:13:34 by mnaji             #+#    #+#             */
/*   Updated: 2020/01/13 18:57:49 by cchudant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			free_processus(t_processus *prc, int step, int ret)
{
	int i;

	ft_strdel(&prc->prc);
	i = -1;
	while (prc->prc_cut && prc->prc_cut[++i])
		ft_strdel(&prc->prc_cut[i]);
	free(prc->prc_cut);
	prc->prc_cut = NULL;
	i = -1;
	if (prc->nb_prog > 0)
		while (++i < prc->nb_prog)
			free_programme(&prc->prog[i], 0);
	if (step > 0)
	{
		free(prc->prog);
		prc->prog = NULL;
	}
	free(prc);
	return (ret);
}

void		free_group(t_group *grp)
{
	if (!grp)
		return ;
	if (grp->type == GRP_PROC)
		free_processus(grp->proc, 1, 0);
	else if (grp->type == GRP_AND)
	{
		free_group(grp->left);
		free_group(grp->right);
	}
	else if (grp->type == GRP_OR)
	{
		free_group(grp->left);
		free_group(grp->right);
	}
	else if (grp->type == GRP_PAR)
		free_group(grp->left);
	free(grp);
}

void		free_minishell(t_minishell *mn)
{
	free_group(mn->grp);
	mn->grp = NULL;
}

int			free_all(t_line *l, t_minishell *mn, char *error)
{
	int		ret;

	ret = 0;
	if (error)
	{
		ft_putendl(error);
		ret = 1;
	}
	return_free_line(l->line, l->i, l->full, NULL);
	free_minishell(mn);
	free_line_cut(mn->line_cut, 0);
	return (ret);
}
