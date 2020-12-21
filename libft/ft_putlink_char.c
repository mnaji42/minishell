/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlink_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:39:45 by mnaji             #+#    #+#             */
/*   Updated: 2018/12/04 21:39:49 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlink_char(t_list *lst)
{
	if (lst == NULL)
		ft_putstr("Rien a afficher, la liste est vide.");
	else
	{
		ft_putstr("(char)     [");
		ft_putchar(*(char*)(*lst).content);
		ft_putstr("]\n");
	}
}
