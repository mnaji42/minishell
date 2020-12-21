/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblist_delfirst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 19:50:18 by mnaji             #+#    #+#             */
/*   Updated: 2019/02/05 19:50:22 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dblist	*dlst_isemptyfirst(t_dblist *dlst)
{
	ft_putstr("rien a supprimer la liste est deja vide !\n");
	return (dlst);
}

t_dblist	*ft_dblist_delfirst(t_dblist *dlst)
{
	t_dblink	*temp;

	if (ft_dblist_isempty(dlst))
		return (dlst_isemptyfirst(dlst));
	temp = dlst->first;
	if (dlst->first == dlst->last)
	{
		temp = ft_dblink_free(temp);
		free(dlst);
		dlst = NULL;
		return (dlst);
	}
	dlst->first = dlst->first->next;
	dlst->first->back = NULL;
	temp->back = NULL;
	temp->next = NULL;
	temp = ft_dblink_free(temp);
	dlst->len--;
	return (dlst);
}
