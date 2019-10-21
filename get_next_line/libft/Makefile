# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/12 18:06:24 by ozhadaie          #+#    #+#              #
#    Updated: 2019/03/13 18:37:40 by ozhadaie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
CMPL	=	gcc
FLGS	=	-Wall -Wextra -Werror
INCL	=	-Iincludes/
SRCS	=	ft_atoi.c ft_itoa.c\
			ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_islower.c ft_isprint.c ft_ispunct.c ft_isspace.c ft_isupper.c\
			ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_bzero.c\
			ft_strcat.c ft_strchr.c ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strlcat.c ft_strlen.c ft_strncat.c ft_strncmp.c\
			ft_strncpy.c ft_strnstr.c ft_strrchr.c ft_strstr.c\
			ft_tolower.c ft_toupper.c\
			ft_memalloc.c ft_memdel.c\
			ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c\
			ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c\
			ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c\
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
			ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c\
			ft_lst_push_back.c ft_lst_size.c ft_lstrev.c

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\033[0;32m [OK] \033[0m	\033[0;33m Compiling:\033[0;36m $(NAME)\033[0m"
	@echo "\033[0;35m Successful created ^^^^^^^\033[0m"

%.o: %.c
	@$(CMPL) $(FLGS) $(INCL) -o $@ -c $<
	@echo "\033[0;32m [OK] \033[0m	\033[0;33m Compiling: \033[0;32m$<\033[0m"

clean:
	@rm -f $(OBJS)
	@echo "\033[0;32m [OK] \033[0m	\033[0;33m Cleaning...\033[0m" 

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;32m [OK] \033[0m	\033[0;33m Deleting: \033[0;31m$(NAME)\033[0m" 

re: fclean all

.PHONY: clean fclean all re

