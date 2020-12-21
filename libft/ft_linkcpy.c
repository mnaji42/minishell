/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linkcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najimehdi <najimehdi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 20:37:32 by mnaji             #+#    #+#             */
/*   Updated: 2019/10/08 17:34:45 by najimehdi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_linkcpy(t_list *link)
{
	t_list	*new;

	if (!(new = ft_lstnew(link->content)))
		return (NULL);
	(*new).next = (*link).next;
	return (new);
}
