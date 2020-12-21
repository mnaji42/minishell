/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najimehdi <najimehdi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:31:39 by mnaji             #+#    #+#             */
/*   Updated: 2019/10/08 17:30:30 by najimehdi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstlen(t_list *lst)
{
	int		size;

	if (lst == NULL)
		return (0);
	size = 1;
	while ((*lst).next != NULL)
	{
		size++;
		lst = (*lst).next;
	}
	return (size);
}
