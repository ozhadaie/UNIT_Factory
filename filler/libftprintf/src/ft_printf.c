/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 12:54:19 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 15:50:41 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ftpf_backend.h"
#include "libftprintf.h"

int		ft_printf(const char *fmt, ...)
{
	va_list			args;
	int				ret_val;

	va_start(args, fmt);
	ret_val = ft_vdprintf(1, fmt, args);
	va_end(args);
	return (ret_val);
}
