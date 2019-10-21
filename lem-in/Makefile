# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/15 16:54:06 by ozhadaie          #+#    #+#              #
#    Updated: 2019/09/23 18:37:01 by ozhadaie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:=	lem-in

SRCD:=	src
INCD:=	inc
OBJD:=	obj

LIBD:=	libft
LIBA:=	$(LIBD)/$(LIBD).a
LIBI:=	$(LIBD)/$(INCD)

FILE:=	ants\
		args\
		dijkstra\
		find\
		line\
		list\
		main\
		path\
		print\
		read\
		room\
		utils

SRCS:=	$(addprefix $(SRCD)/, $(addsuffix .c, $(FILE)))
OBJS:=	$(addprefix $(OBJD)/, $(addsuffix .o, $(FILE)))
INCS:=	$(addprefix $(INCD)/, $(addsuffix .h, lem_in))

CMPL:=	gcc $(addprefix -W, all extra error)

all: $(NAME)

$(NAME): $(OBJS) $(LIBA)
	@$(CMPL) -o $@ $^
	@printf "\r\33[2K$@\t created\n"

$(OBJD)/%.o: $(SRCD)/%.c $(INCS) | $(OBJD)
	@$(CMPL) -o $@ -c $< $(addprefix -I, $(INCD) $(LIBI))
	@printf "\r\33[2KCompiling \t$<"

$(OBJD):
	@mkdir -p $@

$(LIBA):
	@make -sC $(LIBD)

clean:
	@make -sC $(LIBD) $@
	@rm -rf $(OBJD)

fclean: clean
	@make -sC $(LIBD) $@
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean lclean lfclean re
