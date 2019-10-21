# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2029/07/19 12:27:54 by ozhadaie          #+#    #+#              #
#    Updated: 2019/07/24 21:34:49 by ozhadaie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=	ozhadaie.filler
LIBD=	libftprintf
CMPL=	cc
CFLG=	$(addprefix -W, all extra error)
INCD=	$(addprefix -I, inc libftprintf/inc libftprintf/libft/inc)
SRCD=	src
OBJD=	obj
BNSD=	bonus
LIBD=	libftprintf
INCL=	$(addprefix inc/, filler.h)
SRCS=	main.c filler.c
OBJS=	$(addprefix $(OBJD)/, $(SRCS:%.c=%.o))

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -sC $(LIBD)
	@$(CMPL) -o $(NAME) $^ -L $(LIBD) -lftprintf
	@echo "\033[32m$@\033[0m ready to play"

$(OBJD)/%.o: $(SRCD)/%.c $(INCL)
	@mkdir -p $(OBJD)
	$(CMPL) $(CFLG) -o $@ -c $< $(INCD)

clean:
	@$(MAKE) -sC $(BNSD) clean
	@$(MAKE) -sC $(LIBD) clean
	@rm -rf $(OBJD)

fclean: clean
	@$(MAKE) -sC $(BNSD) fclean
	@$(MAKE) -sC $(LIBD) fclean
	@rm -f $(NAME)

re: fclean all

game: all
	-@./resources/filler_vm -f resources/maps/map02 -p1 ./ozhadaie.filler -p2 resources/players/carli.filler

vis: all
	@$(MAKE) -C $(BNSD)
	-./resources/filler_vm -f resources/maps/map02 -p1 ./ozhadaie.filler -p2 resources/players/carli.filler | ./$(BNSD)/visualizer

.PHONY: all fclean clean re game vis
