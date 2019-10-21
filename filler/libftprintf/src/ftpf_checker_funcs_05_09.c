/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_checker_funcs_05_09.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:55:59 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 16:04:33 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_backend.h"

int	ftpf_check_leftjustify_mod(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == '-')
	{
		ex->check_flags &= 0xFFFFFFFD;
		ex->handled_len++;
		ex->lfjusty = 1;
		return (1);
	}
	return (0);
}

int	ftpf_check_alwayssign_mod(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == '+')
	{
		ex->check_flags &= 0xFFFFFFFC;
		ex->handled_len++;
		ex->allsign = 1;
		return (1);
	}
	return (0);
}

int	ftpf_check_fieldwidth_mod(t_ftpf_expandler *ex)
{
	int		len;

	if (*(ex->start + ex->handled_len) >= '1'
			&& *(ex->start + ex->handled_len) <= '9')
	{
		len = number_len(ex);
		ex->field_width = (unsigned short)ft_atoi(ex->start + ex->handled_len);
		ex->handled_len += len;
		ex->check_flags &= 0xFFFFFD81;
		return (1);
	}
	ex->check_flags &= ~(1 << 9);
	return (0);
}
