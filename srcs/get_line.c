/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <mnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 21:19:52 by mnaji             #+#    #+#             */
/*   Updated: 2020/01/13 19:41:13 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_get_line(t_line *l, t_get_line *gl)
{
	if (l->line[l->i])
		ft_strdel(&l->line[l->i]);
	ft_putstr("?> ");
	if (!(l->line[l->i] = (char*)ft_memalloc(sizeof(char) * 1)))
		gl->loop = -1;
	gl->li_temp = l->i;
	gl->i = 0;
}

static int	get_line_break(t_line *l, t_get_line *gl)
{
	if (gl->buff_raw == '\r')
		return (1);
	else if (gl->buff_raw == 4 && l->line[l->i][0] == '\0')
	{
		l->line[l->i] = ft_strdup_free(l->line[l->i], "exit");
		return (1);
	}
	return (0);
}

static void	goto_word(t_line *l, t_get_line *gl)
{
	if (gl->buff_raw == 5)
	{
		while (gl->i < (int)ft_strlen(l->line[l->i]) && \
			l->line[l->i][gl->i] == ' ')
			ft_putchar(l->line[l->i][gl->i++]);
		while (gl->i < (int)ft_strlen(l->line[l->i]) && \
			l->line[l->i][gl->i] != ' ')
			ft_putchar(l->line[l->i][gl->i++]);
	}
	else if (gl->buff_raw == 1)
	{
		if (gl->i > 0)
			ft_putchar(gl->i-- > 0 ? '\b' : '\b');
		while (gl->i > 0 && l->line[l->i][gl->i] == ' ')
			ft_putchar(gl->i-- > 0 ? '\b' : '\b');
		while (gl->i > 0 && l->line[l->i][gl->i] != ' ')
			ft_putchar(gl->i-- > 0 ? '\b' : '\b');
		if (gl->i > 0)
			ft_putchar(l->line[l->i][gl->i++]);
	}
}

static int	get_line_cmd_c(t_line *l, t_get_line *gl)
{
	while (gl->i-- > 0)
		ft_putchar('\b');
	ft_strdel(&l->line[l->i]);
	ft_putstr("\b\b\b\n");
	get_line(l);
	return (1);
}

int			get_line(t_line *l)
{
	t_get_line	gl;

	init_get_line(l, &gl);
	while (1)
	{
		if ((read(0, &gl.buff_raw, 1) < 1))
			return (-1);
		if (get_line_break(l, &gl) == 1)
			break ;
		else if (gl.buff_raw == 5 || gl.buff_raw == 1)
			goto_word(l, &gl);
		else if (gl.buff_raw == 3)
			return (get_line_cmd_c(l, &gl));
		else if (gl.buff_raw > 31 && gl.buff_raw != 127)
			stock_char(l, &gl);
		else if (gl.buff_raw == 27)
		{
			if ((read(0, &gl.buff_raw, 1) < 1) || (read(0, \
				&gl.buff_raw, 1) < 1))
				return (-1);
			get_line_event_27(l, &gl);
		}
		get_line_del(l, &gl);
	}
	return (1);
}
