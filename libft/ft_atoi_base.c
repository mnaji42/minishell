/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najimehdi <najimehdi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 22:37:19 by mnaji             #+#    #+#             */
/*   Updated: 2019/10/13 16:17:38 by najimehdi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi_base(const char *nptr, int base)
{
	int		i;
	int		negativ;
	int		res;

	i = 0;
	res = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
			|| nptr[i] == '\r' || nptr[i] == '\v' || nptr[i] == '\f')
		i++;
	negativ = (nptr[i] == '-') ? -1 : 1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while ((nptr[i] <= '9' && nptr[i] >= '0') || \
	(nptr[i] <= 'f' && nptr[i] >= 'a') || (nptr[i] <= 'F' && nptr[i] >= 'A'))
	{
		if (nptr[i] <= '9' && nptr[i] >= '0')
			res = res * base + nptr[i] - '0';
		else if (nptr[i] <= 'f' && nptr[i] >= 'a')
			res = res * base + nptr[i] - 'a' + 10;
		else if (nptr[i] <= 'F' && nptr[i] >= 'A')
			res = res * base + nptr[i] - 'A' + 10;
		i++;
	}
	return (res * negativ);
}
