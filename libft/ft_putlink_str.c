/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlink_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:38:32 by mnaji             #+#    #+#             */
/*   Updated: 2018/12/04 21:42:57 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlink_str(t_list *lst)
{
	if (lst == NULL)
		ft_putstr("Rien a afficher, la liste est vide");
	else
	{
		ft_putstr("(char*)    [");
		ft_putstr(*(char**)((*lst).content));
		ft_putstr("]\n");
	}
}
