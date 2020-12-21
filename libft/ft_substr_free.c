/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najimehdi <najimehdi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 19:34:00 by mnaji             #+#    #+#             */
/*   Updated: 2019/10/07 17:14:07 by najimehdi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr_free(char *s, int start, size_t len)
{
	char	*str;

	if (!(str = ft_substr(s, start, len)))
		return (NULL);
	ft_strdel(&s);
	return (str);
}
