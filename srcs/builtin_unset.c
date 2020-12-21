/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchudant <cchudant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 07:34:24 by cchudant          #+#    #+#             */
/*   Updated: 2020/01/09 23:53:43 by cchudant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			builtin_unset(t_builtin_ctx *ctx)
{
	int i;

	if (ctx->argc < 2)
	{
		ft_putendl_fd("unset: not enough arguments", ctx->fdout.fd);
		return (1);
	}
	i = 1;
	while (i < ctx->argc)
	{
		env_unset(ctx->argv[i]);
		i++;
	}
	return (0);
}
