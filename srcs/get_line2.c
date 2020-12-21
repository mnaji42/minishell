/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <mnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:29:30 by mnaji             #+#    #+#             */
/*   Updated: 2020/01/13 18:51:34 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	get_line_event_27_help(t_line *l, t_get_line *gl)
{
	if (gl->buff_raw == 'B' && gl->li_temp < l->i)
	{
		while (gl->i > 0)
			ft_putstr(gl->i-- > 0 ? "\b \b" : "\b \b");
		if (gl->li_temp == l->i - 1)
		{
			gl->li_temp = l->i;
			ft_bzero(l->line[l->i], ft_strlen(l->line[l->i]));
		}
		else
		{
			gl->li_temp++;
			ft_strdel(&l->line[l->i]);
			l->line[l->i] = ft_strdup(l->line[gl->li_temp]);
			gl->i = ft_strlen(l->line[l->i]);
			ft_putstr(l->line[l->i]);
		}
	}
	else if (gl->buff_raw == 'C' && l->line[l->i][gl->i] != '\0')
		ft_putchar(l->line[l->i][gl->i++]);
	else if (gl->buff_raw == 'D' && gl->i > 0)
		ft_putchar(gl->i-- > 0 ? '\b' : '\b');
}

void		get_line_event_27(t_line *l, t_get_line *gl)
{
	if (gl->buff_raw == 72)
		while (gl->i > 0)
			ft_putchar(gl->i-- > 0 ? '\b' : '\b');
	else if (gl->buff_raw == 70)
		while (gl->i < (int)ft_strlen(l->line[l->i]))
			ft_putchar(l->line[l->i][gl->i++]);
	else if (gl->buff_raw == 'A' && gl->li_temp > 0)
	{
		while (gl->i > 0)
			ft_putstr(gl->i-- > 0 ? "\b \b" : "\b \b");
		gl->li_temp--;
		ft_strdel(&l->line[l->i]);
		l->line[l->i] = ft_strdup(l->line[gl->li_temp]);
		gl->i = ft_strlen(l->line[l->i]);
		ft_putstr(l->line[l->i]);
	}
	get_line_event_27_help(l, gl);
}

static char	*add_char_line(char *line, int i, char buff_raw)
{
	char	*str;
	int		j;

	j = -1;
	if (!(str = (char*)ft_memalloc(sizeof(char) * (ft_strlen(line) + 2))))
		return (NULL);
	while (++j < i)
		str[j] = line[j];
	if (buff_raw == '\0')
	{
		i++;
		j--;
	}
	else
		str[j] = buff_raw;
	while (i < (int)ft_strlen(line) + 1)
		str[++j] = line[i++];
	ft_strdel(&line);
	return (str);
}

int			stock_char(t_line *l, t_get_line *gl)
{
	if (!(l->line[l->i] = add_char_line(l->line[l->i], gl->i, gl->buff_raw)))
		return (0);
	ft_putchar(gl->buff_raw);
	gl->tmp = gl->i - 1;
	while (l->line[l->i][++gl->tmp])
		ft_putchar(l->line[l->i][gl->tmp + 1]);
	while (--gl->tmp > gl->i)
		ft_putchar('\b');
	gl->i++;
	return (1);
}

void		get_line_del(t_line *l, t_get_line *gl)
{
	if (gl->buff_raw == 127 && gl->i > 0)
	{
		l->line[l->i] = add_char_line(l->line[l->i], gl->i - 1, '\0');
		ft_putchar('\b');
		gl->tmp = gl->i - 1;
		while (l->line[l->i][gl->tmp])
			ft_putchar(l->line[l->i][gl->tmp++]);
		ft_putchar(' ');
		while (gl->tmp-- > gl->i - 2)
			ft_putchar('\b');
		gl->i--;
	}
}
