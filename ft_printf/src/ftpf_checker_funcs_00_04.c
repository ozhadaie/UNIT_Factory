/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_checker_funcs_00_04.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:55:56 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 17:43:39 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_backend.h"

int	ftpf_check_percent(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == '%')
	{
		ex->check_flags &= 0x00000000;
		ex->handled_len++;
		ex->expand = ftpf_percent_expander;
		return (1);
	}
	return (0);
}

int	ftpf_get_arg_num(t_ftpf_expandler *ex)
{
	int		len;

	if (*(ex->start + ex->handled_len) >= '1'
			&& *(ex->start + ex->handled_len) <= '9')
	{
		len = number_len(ex);
		if (*(ex->start + ex->handled_len + len) == '$')
		{
			ex->arg_num = (short)ft_atoi(ex->start + ex->handled_len);
			ex->handled_len += len + 1;
			ex->check_flags &= 0xFFFFFFFC;
			return (1);
		}
	}
	ex->check_flags &= ~(1 << 1);
	return (0);
}

int	ftpf_check_zeropad_mod(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == '0')
	{
		ex->check_flags &= 0xFFFFFFFD;
		ex->handled_len++;
		ex->zpad = 1;
		return (1);
	}
	return (0);
}

int	ftpf_check_spacepad_mod(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == ' ')
	{
		ex->check_flags &= 0xFFFFFFFD;
		ex->handled_len++;
		ex->space = 1;
		return (1);
	}
	return (0);
}

int	ftpf_check_alternate_form_mod(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == '#')
	{
		ex->check_flags &= 0xFFFFFFFC;
		ex->handled_len++;
		ex->altform = 1;
		return (1);
	}
	return (0);
}
