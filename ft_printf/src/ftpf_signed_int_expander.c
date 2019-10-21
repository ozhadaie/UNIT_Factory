/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_signed_int_expander.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:58:05 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 17:37:26 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_backend.h"
#include <stdlib.h>

static void					ftpf_handle_padding_sint(t_ftpf_master_data *md,
								char **str)
{
	size_t	str_len;
	int		sign;

	sign = (((*str)[0] == '-' || md->ex->allsign || md->ex->space) ? 1 : 0);
	if ((*str)[0] != '-' && sign)
		ft_strinsert_nchr(str, md->ex->allsign ? '+' : ' ', 0, 1);
	str_len = ft_strlen(*str);
	if (md->ex->precision > 0)
	{
		ft_strinsert_nchr(str, '0', sign, md->ex->precision - str_len + sign);
		str_len = ft_strlen(*str);
	}
	if (md->ex->field_width > 0)
	{
		if (!(md->ex->lfjusty) && md->ex->zpad && (md->ex->precision <= 0))
			ft_strinsert_nchr(str, '0', sign, md->ex->field_width - str_len);
		else if (!(md->ex->lfjusty))
			ft_strinsert_nchr(str, ' ',
					0, md->ex->field_width - str_len);
		else
			ft_strinsert_nchr(str, ' ',
					str_len, md->ex->field_width - str_len);
	}
}

static int					ftpf_signed_int_expander_l(t_ftpf_master_data *md)
{
	char		*str;
	long long	value;
	int			i;

	value = 0ll;
	if (ftpf_getarg(md, &value) < 0)
		return (0);
	str = ft_litoa(value);
	if (md->ex->precision == 0 && value == 0)
		ft_bzero(str, ft_strlen(str));
	ftpf_handle_padding_sint(md, &str);
	i = 0;
	while (str[i] && (md->max_len < 0 || md->len + i < md->max_len))
		ft_mswriten(md->ms, str + i++, 1);
	free(str);
	return (i);
}

static void					reinterpret_data_for_outofrange(
								t_ftpf_master_data *md, int *value)
{
	if (!(md->ex->size_mod == FTPF_SIZEMOD_H
			|| md->ex->size_mod == FTPF_SIZEMOD_HH))
		return ;
	if (md->ex->size_mod == FTPF_SIZEMOD_H)
	{
		if (*value > 32767 || *value < -32768)
			*value = (short)(*value);
	}
	else
	{
		if (*value > 127 || *value < -128)
			*value = (char)(*value);
	}
}

int							ftpf_signed_int_expander(t_ftpf_master_data *md)
{
	char		*str;
	int			value;
	int			i;

	if (md->ex->size_mod == FTPF_SIZEMOD_L
			|| md->ex->size_mod == FTPF_SIZEMOD_LL)
		return (ftpf_signed_int_expander_l(md));
	value = 0;
	if (ftpf_getarg(md, &value) < 0)
		return (0);
	reinterpret_data_for_outofrange(md, &value);
	str = ft_itoa(value);
	if (md->ex->precision == 0 && value == 0)
		ft_bzero(str, ft_strlen(str));
	ftpf_handle_padding_sint(md, &str);
	i = 0;
	while (str[i] && (md->max_len < 0 || md->len + i < md->max_len))
		ft_mswriten(md->ms, str + i++, 1);
	free(str);
	return (i);
}
