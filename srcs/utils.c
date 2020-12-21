/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchudant <cchudant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 12:11:01 by mnaji             #+#    #+#             */
/*   Updated: 2020/01/13 18:09:45 by cchudant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_u(int fd)
{
	if (fd >= 0)
		close(fd);
}

int		return_error(char *error, int ret)
{
	ft_putstr(error);
	return (ret);
}
