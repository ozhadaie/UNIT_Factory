/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_checker_funcs_15_19.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:56:05 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 16:10:30 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_backend.h"

int		ftpf_check_longdouble_mod(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == 'L')
	{
		ex->handled_len++;
		ex->size_mod = FTPF_SIZEMOD_BIGL;
		ex->check_flags &= 0xFFFF0000;
		return (1);
	}
	ex->check_flags &= ~(1 << 15);
	return (0);
}

int		ftpf_check_ptr_expansion(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == 'p')
	{
		ex->handled_len++;
		ex->check_flags &= 0;
		ex->expand = ftpf_ptr_expander;
		return (1);
	}
	ex->check_flags &= ~(1 << 16);
	return (0);
}

int		ftpf_check_signed_int_expansion(t_ftpf_expandler *ex)
{
	if ((*(ex->start + ex->handled_len) == 'd') ||
		(*(ex->start + ex->handled_len) == 'i') ||
		(*(ex->start + ex->handled_len) == 'D'))
	{
		if (*(ex->start + ex->handled_len) == 'D')
			ex->size_mod = FTPF_SIZEMOD_L;
		ex->handled_len++;
		ex->check_flags &= 0;
		ex->expand = ftpf_signed_int_expander;
		return (1);
	}
	ex->check_flags &= ~(1 << 17);
	return (0);
}

int		ftpf_check_binary_expansion(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == 'b')
	{
		ex->handled_len++;
		ex->check_flags &= 0;
		ex->expand = ftpf_binary_expander;
		return (1);
	}
	ex->check_flags &= ~(1 << 18);
	return (0);
}

int		ftpf_check_unsigned_int_expansion(t_ftpf_expandler *ex)
{
	if ((*(ex->start + ex->handled_len) == 'u') ||
		(*(ex->start + ex->handled_len) == 'U'))
	{
		if (*(ex->start + ex->handled_len) == 'U')
			ex->size_mod = FTPF_SIZEMOD_L;
		ex->handled_len++;
		ex->check_flags &= 0;
		ex->expand = ftpf_unsigned_int_expander;
		return (1);
	}
	ex->check_flags &= ~(1 << 19);
	return (0);
}
