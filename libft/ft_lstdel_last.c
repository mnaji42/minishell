/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najimehdi <najimehdi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:32:42 by mnaji             #+#    #+#             */
/*   Updated: 2019/10/08 17:31:14 by najimehdi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdel_last(t_list *lst)
{
	t_list	*first;
	t_list	*before;

	first = lst;
	if (lst == NULL)
		return (NULL);
	if ((*lst).next == NULL)
		return (ft_lstdel_first(lst));
	while ((*lst).next != NULL)
	{
		before = lst;
		lst = (*lst).next;
	}
	(*before).next = NULL;
	ft_lstdel_first(lst);
	return (first);
}
