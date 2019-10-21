# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/16 18:56:44 by ozhadaie          #+#    #+#              #
#    Updated: 2019/04/16 20:50:02 by ozhadaie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit 

# src / obj files
SRC		= main.c \
		   reader.c \
		   solver.c

OBJ		= $(SRC:.c=.o)

# compiler and flags
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	$(CC) $(OBJ) $(LIB_LNK) -o $(NAME) -I libft -L libft/ -lft

%.o: %.c 
	@$(CC) $(CFLAGS) -I./libft/ -I./ -o $@ -c $<

clean:
	rm -rf $(OBJ)
	make -C libft clean

fclean: clean
	rm -rf $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
