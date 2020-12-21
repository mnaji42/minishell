/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblist_addlast.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 22:03:41 by mnaji             #+#    #+#             */
/*   Updated: 2019/01/30 23:38:41 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dblist	*add_link_to_listlast(t_dblist *dlst, t_dblink *dlnk)
{
	if (ft_dblist_isempty(dlst))
	{
		if (!(dlst = (t_dblist*)ft_memalloc(sizeof(t_dblist))))
			return (NULL);
		dlst->len = 0;
		dlst->first = dlnk;
		dlst->last = dlnk;
	}
	else
	{
		dlst->last->next = dlnk;
		dlnk->back = dlst->last;
		dlst->last = dlnk;
	}
	return (dlst);
}

t_dblist	*ft_dblist_addlast(t_dblist *dlst, char *str, int nb)
{
	t_dblink	*dlnk;
	int			strlen;

	if (!(dlnk = (t_dblink*)ft_memalloc(sizeof(t_dblink))))
		return (NULL);
	if (str != NULL)
	{
		strlen = ft_strlen(str);
		if (!(dlnk->str = (char*)ft_memalloc(sizeof(char) * strlen + 1)))
			return (NULL);
		ft_memcpy(dlnk->str, str, strlen + 1);
	}
	else
		dlnk->str = NULL;
	dlnk->nb = nb;
	dlnk->next = NULL;
	dlnk->back = NULL;
	dlst = add_link_to_listlast(dlst, dlnk);
	dlst->len++;
	return (dlst);
}
