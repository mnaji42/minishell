/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najimehdi <najimehdi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 22:18:13 by mnaji             #+#    #+#             */
/*   Updated: 2019/10/07 16:33:24 by najimehdi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *s, char c)
{
	int		i;
	int		count_word;

	i = 0;
	count_word = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
		{
			i++;
			if (s[i] == '\0')
				return (count_word);
		}
		while (s[i] != c)
		{
			if (s[i] == '\0')
				return (count_word + 1);
			i++;
		}
		count_word++;
	}
	return (count_word);
}

static int	ft_size_word(char *str, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] != c && str[i] != '\0')
	{
		count++;
		i++;
	}
	return (count);
}

static int	ft_cpy_ligne(char *tab, char *s, int i, char c)
{
	int		t;

	t = 0;
	while (s[i] != c && s[i] != 0)
	{
		tab[t] = s[i];
		i++;
		t++;
	}
	tab[t] = '\0';
	return (i);
}

static char	**ft_return_tab(char *s, char **tab, int ligne, char c)
{
	if (*s - 1 != c)
		tab[ligne] = 0;
	else
		tab[ligne - 1] = 0;
	return (tab);
}

char		**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		ligne;

	if (!s || !c || !(tab = (char**)malloc(sizeof(char*) *\
					(ft_count_word(s, c) + 1))))
		return (NULL);
	ligne = 0;
	i = 0;
	while (ligne < ft_count_word(s, c))
	{
		while (s[i] == c && s[i] != 0)
			i++;
		if (!(tab[ligne] = (char*)malloc(sizeof(char) * \
						ft_size_word((char*)&s[i], c) + 1)))
		{
			while (ligne-- >= 0)
				free(tab[ligne]);
			free(tab);
			return (NULL);
		}
		i = ft_cpy_ligne(tab[ligne], (char*)s, i, c);
		ligne++;
	}
	return (ft_return_tab((char*)&s[i], tab, ligne, c));
}
