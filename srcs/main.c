/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <mnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 11:41:16 by mnaji             #+#    #+#             */
/*   Updated: 2020/01/13 19:54:57 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_quote(char *line)
{
	t_quote	q;

	q = (t_quote) {.i = -1};
	while (line[++q.i])
	{
		if (!q.dquote && line[q.i] == '\'')
			q.squote = !q.squote;
		else if (!q.escaped && !q.squote && line[q.i] == '"')
			q.dquote = !q.dquote;
		q.escaped = line[q.i] == '\\' ? !q.escaped : 0;
	}
	if (!q.dquote && !q.squote)
		return (1);
	return (0);
}

static int	mode_raw(int enabled)
{
	static struct termios	cooked;
	static int				raw_enabled = 0;
	struct termios			raw;

	if (raw_enabled == enabled)
		return (0);
	if (enabled)
	{
		tcgetattr(STDIN_FILENO, &cooked);
		raw = cooked;
		cfmakeraw(&raw);
		tcsetattr(STDIN_FILENO, TCSANOW, &raw);
	}
	else
		tcsetattr(STDIN_FILENO, TCSANOW, &cooked);
	raw_enabled = enabled;
	return (1);
}

static void	main_help(t_minishell *mn)
{
	mn->i_l = 0;
	while (mn->line_cut[mn->i_l])
	{
		if (parse_one_group(&mn->grp, mn->line_cut[mn->i_l], \
			ft_strlen(mn->line_cut[mn->i_l])))
			exec_group(mn, mn->grp);
		else
			ft_putendl("Error : parsing");
		free_minishell(mn);
		mn->i_l++;
	}
	free_line_cut(mn->line_cut, 0);
	if (mn->ln.i == 99)
	{
		mn->ln.i = -1;
		mn->ln.full = 1;
	}
	mn->ln.i++;
}

int			main(int ac, char **av, char **env)
{
	t_minishell	mn;

	(void)(ac + av);
	init_signals();
	mn = (t_minishell) { 0 };
	env_load(env);
	mn.ln.line = (char**)ft_memalloc(sizeof(char*) * 100);
	while (1)
	{
		mode_raw(1);
		if (get_line(&mn.ln) == -1)
			return (mode_raw(0));
		mode_raw(0);
		ft_putchar('\n');
		if (!check_quote(mn.ln.line[mn.ln.i]))
		{
			ft_putendl("minishel : Error quote!!");
			continue ;
		}
		if (!(mn.line_cut = split_minishell(mn.ln.line[mn.ln.i], ';')))
			return (free_all(&mn.ln, &mn, "Error : malloc failed !"));
		main_help(&mn);
	}
	return (0);
}
