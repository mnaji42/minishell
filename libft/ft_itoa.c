/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:07:15 by mnaji             #+#    #+#             */
/*   Updated: 2018/12/05 00:07:10 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n)
{
	int		size;

	size = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	else
	{
		if (n < 0)
		{
			size++;
			n = -n;
		}
		while (n != 0)
		{
			n = n / 10;
			size++;
		}
		return (size);
	}
}

static int	ft_particular(char *str, int n)
{
	if (n == 0)
		str[0] = '0';
	else if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		return (147483648);
	}
	else if (n < 0)
	{
		str[0] = '-';
		return (-n);
	}
	return (n);
}

char		*ft_itoa(int n)
{
	int		size;
	char	*str;

	size = ft_size(n);
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	n = ft_particular(str, n);
	while (n > 0)
	{
		size--;
		str[size] = (char)(n % 10 + 48);
		n = n / 10;
	}
	return (str);
}
