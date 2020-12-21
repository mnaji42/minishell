/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <mnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 03:12:13 by mnaji             #+#    #+#             */
/*   Updated: 2019/12/11 11:54:15 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_dblink
{
	char			*str;
	int				nb;
	struct s_dblink	*back;
	struct s_dblink	*next;
}				t_dblink;

typedef struct	s_dblist
{
	int				len;
	struct s_dblink	*first;
	struct s_dblink	*last;
}				t_dblist;

typedef enum
{
	false,
	true
}	t_bool;

typedef struct	s_stock
{
	int		fd;
	char	s[BUFFER_SIZE];
	int		len;
	int		old_len;
}				t_stock;

void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putnbr(int n);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
void			ft_putendl(char const *s);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack,
							const char *needle, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *nptr);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char *s, void (*f)(unsigned int, char));
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
t_list			*ft_lstnew(void const *content);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstadd_front(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *));
int				ft_powerof(int nb, int power);
void			ft_putnligne(int n);
void			ft_putseparation(void);
t_list			*ft_linkcpy(t_list *link);
int				ft_lstlen(t_list *lst);
t_list			*ft_lstdel_first(t_list *lst);
t_list			*ft_lstdel_last(t_list *lst);
t_list			*ft_lstdel_nfirst(t_list *lst, int i);
t_list			*ft_lstdel_nlast(t_list *lst, int i);
t_list			*ft_lstdel_all(t_list *lst);
void			ft_putlink_nbr(t_list *lst);
void			ft_putlst_nbr(t_list *lst);
void			ft_putlink_str(t_list *lst);
void			ft_putlst_str(t_list *lst);
void			ft_putlink_char(t_list *lst);
void			ft_putlst_char(t_list *lst);
void			ft_printlink(t_list *lst);
void			ft_printlst(t_list *lst);
t_dblist		*ft_dblist_new(void);
t_bool			ft_dblist_isempty(t_dblist *dlst);
int				ft_dblist_len(t_dblist *dlst);
t_dblist		*ft_dblist_addlast(t_dblist *dlst, char *str, int nb);
t_dblist		*ft_dblist_addfirst(t_dblist *dlst, char *str, int nb);
t_dblist		*ft_dblist_dellast(t_dblist *dlst);
t_dblist		*ft_dblist_delfirst(t_dblist *dlst);
void			ft_dblist_print(t_dblist *dlst);
t_dblink		*ft_dblink_free(t_dblink *lnk);
t_dblist		*ft_dblist_delall(t_dblist *dlst);
char			*ft_strjoin_free(char *tofree, char *s1, char *s2);
char			*ft_strncpy_last(char *dest, char *src, int n);
int				ft_strchr_tab(char *str, char c);
char			*ft_strrev(char *str);
char			*ft_substr_free(char *s, int start, size_t len);
t_dblink		*ft_dblink_del(t_dblink *dlnk, t_dblist *dlst);
char			*ft_strdup_free(char *tofree, char *s);
int				get_next_line(int fd, char **line);
int				ft_isnbr_int(char *str);
int				ft_ishexa_int(char *str);
int				ft_atoi_base(const char *nptr, int base);
size_t			ft_strlcpy(char	*dest, const char *src, size_t size);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *new);

#endif
