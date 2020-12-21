/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_minishell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchudant <cchudant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:36:29 by mnaji             #+#    #+#             */
/*   Updated: 2020/01/13 18:53:44 by cchudant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_count_word(char const *s, char c)
{
	int		count_word;
	t_quote	q;

	q = (t_quote) {.squote = -1, .dquote = -1};
	count_word = 0;
	while (s[q.i] != '\0')
	{
		while (s[q.i] == c && (q.dquote == -1 || q.squote == -1))
			if (s[++q.i] == '\0')
				return (count_word);
		while ((s[q.i] != c || q.dquote == 1 || q.squote == 1) && s[q.i])
		{
			if (s[q.i] == '"' && q.squote == -1 && !q.escaped)
				q.dquote *= -1;
			else if (s[q.i] == '\'' && q.dquote == -1)
				q.squote *= -1;
			if (s[q.i] == '\0')
				return (count_word + 1);
			q.escaped = s[q.i++] == '\\' ? !q.escaped : 0;
		}
		count_word++;
	}
	return (count_word);
}

static int	ft_size_word(char *str, char c)
{
	int		count;
	t_quote	q;

	q = (t_quote) {.squote = -1, .dquote = -1};
	count = 0;
	while ((str[q.i] != c || q.dquote == 1 || q.squote == 1) && str[q.i])
	{
		if (str[q.i] == '"' && q.squote == -1 && !q.escaped)
			q.dquote *= -1;
		else if (str[q.i] == '\'' && q.dquote == -1)
			q.squote *= -1;
		q.escaped = str[q.i] == '\\' ? !q.escaped : 0;
		count++;
		q.i++;
	}
	return (count);
}

static int	ft_cpy_ligne(char *tab1, char *s, int i, char c)
{
	t_quote	q;

	q = (t_quote) {.squote = -1, .dquote = -1};
	while ((s[i] != c || q.dquote == 1 || q.squote == 1) && s[i] != 0)
	{
		if (s[i] == '"' && q.squote == -1 && !q.escaped)
			q.dquote *= -1;
		else if (s[i] == '\'' && q.dquote == -1)
			q.squote *= -1;
		q.escaped = s[q.i] == '\\' ? !q.escaped : 0;
		tab1[q.i] = s[i];
		i++;
		q.i++;
	}
	tab1[q.i] = '\0';
	return (i);
}

static char	**ft_return_tab(char *s, char **tab1, int ligne, char c)
{
	if (*s - 1 != c)
		tab1[ligne] = 0;
	else
		tab1[ligne - 1] = 0;
	return (tab1);
}

char		**split_minishell(char const *s, char c)
{
	char	**tab1;
	int		i;
	int		ligne;

	if (!s || !c || !(tab1 = (char**)malloc(sizeof(char*) *\
					(ft_count_word(s, c) + 1))))
		return (NULL);
	ligne = 0;
	i = 0;
	while (ligne < ft_count_word(s, c))
	{
		while (s[i] == c && s[i] != 0)
			i++;
		if (!(tab1[ligne] = (char*)malloc(sizeof(char) * \
						ft_size_word((char*)&s[i], c) + 1)))
		{
			while (ligne-- >= 0)
				free(tab1[ligne]);
			free(tab1);
			return (NULL);
		}
		i = ft_cpy_ligne(tab1[ligne], (char*)s, i, c);
		ligne++;
	}
	return (ft_return_tab((char*)&s[i], tab1, ligne, c));
}
