/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:39:10 by mnaji             #+#    #+#             */
/*   Updated: 2018/12/04 21:39:12 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlst_char(t_list *lst)
{
	if (lst == NULL)
		ft_putstr("Rien a afficher la liste est vide");
	else
	{
		while ((*lst).next != NULL)
		{
			ft_putlink_char(lst);
			lst = (*lst).next;
		}
		ft_putlink_char(lst);
	}
}
