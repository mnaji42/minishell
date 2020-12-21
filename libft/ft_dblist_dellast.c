/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblist_dellast.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:26:58 by mnaji             #+#    #+#             */
/*   Updated: 2019/02/01 17:27:58 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dblist	*dlst_isemptylast(t_dblist *dlst)
{
	ft_putstr("rien a supprimer la liste est deja vide !\n");
	return (dlst);
}

t_dblist	*ft_dblist_dellast(t_dblist *dlst)
{
	t_dblink	*temp;

	if (ft_dblist_isempty(dlst))
		return (dlst_isemptylast(dlst));
	temp = dlst->last;
	if (dlst->first == dlst->last)
	{
		temp = ft_dblink_free(temp);
		free(dlst);
		dlst = NULL;
		return (dlst);
	}
	dlst->last = dlst->last->back;
	dlst->last->next = NULL;
	temp->next = NULL;
	temp->back = NULL;
	temp = ft_dblink_free(temp);
	dlst->len--;
	return (dlst);
}
