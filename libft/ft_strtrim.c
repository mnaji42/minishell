/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najimehdi <najimehdi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 21:26:03 by mnaji             #+#    #+#             */
/*   Updated: 2019/10/08 15:35:50 by najimehdi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*str;

	start = 0;
	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	i = 0;
	while (ft_strchr(set, s1[i]))
		i++;
	if (s1[i] == '\0')
		return ("");
	start = i;
	i = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[i]))
		i--;
	end = i;
	if (!(str = (char*)malloc(sizeof(char) * (end - start + 2))))
		return (NULL);
	str = ft_strncpy(str, (char*)s1 + start, end - start + 1);
	str[end - start + 1] = '\0';
	return (str);
}
