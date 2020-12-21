/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchudant <cchudant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 00:30:24 by cchudant          #+#    #+#             */
/*   Updated: 2020/01/13 17:32:20 by cchudant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		g_last_return_status;
static t_var	*g_env;

t_var	**get_env(void)
{
	return (&g_env);
}

int		*get_last_return_status(void)
{
	return (&g_last_return_status);
}
