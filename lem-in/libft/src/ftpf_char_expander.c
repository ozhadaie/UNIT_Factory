/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_char_expander.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:55:52 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 15:55:21 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ftpf_backend.h"

static void					ftpf_handle_padding_char(t_ftpf_master_data *md,
								char **str)
{
	int		len;

	len = (int)ft_strlen(*str);
	if (md->ex->field_width > 0)
	{
		if (!(md->ex->lfjusty) && md->ex->zpad)
			ft_strinsert_nchr(str, '0', 0, md->ex->field_width - 1);
		else if (!(md->ex->lfjusty))
			ft_strinsert_nchr(str, ' ', 0, md->ex->field_width - 1);
		else if (len == 0)
			ft_strinsert_nchr(str, ' ', len, md->ex->field_width);
		else
			ft_strinsert_nchr(str, ' ', len, md->ex->field_width - 1);
	}
}

static int					write_null_terminator(t_ftpf_master_data *md,
								int i)
{
	if (md->max_len < 0 || md->len + i < md->max_len)
	{
		ft_mswrite_nullterm(md->ms);
		return (1);
	}
	return (0);
}

int							ftpf_char_expander(t_ftpf_master_data *md)
{
	char			*str;
	int				value;
	int				i;

	i = 0;
	if (ftpf_getarg(md, &value) < 0)
		return (0);
	if (value == 0 && md->ex->lfjusty)
	{
		i += write_null_terminator(md, i);
		str = ft_strdup("");
	}
	else
	{
		str = ft_strnew(1);
		str[0] = (unsigned char)value;
	}
	ftpf_handle_padding_char(md, &str);
	while (str[i] && (md->max_len < 0 || md->len + i < md->max_len))
		ft_mswriten(md->ms, str + i++, 1);
	free(str);
	if (value == 0 && !(md->ex->lfjusty))
		i += write_null_terminator(md, i);
	return (i);
}
