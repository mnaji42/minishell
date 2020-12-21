# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchudant <cchudant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/11 15:59:01 by mnaji             #+#    #+#              #
#    Updated: 2020/01/07 02:47:38 by cchudant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OBJ_DIR = ./objs/

SRC_FILES =	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstclear.c ft_lstadd_front.c ft_lstiter.c ft_lstmap.c ft_powerof.c ft_putnligne.c ft_putseparation.c ft_linkcpy.c ft_lstlen.c ft_lstdel_first.c ft_lstdel_last.c ft_lstdel_nfirst.c ft_lstdel_nlast.c ft_lstdel_all.c ft_putlink_nbr.c ft_putlst_nbr.c ft_putlink_str.c ft_putlst_str.c ft_putlink_char.c ft_putlst_char.c ft_printlink.c ft_printlst.c ft_dblist_new.c ft_dblist_isempty.c ft_dblist_len.c ft_dblist_addlast.c ft_dblist_addfirst.c ft_dblist_delfirst.c ft_dblist_dellast.c ft_dblist_print.c ft_dblink_free.c ft_dblist_delall.c ft_strjoin_free.c ft_strncpy_last.c ft_strchr_tab.c ft_strrev.c ft_substr_free.c ft_dblink_del.c ft_strdup_free.c get_next_line.c ft_isnbr_int.c ft_ishexa_int.c ft_atoi_base.c ft_strlcpy.c ft_lstlast.c ft_lstadd_back.c ft_calloc.c
OBJ_FILES = $(SRC_FILES:.c=.o)

OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

CC = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\033[32mLibft.a generated !\033[0m"

$(OBJ_DIR)%.o: %.c
	@mkdir $(OBJ_DIR) 2> /dev/null || true
	@$(CC) -o $@ -c $<

clean:
	@rm -Rf $(OBJ_DIR)
	@echo "\033[31mObjects deleted !\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31mLibft.a deleted !\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re
