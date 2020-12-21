/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strappend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchudant <cchudant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 01:32:48 by cchudant          #+#    #+#             */
/*   Updated: 2020/01/13 14:53:33 by cchudant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strnlen(char const *s, size_t len)
{
	size_t i;

	i = 0;
	while (i < len && s[i])
		i++;
	return (i);
}

int		ft_strnappend(char **dst, char const *str, size_t len)
{
	char	*ret;
	size_t	dstlen;

	if (*dst == NULL)
		return (0);
	dstlen = ft_strlen(*dst);
	len = ft_strnlen(str, len);
	if (!(ret = malloc(sizeof(char) * (dstlen + len + 1))))
	{
		free(*dst);
		*dst = NULL;
		return (0);
	}
	ft_memcpy(ret, *dst, dstlen);
	ft_memcpy(&ret[dstlen], str, len);
	ret[dstlen + len] = '\0';
	free(*dst);
	*dst = ret;
	return (1);
}

int		ft_strappend(char **dst, char const *str)
{
	char	*ret;
	size_t	dstlen;
	size_t	strlen;

	if (*dst == NULL)
		return (0);
	dstlen = ft_strlen(*dst);
	strlen = ft_strlen(str);
	if (!(ret = malloc(sizeof(char) * (dstlen + strlen + 1))))
	{
		free(*dst);
		*dst = NULL;
		return (0);
	}
	ft_memcpy(ret, *dst, dstlen);
	ft_memcpy(&ret[dstlen], str, strlen);
	ret[dstlen + strlen] = '\0';
	free(*dst);
	*dst = ret;
	return (1);
}

int		ft_strappend_char(char **dst, char c)
{
	char	*ret;
	size_t	dstlen;

	if (*dst == NULL)
		return (0);
	dstlen = ft_strlen(*dst);
	if (!(ret = malloc(sizeof(char) * (dstlen + 2))))
	{
		free(*dst);
		*dst = NULL;
		return (0);
	}
	ft_memcpy(ret, *dst, dstlen);
	ret[dstlen] = c;
	ret[dstlen + 1] = '\0';
	free(*dst);
	*dst = ret;
	return (1);
}

int		ft_strappend_nbr(char **dst, int i)
{
	char	*str;
	int		ret;

	if (!(str = ft_itoa(i)))
	{
		free(*dst);
		*dst = NULL;
		return (0);
	}
	ret = ft_strappend(dst, str);
	free(str);
	return (ret);
}
