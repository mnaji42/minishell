/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlink_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:37:52 by mnaji             #+#    #+#             */
/*   Updated: 2018/12/04 21:37:54 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlink_nbr(t_list *lst)
{
	if (lst == NULL)
		ft_putstr("Rien a afficher, la liste est vide");
	else
	{
		ft_putstr("(int)      [");
		ft_putnbr(*(int*)((*lst).content));
		ft_putstr("]\n");
	}
}
