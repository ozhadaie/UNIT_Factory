# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/12 13:14:52 by ozhadaie          #+#    #+#              #
#    Updated: 2019/07/12 14:00:13 by ozhadaie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NM	=	libftprintf.a
CC	=	cc
CF	=	$(addprefix -W, all extra error)
ID	=	inc
LD	=	libft
SD	=	src
OD	=	obj
SC	=	ft_asprintf.c ft_printf.c ft_sbprintf.c \
		ft_snprintf.c ft_sprintf.c \
		ft_vdprintf.c ft_vsbprintf.c \
		ft_vsnprintf.c ft_vsprintf.c \
		ft_vprintf.c \
		ftpf_expandler.c ftpf_master.c \
		ftpf_checker_funcs_index.c \
		ftpf_checker_funcs_00_04.c \
		ftpf_checker_funcs_05_09.c \
		ftpf_checker_funcs_10_14.c \
		ftpf_checker_funcs_15_19.c \
		ftpf_checker_funcs_20_24.c \
		ftpf_checker_funcs_25_29.c \
		ftpf_percent_expander.c \
		ftpf_signed_int_expander.c \
		ftpf_unsigned_int_expander.c \
		ftpf_string_expander.c \
		ftpf_extension_expander.c \
		ftpf_hexlower_expander.c \
		ftpf_hexupper_expander.c \
		ftpf_octal_expander.c \
		ftpf_char_expander.c \
		ftpf_ptr_expander.c \
		ftpf_float_expander.c \
		ftpf_float_expander_utils.c \
		ftpf_floatl_expander.c \
		ftpf_floatl_expander_utils.c \
		ftpf_memory_and_binary_utils.c \
		ftpf_memory_expander.c \
		ftpf_binary_expander.c \
		ftpf_flt_expander_special.c \
		ftpf_getarg_ints.c \
		ftpf_getarg_main.c \
		ftpf_getarg_other.c

CO	=	$(addprefix $(OD)/, $(SC:.c=.o))

all: $(NM)

$(NM): $(CO)
	@make -C libft/
	@ar rcs $(NM) $(CO) $(LD)/$(OD)/*.o
	@echo "Вот это подгон: $@ ✅"

$(OD)/%.o: $(SD)/%.c
	@mkdir -p $(OD)
	@$(CC) $(CF) -I$(ID) -I$(LD)/$(ID) -o $@ -c $<
	@echo "Файлы на прокачку: $(<:$(SD)/%=%) 🚀"

clean:
	@make -C $(LD) clean
	@rm -rf $(OD)
	@echo "ФУ. На выкинштейн 🚮"

fclean: clean
	@make -C $(LD) fclean
	@rm -f $(NM)
	@echo "Кому эта либа вообще сдалась.. 🤷‍♂️"

re: fclean all

.PHONY: all clean fclean re
