/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_checker_funcs_25_29.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:56:13 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 16:15:04 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_backend.h"

int		ftpf_check_octal_expansion(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == 'o')
	{
		ex->handled_len++;
		ex->check_flags &= 0;
		ex->expand = ftpf_octal_expander;
		return (1);
	}
	ex->check_flags &= ~(1 << 25);
	return (0);
}

int		ftpf_check_memory_expansion(t_ftpf_expandler *ex)
{
	if (*(ex->start + ex->handled_len) == 'm')
	{
		ex->handled_len++;
		ex->check_flags &= 0;
		ex->expand = ftpf_memory_expander;
		return (1);
	}
	ex->check_flags &= ~(1 << 26);
	return (0);
}

int		ftpf_check_extension_expansion(t_ftpf_expandler *ex)
{
	int		len;

	if (*(ex->start + ex->handled_len) == '{')
	{
		len = 1;
		while (*(ex->start + ex->handled_len + len) != '\0' &&
				*(ex->start + ex->handled_len + len) != '}')
			len++;
		if (*(ex->start + ex->handled_len + len) == '}')
		{
			ex->handled_len += len + 1;
			ex->expand = ftpf_extension_expander;
			ex->check_flags = 0;
			return (1);
		}
		ex->handled_len = 2;
		ex->check_flags = 0;
		return (0);
	}
	ex->check_flags &= ~(1 << 27);
	return (0);
}
