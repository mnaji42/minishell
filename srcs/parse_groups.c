/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_groups.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <mnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 05:20:38 by cchudant          #+#    #+#             */
/*   Updated: 2020/01/07 00:41:19 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	grp_proc(t_group **dst, char *str, int len)
{
	if (len < 1 || !(*dst = malloc(sizeof(t_group))))
		return (0);
	**dst = (t_group) { .type = GRP_PROC };
	if (!((*dst)->proc = malloc(sizeof(t_processus))))
		return (0);
	*(*dst)->proc = (t_processus) { .prc = ft_strndup(str, len) };
	if (!(*dst)->proc->prc)
		return (0);
	return (parse_processus((*dst)->proc));
}

static int	grp_and(t_group **dst, char *str, int delim, int len)
{
	if (len < 4 || !(*dst = malloc(sizeof(t_group))))
		return (0);
	**dst = (t_group) { .type = GRP_AND };
	if (!parse_one_group(&(*dst)->left, str, delim))
		return (0);
	if (!parse_one_group(&(*dst)->right, str + delim + 2, len - delim - 2))
		return (0);
	return (1);
}

static int	grp_or(t_group **dst, char *str, int delim, int len)
{
	if (len < 4 || !(*dst = malloc(sizeof(t_group))))
		return (0);
	**dst = (t_group) { .type = GRP_OR };
	if (!parse_one_group(&(*dst)->left, str, delim))
		return (0);
	if (!parse_one_group(&(*dst)->right, str + delim + 2, len - delim - 2))
		return (0);
	return (1);
}

static int	grp_par(t_group **dst, char *str, int len)
{
	if (len < 2 || !(*dst = malloc(sizeof(t_group))))
		return (0);
	**dst = (t_group) { .type = GRP_PAR };
	if (!parse_one_group(&(*dst)->left, str + 1, len - 2))
		return (0);
	return (1);
}

int			parse_one_group(t_group **dst, char *str, int len)
{
	int		par_count;
	t_quote	q;

	grp_trim(&str, &len);
	q = (t_quote) {.i = -1};
	par_count = 0;
	while (++q.i < len)
	{
		parse_one_group_nrm(&q, str, &par_count);
		if (!q.escaped && !q.squote && !q.dquote && \
			!par_count && str[q.i] == '&')
			return (str[q.i + 1] == '&' ? grp_and(dst, str, q.i, len) : 0);
		else if (!q.escaped && !q.squote && !q.dquote \
			&& !par_count && str[q.i] == '|' && str[q.i + 1] == '|')
			return (grp_or(dst, str, q.i, len));
		q.escaped = str[q.i] == '\\' ? !q.escaped : 0;
		if (par_count < 0)
			return (0);
	}
	if (str[0] == '(' && str[len - 1] == ')')
		return (grp_par(dst, str, len));
	return (grp_proc(dst, str, len));
}
