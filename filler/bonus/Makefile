# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/22 13:28:33 by ozhadaie          #+#    #+#              #
#    Updated: 2019/07/24 16:14:02 by ozhadaie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=	visualizer
SRCS=	main.c colorize.c
INCS=	visualizer.h
CMPL=	cc
OBJD=	obj
SRCD=	src
CFLG=	$(addprefix -W, all extra error)
INCL=	$(addprefix -I../, bonus/inc libftprintf/inc libftprintf/libft/inc)

OBJS=	$(addprefix $(OBJD)/, $(SRCS:%.c=%.o))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CMPL) -o $(NAME) $^ -L../libftprintf -lftprintf -lncurses $(INCL)
	@echo "Вот это подгон: $@ ✅"

$(OBJD)/%.o: $(SRCD)/%.c
	@mkdir -p $(OBJD)
	@$(CMPL) $(CFLG) $(INCL) -o $@ -c $<
	@echo "Файлы на прокачку: $(<:$(SD)/%=%) 🚀"

clean:
	@rm -rf $(OBJD)
	@echo "ФУ. На выкинштейн 🚮"

fclean: clean
	@rm -f $(NAME)
	@echo "Играть надоело.. 🤷‍♂️"

re: fclean all

.PHONY: all clean fclean re
