/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchudant <cchudant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 07:34:24 by cchudant          #+#    #+#             */
/*   Updated: 2020/01/09 23:36:53 by cchudant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			builtin_pwd(t_builtin_ctx *ctx)
{
	char cwd[PATH_MAX];

	if (ctx->argc > 1)
	{
		ft_putendl_fd("pwd: too many arguments", ctx->fdout.fd);
		return (1);
	}
	getcwd(cwd, PATH_MAX);
	ft_putendl_fd(cwd, ctx->fdout.fd);
	return (0);
}
