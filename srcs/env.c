/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchudant <cchudant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 11:31:28 by mnaji             #+#    #+#             */
/*   Updated: 2020/01/13 17:26:48 by cchudant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			env_free(void)
{
	t_var	*tmp;

	while (*get_env())
	{
		tmp = *get_env();
		*get_env() = (*get_env())->next;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
	}
	*get_env() = NULL;
	return (0);
}

int			env_load(char **env)
{
	t_var	*lst;
	size_t	pos;

	while (*env)
	{
		if (!(lst = malloc(sizeof(t_var))))
			return (env_free());
		pos = ft_strchr(*env, '=') - *env;
		lst->key = ft_strndup(*env, pos);
		lst->value = ft_strdup(*env + pos + 1);
		lst->next = *get_env();
		*get_env() = lst;
		env++;
	}
	return (1);
}

static int	env_num_entries(void)
{
	int		len;
	t_var	*lst;

	len = 0;
	lst = *get_env();
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

static void	env_cpy(char *ret, t_var *lst)
{
	ft_memcpy(ret, lst->key, ft_strlen(lst->key));
	ret[ft_strlen(lst->key)] = '=';
	ft_memcpy(ret + ft_strlen(lst->key) + 1,
			lst->value, ft_strlen(lst->value));
	ret[ft_strlen(lst->key) + ft_strlen(lst->value) + 1] = '\0';
}

char		**env_get_as_array(void)
{
	int		i;
	char	**ret;
	t_var	*lst;

	if (!(ret = malloc(sizeof(char *) * (env_num_entries() + 1))))
		return (NULL);
	lst = *get_env();
	i = 0;
	while (lst)
	{
		if (!(ret[i] = malloc(sizeof(char) *
				(ft_strlen(lst->key) + ft_strlen(lst->value) + 2))))
		{
			while (i >= 0)
				free(ret[i--]);
			free(ret);
			return (NULL);
		}
		env_cpy(ret[i], lst);
		lst = lst->next;
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
