/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <mnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:48:07 by mnaji             #+#    #+#             */
/*   Updated: 2019/12/11 11:52:26 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_eol(char *s, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int	pop_line(t_stock *stock, char **line)
{
	int i;
	int j;
	int	eol;

	if ((eol = is_eol(stock->s, stock->len)) != -1)
	{
		if (!(*line = malloc(eol + 1)))
			return (-1);
		i = -1;
		while (++i < eol)
			(*line)[i] = stock->s[i];
		(*line)[i++] = '\0';
		j = 0;
		while (stock->s[i] && i < stock->len)
			stock->s[j++] = stock->s[i++];
		stock->len = j;
		return (1);
	}
	return (0);
}

static int	cpy(char *line, char *buff, int i, int size)
{
	int i2;

	i2 = 0;
	while (i2 < size)
	{
		line[i + i2] = buff[i2];
		i2++;
	}
	return (i2);
}

static int	read_line(char **line, t_stock *stock, int i_line, int i_read)
{
	char	buffer[BUFFER_SIZE];
	int		ret;
	int		i;
	int		eol;
	int		ret2;

	if ((ret = read(stock->fd, buffer, BUFFER_SIZE)) == -1)
		return (-1);
	if ((eol = is_eol(buffer, ret)) != -1 || ret != BUFFER_SIZE)
	{
		if (!(*line = malloc(i_read * BUFFER_SIZE + \
				(eol == -1 ? ret : eol) + stock->len + 1)))
			return (-1);
		cpy(*line, stock->s, 0, stock->len);
		i = cpy(*line, buffer, i_read * BUFFER_SIZE + stock->len, \
				(eol == -1 ? ret : eol));
		(*line)[i_read * BUFFER_SIZE + stock->len + i++] = '\0';
		stock->len = cpy(stock->s, &buffer[i], 0, ret - i);
		return (eol != -1 ? 1 : 0);
	}
	if ((ret2 = read_line(line, stock, i_line, i_read + 1)) == -1)
		return (-1);
	cpy(*line, buffer, i_read * BUFFER_SIZE + stock->old_len, ret);
	return (ret2);
}

int			get_next_line(int fd, char **line)
{
	static t_stock	stock;
	int				ret;

	if ((fd < 0 || fd > OPEN_MAX) || !line || BUFFER_SIZE < 1 || \
			read(fd, NULL, 0) == -1)
		return (-1);
	if ((ret = pop_line(&stock, line)) != 0)
		return (ret);
	stock.fd = fd;
	stock.old_len = stock.len;
	if ((ret = read_line(line, &stock, 0, 0)) == -1)
		return (-1);
	return (ret);
}
