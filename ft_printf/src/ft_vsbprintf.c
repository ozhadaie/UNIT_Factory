/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsbprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 12:54:48 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 15:50:57 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ftpf_backend.h"

int		ft_vsbprintf(t_stringbuilder *sb, const char *fmt, va_list args)
{
	t_multistringer	*ms;

	ms = (t_multistringer *)sb;
	return (ftpf_master(ms, fmt, FTPF_UNLIMITED_LEN, args));
}
