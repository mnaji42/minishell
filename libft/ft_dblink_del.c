/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblink_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 00:16:36 by mnaji             #+#    #+#             */
/*   Updated: 2019/02/11 00:16:40 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dblink	*ft_dblink_del(t_dblink *dlnk, t_dblist *dlst)
{
	if (dlst->first == dlnk)
		dlst = ft_dblist_delfirst(dlst);
	else if (dlst->last == dlnk)
		dlst = ft_dblist_dellast(dlst);
	else
	{
		dlnk->next->back = dlnk->back;
		dlnk->back->next = dlnk->next;
	}
	return (ft_dblink_free(dlnk));
}
