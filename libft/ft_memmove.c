/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 07:58:27 by mnaji             #+#    #+#             */
/*   Updated: 2018/12/04 20:53:56 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int					i;
	unsigned char		*str;
	const unsigned char	*str2;

	str = (unsigned char*)dest;
	str2 = (unsigned char*)src;
	i = 0;
	if (dest <= src)
		ft_memcpy(dest, src, n);
	else
	{
		str = dest + n - 1;
		str2 = src + n - 1;
		while (n--)
		{
			str[i] = str2[i];
			i--;
		}
	}
	return (dest);
}
