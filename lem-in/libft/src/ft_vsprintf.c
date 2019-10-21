/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 12:54:58 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 15:51:01 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ftpf_backend.h"

int		ft_vsprintf(char *str, const char *fmt, va_list args)
{
	t_multistringer	*ms;
	int				ret_val;

	ms = (t_multistringer *)ft_swnew(str, 2147483647);
	if (!ms)
		return (FTPF_ERROR);
	ret_val = ftpf_master(ms, fmt, 2147483647, args);
	ft_swdel((t_stringwriter **)(&ms));
	return (ret_val);
}
