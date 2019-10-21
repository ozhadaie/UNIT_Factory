/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 12:54:13 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 15:50:37 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "libftprintf.h"
#include "ftpf_backend.h"

int		ft_asprintf(char **ret, const char *fmt, ...)
{
	va_list			args;
	t_stringbuilder	*sb;
	int				ret_val;

	if (ret == NULL)
		return (-1);
	sb = ft_sbnew();
	if (sb == NULL)
		return (-1);
	va_start(args, fmt);
	ret_val = ft_vsbprintf(sb, fmt, args);
	*ret = ft_sbtostr(sb);
	if (*ret == NULL)
		return (-1);
	ft_sbdel(&sb);
	va_end(args);
	return (ret_val);
}
