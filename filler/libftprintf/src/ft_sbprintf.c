/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sbprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 12:54:23 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 15:50:45 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ftpf_backend.h"
#include "libftprintf.h"

int		ft_sbprintf(t_stringbuilder *sb, const char *fmt, ...)
{
	va_list		args;
	int			ret;

	va_start(args, fmt);
	ret = ft_vsbprintf(sb, fmt, args);
	va_end(args);
	return (ret);
}
