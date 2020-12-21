/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlink.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:42:03 by mnaji             #+#    #+#             */
/*   Updated: 2018/12/04 22:56:36 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printlink(t_list *lst)
{
	if (lst == NULL)
		ft_putstr("Rien a afficher, la liste est vide.");
	else if ((*lst).content_size == 1)
		ft_putlink_char(lst);
	else if ((*lst).content_size == 4)
		ft_putlink_nbr(lst);
	else if ((*lst).content_size == 8)
		ft_putlink_str(lst);
	else
		ft_putstr("Maillon non affichable !\n");
}
