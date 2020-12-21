/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_processus_help.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <mnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 01:40:55 by mnaji             #+#    #+#             */
/*   Updated: 2020/01/10 15:51:17 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		malloc_prog_file(t_prog *prog, char *line)
{
	t_quote	q;

	q = (t_quote) {.i = -1, .squote = -1, .dquote = -1};
	while (line[++q.i])
	{
		if (line[q.i] == '"' && q.squote == -1 && !q.escaped)
			q.dquote *= -1;
		else if (line[q.i] == '\'' && q.dquote == -1)
			q.squote *= -1;
		else if (line[q.i] == '>' && line[q.i + 1] == '>' && \
			q.dquote == -1 && q.squote == -1)
		{
			prog->nb_redir++;
			q.i++;
		}
		else if (line[q.i] == '>' && q.dquote == -1 && q.squote == -1)
			prog->nb_redir++;
		else if (line[q.i] == '<' && q.dquote == -1 && q.squote == -1)
			prog->nb_redir++;
		q.escaped = line[q.i] == '\\' ? !q.escaped : 0;
	}
	return ((prog->redir = ft_memalloc(sizeof(t_redir) \
		* prog->nb_redir)) != NULL);
}

int		get_value_prog(t_prog *prog, char **arg_tmp, t_nrm_parse_prog n)
{
	while (arg_tmp[++n.i])
	{
		if (arg_tmp[n.i][0] == '>' && arg_tmp[n.i][1] == '>')
		{
			if (!(prog->redir[n.redir++] = (t_redir) \
				{ REDIR_APP, ft_strdup(arg_tmp[++n.i]) }).file)
				return (0);
		}
		else if (arg_tmp[n.i][0] == '>')
		{
			if (!(prog->redir[n.redir++] = (t_redir) \
				{ REDIR_OUT, ft_strdup(arg_tmp[++n.i]) }).file)
				return (0);
		}
		else if (arg_tmp[n.i][0] == '<')
		{
			if (!(prog->redir[n.redir++] = (t_redir) \
				{ REDIR_IN, ft_strdup(arg_tmp[++n.i]) }).file)
				return (0);
		}
		else if (!(prog->cmd[n.cmd++] = ft_strdup(arg_tmp[n.i])))
			return (0);
	}
	return (1);
}

int		malloc_prog_cmd(t_prog *prog, char **arg_tmp)
{
	int		count;
	int		i;

	count = 0;
	i = -1;
	while (arg_tmp[++i])
	{
		if (arg_tmp[i][0] != '<' && arg_tmp[i][0] != '>')
			count++;
	}
	if (!(prog->cmd = (char**)ft_memalloc(sizeof(char*) * (count + 1))))
		return (0);
	return (1);
}

void	append_env_var(char **ret, int *i, char *arg)
{
	int		j;
	char	*str;

	(*i)++;
	if (arg[*i] == '?')
	{
		ft_strappend_nbr(ret, *get_last_return_status());
		return ;
	}
	j = 0;
	while (ft_isalnum(arg[*i + j]) || arg[*i + j] == '_')
		j++;
	str = env_nget(&arg[*i], j);
	if (!str)
		str = "";
	ft_strappend(ret, str);
	(*i) += j - 1;
}

char	*handle_arg(char *arg)
{
	char	*ret;
	int		i;
	int		dqu;
	int		squ;
	int		esc;

	i = -1;
	esc = 0;
	dqu = 0;
	squ = 0;
	ret = ft_strdup("");
	while (ret && arg[++i])
	{
		if (!squ && !esc && arg[i] == '"')
			dqu = !dqu;
		else if (!dqu && !esc && arg[i] == '\'')
			squ = !squ;
		else if (!squ && !esc && arg[i] == '$' && (arg[i + 1] == '?' \
			|| ft_isalnum(arg[i + 1]) || arg[i + 1] == '_'))
			append_env_var(&ret, &i, arg);
		else if (!(!squ && !esc && arg[i] == '\\'))
			ft_strappend_char(&ret, arg[i]);
		esc = !squ && arg[i] == '\\' ? !esc : 0;
	}
	return (ret);
}
