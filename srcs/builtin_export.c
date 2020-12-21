/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchudant <cchudant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 07:34:24 by cchudant          #+#    #+#             */
/*   Updated: 2020/01/10 00:38:10 by cchudant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	disp_env(t_builtin_ctx *ctx)
{
	t_var	*lst;

	lst = *get_env();
	while (lst)
	{
		ft_putstr_fd(lst->key, ctx->fdout.fd);
		ft_putstr_fd("=", ctx->fdout.fd);
		ft_putendl_fd(lst->value, ctx->fdout.fd);
		lst = lst->next;
	}
	return (0);
}

int			builtin_export(t_builtin_ctx *ctx)
{
	char *ptr;
	char *key;

	if (ctx->argc == 1)
		return (disp_env(ctx));
	if (!(ptr = ft_strchr(ctx->argv[1], '=')))
		return (0);
	if (!(key = ft_strndup(ctx->argv[1], ptr - ctx->argv[1])))
		return (1);
	env_set(key, ptr + 1);
	free(key);
	return (0);
}
