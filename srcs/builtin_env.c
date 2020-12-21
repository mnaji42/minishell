/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchudant <cchudant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 07:34:24 by cchudant          #+#    #+#             */
/*   Updated: 2020/01/10 00:38:20 by cchudant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			builtin_env(t_builtin_ctx *ctx)
{
	t_var	*lst;

	if (ctx->argc > 1)
	{
		ft_putendl_fd("env: too many arguments", ctx->fdout.fd);
		return (1);
	}
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
