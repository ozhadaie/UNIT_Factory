/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_float_expander.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:56:27 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 17:23:19 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftpf_backend.h"

void			ftpf_handle_padding_float(t_ftpf_master_data *md, char **str)
{
	size_t	str_len;
	int		sign;

	sign = (((*str)[0] == '-' || md->ex->allsign || md->ex->space) ? 1 : 0);
	str_len = ft_strlen(*str);
	if (md->ex->field_width > 0)
	{
		if (!(md->ex->lfjusty) && md->ex->zpad)
			ft_strinsert_nchr(str, '0', sign, md->ex->field_width - str_len);
		else if (!(md->ex->lfjusty))
			ft_strinsert_nchr(str, ' ', 0, md->ex->field_width - str_len);
		else
			ft_strinsert_nchr(str, ' ',
					str_len, md->ex->field_width - str_len);
	}
}

char			*ftpf_flt_hlpr_get_str(t_ftpf_master_data *md,
						int neg, t_ftpf_flt_hlpr *h)
{
	t_stringbuilder	*sb;
	char			*str;
	int				i;
	int				len;

	sb = ft_sbnew();
	if (neg)
		ft_sbwrite(sb, "-");
	else if (md->ex->allsign || md->ex->space)
		ft_sbwrite(sb, (md->ex->allsign ? "+" : " "));
	ft_ms_put_ul((t_multistringer *)sb, h->ip);
	if (md->ex->precision > 0 || md->ex->altform)
		ft_sbwrite(sb, ".");
	i = -1;
	len = ftpf_flt_ul_len(h->fpul);
	while (++i < md->ex->precision - len)
		ft_sbwrite(sb, "0");
	if (md->ex->precision)
		ft_ms_put_ul((t_multistringer *)sb, h->fpul);
	str = ft_sbtostr(sb);
	ft_sbdel(&sb);
	return (str);
}

static void		guarantee_precision(t_ftpf_master_data *md)
{
	if (md->ex->precision < 0)
		md->ex->precision = 6;
}

int				ftpf_float_expander(t_ftpf_master_data *md)
{
	char				*str;
	t_ftpf_flt_hlpr		*h;
	double				val;
	int					i;

	if (md->ex->size_mod == FTPF_SIZEMOD_BIGL)
		return (ftpf_floatl_expander(md));
	if (ftpf_getarg(md, &val) < 0)
		return (0);
	if ((str = ftpf_flt_check_special(val)))
		return (ftpf_expand_special_float(md, str));
	guarantee_precision(md);
	h = ftpf_flt_hlpr_new(val);
	ftpf_flt_get_fpul(md, h);
	str = ftpf_flt_hlpr_get_str(md, FTPF_DBL_IS_NEG(val), h);
	free(h);
	ftpf_handle_padding_float(md, &str);
	i = 0;
	while (str[i] && (md->max_len < 0 || md->len + i < md->max_len))
		ft_mswriten(md->ms, str + i++, 1);
	free(str);
	return (i);
}
