/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_string_expander.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:58:08 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 17:37:36 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftpf_backend.h"

static int	determine_padding(t_ftpf_master_data *md, char *pad_char, char *str)
{
	int		str_len;

	if (md->ex->field_width == 0)
		return (0);
	if (md->ex->lfjusty)
		*pad_char = ' ';
	else
		*pad_char = md->ex->zpad ? '0' : ' ';
	str_len = ft_strlen(str);
	if (md->ex->precision >= 0 && str_len > md->ex->precision)
		str_len = md->ex->precision;
	return (md->ex->field_width - str_len);
}

static int	handle_padding(t_ftpf_master_data *md,
		int before_or_after, char *str)
{
	char	padchar;
	int		padding;

	padding = determine_padding(md, &padchar, str);
	if (before_or_after == 0)
	{
		if (padding > 0 && !(md->ex->lfjusty))
			ft_msputnchar(md->ms, padchar, padding);
	}
	else if (before_or_after == 1)
	{
		if (padding > 0 && (md->ex->lfjusty))
			ft_msputnchar(md->ms, padchar, padding);
	}
	return (padding);
}

int			ftpf_string_expander(t_ftpf_master_data *md)
{
	int		written;
	char	*str;
	int		i;
	int		must_free_null;

	must_free_null = 0;
	if (ftpf_getarg(md, &str) < 0)
		return (0);
	if (str == NULL && (str = ft_strdup("(null)")) != NULL)
		must_free_null = 1;
	written = 0;
	handle_padding(md, 0, str);
	i = 0;
	while (str[i] && (md->ex->precision < 0 || written < md->ex->precision)
			&& (md->max_len < 0 || md->len + written < md->max_len))
	{
		ft_mswriten(md->ms, str + i, 1);
		written++;
		i++;
	}
	if (handle_padding(md, 1, str) > 0)
		written += handle_padding(md, -1, str);
	if (must_free_null)
		free(str);
	return (written);
}
