/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:40:53 by mnaji             #+#    #+#             */
/*   Updated: 2018/12/04 21:40:55 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printlst(t_list *lst)
{
	if (lst == NULL)
		ft_putstr("Rien a afficher, la liste est vide.");
	else
	{
		while ((*lst).next != NULL)
		{
			ft_printlink(lst);
			lst = (*lst).next;
		}
		ft_printlink(lst);
	}
}
