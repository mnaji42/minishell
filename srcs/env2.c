/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchudant <cchudant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 11:31:28 by mnaji             #+#    #+#             */
/*   Updated: 2020/01/10 02:06:00 by cchudant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*env_get(char *key)
{
	t_var	*lst;

	lst = *get_env();
	while (lst)
	{
		if (!ft_strcmp(lst->key, key))
			return (lst->value);
		lst = lst->next;
	}
	return (NULL);
}

char	*env_nget(char *key, size_t len)
{
	t_var	*lst;

	lst = *get_env();
	while (lst)
	{
		if (!ft_strncmp(lst->key, key, len))
			return (lst->value);
		lst = lst->next;
	}
	return (NULL);
}

/*
** env_set: `value` and `key` will be strdup'ed on need, you must retain
**   full ownership of the values you pass
** returns 0 on error
*/

int		env_set(char *key, char *value)
{
	t_var	*lst;

	lst = *get_env();
	while (lst)
	{
		if (!ft_strcmp(lst->key, key))
		{
			free(lst->value);
			lst->value = ft_strdup(value);
			return (1);
		}
		lst = lst->next;
	}
	if (!(lst = malloc(sizeof(t_var))))
		return (0);
	lst->next = *get_env();
	lst->key = ft_strdup(key);
	lst->value = ft_strdup(value);
	*get_env() = lst;
	return (1);
}

int		env_unset(char *key)
{
	t_var	*tmp;
	t_var	**lst;

	lst = get_env();
	while (*lst)
	{
		if (!ft_strcmp((*lst)->key, key))
		{
			tmp = *lst;
			*lst = tmp->next;
			free(tmp->key);
			free(tmp->value);
			free(tmp);
			return (1);
		}
		lst = &(*lst)->next;
	}
	return (0);
}
