/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchudant <cchudant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 07:34:24 by cchudant          #+#    #+#             */
/*   Updated: 2020/01/09 23:53:10 by cchudant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	cd_chdir(t_builtin_ctx *ctx, char *loc)
{
	char *tilde;

	tilde = path_normalize_tilde(loc);
	if (chdir(tilde) < 0)
	{
		ft_putstr_fd("cd: ", ctx->fdout.fd);
		ft_putstr_fd(strerror(errno), ctx->fdout.fd);
		ft_putstr_fd(": ", ctx->fdout.fd);
		ft_putendl_fd(loc, ctx->fdout.fd);
		free(tilde);
		return (1);
	}
	free(tilde);
	return (0);
}

int			builtin_cd(t_builtin_ctx *ctx)
{
	if (ctx->argc > 2)
	{
		ft_putendl_fd("cd: too many arguments", ctx->fdout.fd);
		return (1);
	}
	if (ctx->argc == 1)
		return (cd_chdir(ctx, "~"));
	return (cd_chdir(ctx, ctx->argv[1]));
}
