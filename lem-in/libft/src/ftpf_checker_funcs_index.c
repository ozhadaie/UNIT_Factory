/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_checker_funcs_index.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:56:17 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 16:16:03 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_backend.h"

const	t_ftpf_checker_func		g_checkfuncs[FTPF_NUM_CHECKFLAGS] =
{
	ftpf_check_percent,
	ftpf_get_arg_num,
	ftpf_check_zeropad_mod,
	ftpf_check_spacepad_mod,
	ftpf_check_alternate_form_mod,
	ftpf_check_leftjustify_mod,
	ftpf_check_alwayssign_mod,
	NULL,
	NULL,
	ftpf_check_fieldwidth_mod,
	ftpf_check_precision_mod,
	ftpf_check_shortshort_mod,
	ftpf_check_short_mod,
	ftpf_check_longlong_mod,
	ftpf_check_long_mod,
	ftpf_check_longdouble_mod,
	ftpf_check_ptr_expansion,
	ftpf_check_signed_int_expansion,
	ftpf_check_binary_expansion,
	ftpf_check_unsigned_int_expansion,
	ftpf_check_hexlower_expansion,
	ftpf_check_hexupper_expansion,
	ftpf_check_float_expansion,
	ftpf_check_string_expansion,
	ftpf_check_char_expansion,
	ftpf_check_octal_expansion,
	ftpf_check_memory_expansion,
	ftpf_check_extension_expansion,
};

int						number_len(t_ftpf_expandler *ex)
{
	int		i;
	char	c;

	i = 0;
	c = *(ex->start + ex->handled_len + i);
	while (1)
	{
		if (!(c >= '0' && c <= '9'))
			return (i);
		i++;
		c = *(ex->start + ex->handled_len + i);
	}
	return (0);
}
