# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/12 13:14:52 by ozhadaie          #+#    #+#              #
#    Updated: 2019/09/18 14:19:37 by ozhadaie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NM	=	libft.a
CC	=	cc
CF	=	$(addprefix -W, all extra error)
ID	=	inc
LD	=	libft
SD	=	src
OD	=	obj
SC	=	ft_atoi.c ft_buffwriter.c ft_destroy_nullterm_ptrarray.c \
		ft_fildeswriter.c ft_get_next_line.c ft_hat.c ft_hat_aux.c \
		ft_hat_backend_1.c ft_hat_toarr.c ft_hatdellf.c ft_hatinslf.c \
		ft_itoa.c ft_litoa.c ft_mem_1.c ft_mem_2.c ft_mswrite_nullterm.c \
		ft_multistringer.c ft_multistringer_aux.c ft_print_hex.c \
		ft_putchar.c ft_putnbr.c ft_putstr.c ft_sbtostr.c ft_str_aux.c \
		ft_str_constructors.c ft_strcat.c ft_strcmp.c ft_strcpy.c \
		ft_stringbuilder.c ft_stringwriter.c ft_strjoin.c ft_strsplit.c \
		ft_strstr.c ft_strtrim.c \
		ft_asprintf.c ft_printf.c ft_sbprintf.c \
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
	@ar rcs $@ $^
	@printf "\r\33[2K$@\t created\n"

$(OD)/%.o: $(SD)/%.c | $(OD)
	@$(CC) $(CF) $(addprefix -I, $(ID)) -o $@ -c $<
	@printf "\r\33[2KCompiling\t$(<:$(SD)/%=%)"

$(OD):
	@mkdir -p $@

clean:
	@rm -rf $(OD)

fclean: clean
	@rm -f $(NM)

re: fclean all

.PHONY: all clean fclean re
