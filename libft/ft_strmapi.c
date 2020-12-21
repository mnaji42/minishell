/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najimehdi <najimehdi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:00:47 by mnaji             #+#    #+#             */
/*   Updated: 2019/10/08 15:17:58 by najimehdi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char *s, void (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	if (!(str = strdup(s)) || !s || !f)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		f(i, str[i]);
		i++;
	}
	return (str);
}
