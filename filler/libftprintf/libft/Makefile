# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/12 13:42:25 by ozhadaie          #+#    #+#              #
#    Updated: 2019/07/12 13:52:36 by ozhadaie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NM	=	libft.a
CC	=	cc
CF	=	$(addprefix -W, all extra error)
ID	=	inc
OD	=	obj
SD	=	src
SC	=	ft_get_next_line.c \
		ft_putstr.c \
		ft_strcmp.c \
		ft_mem_1.c \
		ft_destroy_nullterm_ptrarray.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_putnbr.c \
		ft_litoa.c \
		ft_str_constructors.c \
		ft_mem_2.c \
		ft_strcpy.c \
		ft_putchar.c \
		ft_itoa.c \
		ft_str_aux.c \
		ft_strtrim.c \
		ft_strcat.c \
		ft_strjoin.c \
		ft_atoi.c \
		ft_print_hex.c \
		ft_hat_toarr.c \
		ft_hatdellf.c \
		ft_hat_aux.c \
		ft_hatinslf.c \
		ft_hat_backend_1.c \
		ft_hat.c \
		ft_multistringer_aux.c \
		ft_sbtostr.c \
		ft_buffwriter.c \
		ft_stringwriter.c \
		ft_fildeswriter.c \
		ft_multistringer.c \
		ft_mswrite_nullterm.c \
		ft_stringbuilder.c

CO	=	$(addprefix $(OD)/, $(SC:.c=.o))

all: $(NM)

$(NM): $(CO)
	@ar rcs $(NM) $(CO)
	@echo "Вот это подгон: $@ ✅"

$(OD)/%.o: $(SD)/%.c
	@mkdir -p $(OD)
	@$(CC) $(CF) -c $< -o $@ -I$(ID)
	@echo "Файлы на прокачку: $(<:$(SD)/%=%) 🚀"

clean:
	@rm -rf $(OD)
	@echo "ФУ. На выкинштейн 🚮"

fclean: clean
	@rm -rf $(NM)
	@echo "Кому эта либа вообще сдалась.. 🤷‍♂️"

re: fclean all

.PHONY: all clean fclean re
