/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblist_delall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 23:54:21 by mnaji             #+#    #+#             */
/*   Updated: 2019/02/05 23:54:24 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dblist	*ft_dblist_delall(t_dblist *dlst)
{
	int		i;

	if (ft_dblist_isempty(dlst))
		return (NULL);
	i = dlst->len;
	while (i > 0)
	{
		ft_dblist_dellast(dlst);
		i--;
	}
	return (NULL);
}
