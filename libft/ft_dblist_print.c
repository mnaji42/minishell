/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblist_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 21:14:02 by mnaji             #+#    #+#             */
/*   Updated: 2019/02/05 21:14:05 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dblist_print(t_dblist *dlst)
{
	t_dblink	*temp;

	if (ft_dblist_isempty(dlst))
	{
		ft_putstr("Rien a affciher, la liste est vide !\n");
		return ;
	}
	temp = dlst->first;
	while (temp != NULL)
	{
		if (temp->str != NULL)
		{
			ft_putstr(" \" ");
			ft_putstr(temp->str);
			ft_putstr(" \" ");
		}
		ft_putstr("[ ");
		ft_putnbr(temp->nb);
		ft_putstr(" ] ");
		ft_putnligne(1);
		temp = temp->next;
	}
}
