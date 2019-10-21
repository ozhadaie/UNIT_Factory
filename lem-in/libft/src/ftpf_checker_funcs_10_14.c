/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_checker_funcs_10_14.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:56:02 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 16:09:53 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_backend.h"

int	ftpf_check_precision_mod(t_ftpf_expandler *ex)
{
	int		len;

	if (*(ex->start + ex->handled_len) == '.')
	{
		ex->handled_len++;
		len = number_len(ex);
		ex->precision = ft_atoi(ex->start + ex->handled_len);
		ex->handled_len += len;
		ex->check_flags &= 0xFFFFF981;
		return (1);
	}
	ex->check_flags &= ~(1 << 10);
	return (0);
}

int	ftpf_check_shortshort_mod(t_ftpf_expandler *ex)
{
	if ((*(ex->start + ex->handled_len) == 'h') &&
		*(ex->start + ex->handled_len + 1) == 'h')
	{
		ex->handled_len += 2;
		ex->size_mod = FTPF_SIZEMOD_HH;
		ex->check_flags &= 0xFFFF0000;
		return (1);
	}
	ex->check_flags &= ~(1 << 11);
	return (0);
}

int	ftpf_check_short_mod(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == 'h')
	{
		ex->handled_len++;
		ex->size_mod = FTPF_SIZEMOD_H;
		ex->check_flags &= 0xFFFF0000;
		return (1);
	}
	ex->check_flags &= ~(1 << 12);
	return (0);
}

int	ftpf_check_longlong_mod(t_ftpf_expandler *ex)
{
	if ((*(ex->start + ex->handled_len) == 'l') &&
		*(ex->start + ex->handled_len + 1) == 'l')
	{
		ex->handled_len += 2;
		ex->size_mod = FTPF_SIZEMOD_LL;
		ex->check_flags &= 0xFFFF0000;
		return (1);
	}
	ex->check_flags &= ~(1 << 13);
	return (0);
}

int	ftpf_check_long_mod(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == 'l')
	{
		ex->handled_len++;
		ex->size_mod = FTPF_SIZEMOD_L;
		ex->check_flags &= 0xFFFF0000;
		return (1);
	}
	ex->check_flags &= ~(1 << 14);
	return (0);
}
