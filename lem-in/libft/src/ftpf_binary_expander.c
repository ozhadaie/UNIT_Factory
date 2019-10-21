/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_binary_expander.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:55:41 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 15:54:08 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftpf_backend.h"

static void				ftpf_handle_padding_binary(t_ftpf_master_data *md,
							char **str)
{
	size_t	str_len;

	str_len = ft_strlen(*str);
	if (md->ex->field_width > 0)
	{
		if (!(md->ex->lfjusty))
			ft_strinsert_nchr(str, ' ', 0, md->ex->field_width - str_len);
		else
			ft_strinsert_nchr(str, ' ', str_len, md->ex->field_width - str_len);
	}
}

static char				*get_str(t_ftpf_master_data *md, void *start)
{
	t_stringbuilder	*sb;
	char			*str;
	int				i;

	sb = ft_sbnew();
	i = md->ex->precision - 1;
	while (i >= 0)
	{
		ftpf_sbwrite_bit(sb, start, i);
		if (i != 0 && md->ex->altform && i % 4 == 0)
			ft_sbwrite(sb, ".");
		i--;
	}
	str = ft_sbtostr(sb);
	ft_sbdel(&sb);
	return (str);
}

int						ftpf_binary_expander(t_ftpf_master_data *md)
{
	char			*str;
	void			*start;
	int				i;

	if (ftpf_getarg(md, &start) < 0 || start == NULL)
		return (0);
	md->ex->precision = ftpf_guarantee_precision_memory(md) * 8;
	str = get_str(md, start);
	ftpf_handle_padding_binary(md, &str);
	i = 0;
	while (str[i] && (md->max_len < 0 || md->len + i < md->max_len))
	{
		ft_mswriten(md->ms, str + i, 1);
		i++;
	}
	free(str);
	return (i);
}
