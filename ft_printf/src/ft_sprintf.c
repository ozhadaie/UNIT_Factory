/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 12:54:33 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 15:50:50 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ftpf_backend.h"
#include "libftprintf.h"

int		ft_sprintf(char *buff, const char *fmt, ...)
{
	va_list			args;
	int				ret_val;

	if (buff == NULL)
		return (-1);
	va_start(args, fmt);
	ret_val = ft_vsprintf(buff, fmt, args);
	va_end(args);
	return (ret_val);
}
