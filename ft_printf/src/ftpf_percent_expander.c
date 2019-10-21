/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_percent_expander.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:57:58 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 17:34:05 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftpf_backend.h"

static void						ftpf_handle_padding_pct(t_ftpf_master_data *md,
									char **str)
{
	if (md->ex->field_width > 0)
	{
		if (!(md->ex->lfjusty) && md->ex->zpad)
			ft_strinsert_nchr(str, '0', 0, md->ex->field_width - 1);
		else if (!(md->ex->lfjusty))
			ft_strinsert_nchr(str, ' ', 0, md->ex->field_width - 1);
		else
			ft_strinsert_nchr(str, ' ', 1, md->ex->field_width - 1);
	}
}

int								ftpf_percent_expander(
									t_ftpf_master_data *md)
{
	char	*str;
	int		i;

	str = ft_strdup("%");
	ftpf_handle_padding_pct(md, &str);
	i = 0;
	while (str[i] && (md->max_len < 0 || md->len + i < md->max_len))
	{
		ft_mswriten(md->ms, str + i, 1);
		i++;
	}
	free(str);
	return (i);
}
