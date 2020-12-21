/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_powerof.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:18:52 by mnaji             #+#    #+#             */
/*   Updated: 2018/11/17 21:42:42 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_powerof(int nb, int power)
{
	int		result;

	result = 1;
	if (power == 0)
		return (1);
	while (power > 0)
	{
		result = result * nb;
		power--;
	}
	return (result);
}
