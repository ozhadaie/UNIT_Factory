/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 12:54:52 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 15:50:59 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ftpf_backend.h"

int		ft_vsnprintf(char *str, size_t size, const char *fmt, va_list args)
{
	t_multistringer	*ms;
	int				ret_val;

	ms = (t_multistringer *)ft_swnew(str, size);
	if (!ms)
		return (FTPF_ERROR);
	ret_val = ftpf_master(ms, fmt, size, args);
	ft_swdel((t_stringwriter **)(&ms));
	return (ret_val);
}
