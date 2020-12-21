/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_processus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchudant <cchudant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 17:43:37 by mnaji             #+#    #+#             */
/*   Updated: 2020/01/13 18:55:13 by cchudant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*add_space_around(char *line, int i, int nb_char, t_nrm_sp_around n)
{
	if (!(n.left = ft_memalloc(sizeof(char) * (i + 3 + nb_char))))
		return (NULL);
	while (++n.j < i)
		n.left[n.j] = line[n.j];
	n.left[n.j++] = ' ';
	n.left[n.j++] = line[i];
	if (nb_char == 2)
		n.left[n.j++] = line[i + 1];
	n.left[n.j++] = ' ';
	if (!(n.right = ft_strdup(&line[i + nb_char])))
	{
		ft_strdel(&n.left);
		return (NULL);
	}
	if (!(line = ft_strjoin_free(line, n.left, n.right)))
	{
		ft_strdel(&n.left);
		ft_strdel(&n.right);
		return (NULL);
	}
	ft_strdel(&n.left);
	ft_strdel(&n.right);
	return (line);
}

static char	*add_space_prog(char *line)
{
	t_quote	q;

	q = (t_quote) {.i = -1, .squote = -1, .dquote = -1};
	while (line[++q.i])
	{
		if (line[q.i] == '"' && q.squote == -1 && !q.escaped)
			q.dquote *= -1;
		else if (line[q.i] == '\'' && q.dquote == -1)
			q.squote *= -1;
		else if (q.i != 0 && q.dquote == -1 && q.squote == -1 \
			&& line[q.i] == '>' && line[q.i + 1] == '>')
		{
			if (!(line = add_space_around(line, q.i, 2, \
				(t_nrm_sp_around) {0, 0, -1})))
				return (NULL);
			q.i += 2;
		}
		else if (q.i != 0 && q.dquote == -1 && q.squote == -1 \
			&& (line[q.i] == '<' || line[q.i] == '>'))
			if (!(line = add_space_around(line, q.i++, 1, \
				(t_nrm_sp_around) {0, 0, -1})))
				return (NULL);
		q.escaped = line[q.i] == '\\' ? !q.escaped : 0;
	}
	return (line);
}

static int	cut_quote_args(t_prog *prog)
{
	int		i;
	char	*str;

	i = -1;
	while (prog->cmd[++i])
	{
		str = handle_arg(prog->cmd[i]);
		free(prog->cmd[i]);
		if (!(prog->cmd[i] = str))
			return (0);
	}
	return (1);
}

static int	parse_programme(t_prog *prog, char **line)
{
	char	**arg_tmp;

	if (!(*line = add_space_prog(*line)))
		return (0);
	if (!(malloc_prog_file(prog, *line)))
		return (0);
	if (!(arg_tmp = split_minishell(*line, ' ')))
		return (0);
	if (!*arg_tmp || !(malloc_prog_cmd(prog, arg_tmp)))
	{
		free_line_cut(arg_tmp, 0);
		return (0);
	}
	if (!(get_value_prog(prog, arg_tmp, (t_nrm_parse_prog) {-1, 0, 0})))
	{
		free_line_cut(arg_tmp, 0);
		return (0);
	}
	free_line_cut(arg_tmp, 0);
	if (!(cut_quote_args(prog)))
		return (0);
	return (1);
}

int			parse_processus(t_processus *prc)
{
	int i;

	prc->nb_prog = 0;
	if (prc->prc[ft_strlen(prc->prc) - 1] == '|' ||
			prc->prc[0] == '|' ||
			!(prc->prc_cut = split_minishell(prc->prc, '|')))
		return (0);
	while (prc->prc_cut[prc->nb_prog])
		prc->nb_prog++;
	if (!(prc->prog = (t_prog*)ft_memalloc(sizeof(t_prog) * prc->nb_prog)))
		return (free_processus(prc, 0, 0));
	i = -1;
	while (++i < prc->nb_prog)
		if (!(parse_programme(&prc->prog[i], &prc->prc_cut[i])))
			return (0);
	return (1);
}
