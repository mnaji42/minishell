/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najimehdi <najimehdi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:35:59 by mnaji             #+#    #+#             */
/*   Updated: 2019/10/08 17:31:34 by najimehdi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdel_all(t_list *lst)
{
	lst = ft_lstdel_nfirst(lst, ft_lstlen(lst));
	return (lst);
}
