/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchudant <cchudant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 07:34:24 by cchudant          #+#    #+#             */
/*   Updated: 2020/01/09 22:45:34 by cchudant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		builtin_echo(t_builtin_ctx *ctx)
{
	int i;
	int nono;

	i = 1;
	nono = 0;
	if (ctx->argc > 1 && !ft_strcmp(ctx->argv[1], "-n"))
	{
		i++;
		nono = 1;
	}
	while (i < ctx->argc)
	{
		ft_putstr_fd(ctx->argv[i], ctx->fdout.fd);
		if (i != ctx->argc - 1)
			ft_putstr_fd(" ", ctx->fdout.fd);
		i++;
	}
	if (!nono)
		ft_putstr_fd("\n", ctx->fdout.fd);
	return (0);
}
