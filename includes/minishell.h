/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <mnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 11:31:28 by mnaji             #+#    #+#             */
/*   Updated: 2020/01/13 20:04:04 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <term.h>

typedef struct			s_childlist
{
	pid_t				pid;
	struct s_childlist	*next;
}						t_childlist;

typedef enum			e_redir_dir
{
	REDIR_IN,
	REDIR_OUT,
	REDIR_APP,
}						t_redir_dir;

typedef struct			s_redir
{
	t_redir_dir			dir;
	char				*file;
}						t_redir;

typedef struct			s_prog
{
	char				**cmd;
	t_redir				*redir;
	int					nb_redir;
}						t_prog;

typedef struct			s_processus
{
	char				*prc;
	char				**prc_cut;
	t_prog				*prog;
	int					nb_prog;
}						t_processus;

typedef enum			e_group_type
{
	GRP_AND,
	GRP_OR,
	GRP_PAR,
	GRP_PROC,
}						t_group_type;

typedef struct			s_group
{
	t_group_type		type;
	struct s_group		*left;
	struct s_group		*right;
	t_processus			*proc;
}						t_group;

typedef struct			s_var
{
	char				*key;
	char				*value;
	struct s_var		*next;
}						t_var;

typedef struct			s_line
{
	char				**line;
	int					i;
	t_bool				full;
}						t_line;

typedef struct			s_minishell
{
	char				**line_cut;
	int					i_l;
	t_group				*grp;
	t_line				ln;
}						t_minishell;

typedef struct			s_quote
{
	int					i;
	int					dquote;
	int					squote;
	int					escaped;
}						t_quote;

typedef struct			s_nrm_parse_prog
{
	int					i;
	int					redir;
	int					cmd;
}						t_nrm_parse_prog;

typedef struct			s_nrm_sp_around
{
	char				*left;
	char				*right;
	int					j;
}						t_nrm_sp_around;

typedef enum			e_loop
{
	BREAK = -2,
	GET_LINE = -3,
}						t_loop;

typedef struct			s_get_line
{
	char				buff_raw;
	int					i;
	int					tmp;
	int					li_temp;
	int					ret;
	t_loop				loop;
}						t_get_line;

char					**split_minishell(char const *s, char c);
int						parse_processus(t_processus *prc);
int						parse_one_group(t_group **dst, char *str, int len);
void					grp_trim(char **str, int *len);
void					parse_one_group_nrm(t_quote *q, char *str, \
							int *par_count);
int						malloc_prog_file(t_prog *prog, char *line);
int						get_value_prog(t_prog *prog, char **arg_tmp, \
							t_nrm_parse_prog n);
int						malloc_prog_cmd(t_prog *prog, char **arg_tmp);
void					append_env_var(char **ret, int *i, char *arg);
char					*handle_arg(char *arg);
int						get_line(t_line *l);
void					get_line_event_27(t_line *l, t_get_line *gl);
int						stock_char(t_line *l, t_get_line *gl);
void					get_line_del(t_line *l, t_get_line *gl);

int						return_error(char *error, int ret);
char					*ft_strndup(char *str, int len);

int						free_line_cut(char **line_cut, int ret);
int						free_all(t_line *l, t_minishell *mn, char *error);
int						return_free_line(char **line, int i, int full, \
							char *error);
void					free_minishell(t_minishell *mn);
int						free_processus(t_processus *prc, int step, int ret);
int						free_programme(t_prog *prog, int ret);

void					init_signals();
void					wait_children();
int						wrap_fork();
void					exec_group(t_minishell *mn, t_group *grp);

typedef struct			s_fdcls
{
	int					fd;
	int					must_close;
}						t_fdcls;

int						get_redir(t_prog *prog, t_fdcls *in, t_fdcls *out);

typedef struct			s_builtin_ctx
{
	char				**argv;
	int					argc;
	t_fdcls				fdin;
	t_fdcls				fdout;
	t_minishell			*mn;
}						t_builtin_ctx;

typedef struct			s_builtin_entry
{
	char				*name;
	int					(*fn)(t_builtin_ctx *ctx);
}						t_builtin_entry;

int						open_wrap(char *file, int flags, mode_t mode);

/*
** builtins
*/

int						handle_builtin(t_minishell *mn, t_prog *prog,
							t_fdcls fdin, t_fdcls fdout);

int						builtin_echo(t_builtin_ctx *ctx);
int						builtin_exit(t_builtin_ctx *ctx);
int						builtin_pwd(t_builtin_ctx *ctx);
int						builtin_cd(t_builtin_ctx *ctx);
int						builtin_export(t_builtin_ctx *ctx);
int						builtin_unset(t_builtin_ctx *ctx);
int						builtin_env(t_builtin_ctx *ctx);

/*
** env
*/

int						env_free();
int						env_load(char **env);
char					**env_get_as_array();
char					*env_get(char *key);
char					*env_nget(char *key, size_t len);
int						env_set(char *key, char *value);
int						env_unset(char *key);

/*
** path
*/

char					*path_normalize_tilde(char *path);
char					*get_executable(char *path);

t_var					**get_env();
int						*get_last_return_status();

/*
** utils
*/

size_t					ft_strnlen(char const *s, size_t len);
int						ft_strnappend(char **dst, char const *str, size_t len);
int						ft_strappend(char **dst, char const *str);
int						ft_strappend_char(char **dst, char c);
int						ft_strappend_nbr(char **dst, int i);

void					close_u(int fd);

#endif
