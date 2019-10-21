/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_floatl_expander.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:56:56 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 17:23:40 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftpf_backend.h"

static void		guarantee_precision(t_ftpf_master_data *md)
{
	if (md->ex->precision < 0)
		md->ex->precision = 6;
}

int				ftpf_floatl_expander(t_ftpf_master_data *md)
{
	char				*str;
	t_ftpf_fltl_hlpr	*h;
	long double			val;
	int					i;

	if (ftpf_getarg(md, &val) < 0)
		return (0);
	if ((str = ftpf_fltl_check_special(val)))
		return (ftpf_expand_special_float(md, str));
	guarantee_precision(md);
	h = ftpf_fltl_hlpr_new(val);
	ftpf_fltl_get_fpul(md, h);
	str = ftpf_flt_hlpr_get_str(md, FTBF_GET_SGN_LD(val), (t_ftpf_flt_hlpr *)h);
	free(h);
	ftpf_handle_padding_float(md, &str);
	i = 0;
	while (str[i] && (md->max_len < 0 || md->len + i < md->max_len))
		ft_mswriten(md->ms, str + i++, 1);
	free(str);
	return (i);
}
