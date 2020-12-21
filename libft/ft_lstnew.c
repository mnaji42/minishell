/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najimehdi <najimehdi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:18:22 by mnaji             #+#    #+#             */
/*   Updated: 2019/10/08 17:32:57 by najimehdi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content)
{
	t_list	*list;

	if (!(list = (t_list*)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!((*list).content = (void*)ft_memalloc(sizeof(content))))
			return (NULL);
		ft_memcpy((*list).content, content, sizeof(content));
	}
	else
		(*list).content = NULL;
	(*list).next = NULL;
	return (list);
}
