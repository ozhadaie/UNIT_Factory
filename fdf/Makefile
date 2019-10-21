# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozhadaie <ozhadaie@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/13 14:34:05 by ozhadaie          #+#    #+#              #
#    Updated: 2019/07/29 16:09:25 by ozhadaie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=	fdf
CMPL=	cc
CFLG=	$(addprefix -W, all extra error)
SRCD=	src
INCD=	inc
OBJD=	obj
SRCS=	main.c parse.c init.c draw.c project.c color.c hook.c color2.c
OBJS=	$(addprefix $(OBJD)/, $(SRCS:.c=.o))
INCS=	$(addprefix -I, $(INCD) /usr/local/include)
INCS+=	$(addprefix -framework , OpenGL AppKit)
INCS+=	$(addprefix -l, mlx)

LIBD=	libft
LIBA=	$(addprefix $(LIBD)/, $(addsuffix .a, $(LIBD)))

all:
	@$(MAKE) -s $(OBJD)
	@$(MAKE) -sC $(LIBD)
	@$(MAKE) -s $(NAME)
	
$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $^ $(LIBA) $(CFLG) $(INCS)
	@echo "Вот это подгон: $@ ✅"

$(OBJD)/%.o: $(SRCD)/%.c
	@$(CMPL) $(CFLG) -c $< -o $@ -I$(INCD) -I$(LIBD)
	@echo "Файлы на прокачку: $(<:$(SD)/%=%) 🚀"

$(OBJD):
	@mkdir -p $(OBJD)

clean:
	@$(MAKE) -sC $(LIBD) clean
	@rm -rf $(OBJD)
	@echo "ФУ. На выкинштейн 🚮"

fclean: clean
	@$(MAKE) -sC $(LIBD) fclean
	@rm -f $(NAME)
	@echo "Кому эта либа вообще сдалась.. 🤷‍♂️"

re: fclean all
	
.PHONY: all clean fclean re lib
