/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchudant <cchudant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 09:39:36 by mnaji             #+#    #+#             */
/*   Updated: 2020/01/07 13:00:21 by cchudant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_group	*add_new_group(t_group *grp, char *pos)
{
	t_group	*grp_next;

	grp_next = (t_group*)ft_memalloc(sizeof(t_group));
	if (ft_strcmp("left", pos) == 0)
		grp->left = grp_next;
	else if (ft_strcmp("right", pos) == 0)
		grp->right = grp_next;
	return (grp_next);
}

void	grp_trim(char **str, int *len)
{
	while (*len && **str == ' ')
	{
		(*str)++;
		(*len)--;
	}
	while (*len && (*str)[*len - 1] == ' ')
		(*len)--;
}

void	parse_one_group_nrm(t_quote *q, char *str, int *par_count)
{
	if (!q->dquote && str[q->i] == '\'')
		q->squote = !q->squote;
	else if (!q->escaped && !q->squote && str[q->i] == '"')
		q->dquote = !q->dquote;
	else if (!q->escaped && !q->dquote && !q->squote && str[q->i] == '(')
		(*par_count)++;
	else if (!q->escaped && !q->dquote && !q->squote && str[q->i] == ')')
		(*par_count)--;
}

char	*ft_strndup(char *str, int len)
{
	int		i;
	char	*res;

	i = 0;
	while (i < len && str[i])
		i++;
	if (!(res = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (i < len && str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
