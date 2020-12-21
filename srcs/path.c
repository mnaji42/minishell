/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchudant <cchudant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 11:31:28 by cchudant          #+#    #+#             */
/*   Updated: 2020/01/13 20:23:55 by cchudant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*path_normalize_tilde(char *path)
{
	if (!env_get("HOME"))
		return (ft_strdup(path));
	if (path[0] == '~')
		return (ft_strjoin(env_get("HOME"), path + 1));
	return (ft_strdup(path));
}

void		free_split(char **banana)
{
	int i;

	i = 0;
	while (banana[i])
	{
		free(banana[i]);
		i++;
	}
	free(banana);
}

static char	*find_in_path(char *path, char **banana)
{
	struct stat	ss;
	int			i;
	char		*pth;

	i = -1;
	while (banana[++i])
	{
		pth = ft_strdup(banana[i]);
		if (pth[ft_strlen(pth) - 1] != '/')
			pth = ft_strjoin_free(pth, pth, "/");
		pth = ft_strjoin_free(pth, pth, path);
		if (stat(pth, &ss) >= 0)
		{
			free_split(banana);
			return (pth);
		}
		free(pth);
	}
	free_split(banana);
	return (NULL);
}

char		*get_executable(char *path)
{
	char *path2;
	char *path_env;
	char **banana;

	path2 = path_normalize_tilde(path);
	if ((path2[0] == '.' && path2[1] == '/') || path2[0] == '/')
		return (path2);
	free(path2);
	if (!(path_env = env_get("PATH")))
		path_env = "";
	if (!(banana = ft_split(path_env, ':')))
		return (NULL);
	if ((path2 = find_in_path(path, banana)))
		return (path2);
	ft_putstr("minishell: command not found: ");
	ft_putstr(path);
	ft_putstr("\n");
	return (NULL);
}
