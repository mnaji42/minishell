/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishexa_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najimehdi <najimehdi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 11:34:09 by mnaji             #+#    #+#             */
/*   Updated: 2019/05/07 13:18:49 by najimehdi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ishexa_int(char *str)
{
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	if (str[i++] != '0')
		return (0);
	if (str[i] != 'x' && str[i] != 'X')
		return (0);
	i++;
	while (str[i] == '0')
		i++;
	while (str[i] != '\0')
	{
		if (i2 == 6 || ((ft_isdigit(str[i]) == 0 && (str[i] < 'A' || \
			str[i] > 'F') && (str[i] < 'a' || str[i] > 'f'))))
			return (0);
		i++;
		i2++;
	}
	return (1);
}
