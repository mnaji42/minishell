/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:36:24 by mnaji             #+#    #+#             */
/*   Updated: 2018/12/04 21:36:26 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlst_nbr(t_list *lst)
{
	if (lst == NULL)
		ft_putstr("Rien a afficher, la liste est vide.");
	else
	{
		while ((*lst).next != NULL)
		{
			ft_putlink_nbr(lst);
			lst = (*lst).next;
		}
		ft_putlink_nbr(lst);
	}
}
