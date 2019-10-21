/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_checker_funcs_20_24.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:56:10 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 16:13:41 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_backend.h"

int		ftpf_check_hexlower_expansion(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == 'x')
	{
		ex->handled_len++;
		ex->check_flags &= 0;
		ex->expand = ftpf_hexlower_expander;
		return (1);
	}
	ex->check_flags &= ~(1 << 20);
	return (0);
}

int		ftpf_check_hexupper_expansion(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == 'X')
	{
		ex->handled_len++;
		ex->check_flags &= 0;
		ex->expand = ftpf_hexupper_expander;
		return (1);
	}
	ex->check_flags &= ~(1 << 21);
	return (0);
}

int		ftpf_check_float_expansion(t_ftpf_expandler *ex)
{
	if ((*(ex->start + ex->handled_len) == 'f') ||
		(*(ex->start + ex->handled_len) == 'F'))
	{
		if (*(ex->start + ex->handled_len) == 'F')
			ex->size_mod = FTPF_SIZEMOD_L;
		ex->handled_len++;
		ex->check_flags &= 0;
		ex->expand = ftpf_float_expander;
		return (1);
	}
	ex->check_flags &= ~(1 << 22);
	return (0);
}

int		ftpf_check_string_expansion(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == 's')
	{
		ex->handled_len++;
		ex->check_flags &= 0;
		ex->expand = ftpf_string_expander;
		return (1);
	}
	ex->check_flags &= ~(1 << 23);
	return (0);
}

int		ftpf_check_char_expansion(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == 'c')
	{
		ex->handled_len++;
		ex->check_flags &= 0;
		ex->expand = ftpf_char_expander;
		return (1);
	}
	ex->check_flags &= ~(1 << 24);
	return (0);
}
