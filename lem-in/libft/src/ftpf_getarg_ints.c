/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_getarg_ints.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:57:08 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 17:26:12 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_backend.h"

void		ftpf_getarg_uint4(void *dst, va_list *args)
{
	unsigned int	ret;

	ret = va_arg((*args), unsigned int);
	if (dst)
		*((unsigned int *)dst) = ret;
}

void		ftpf_getarg_uint8(void *dst, va_list *args)
{
	unsigned long long	ret;

	ret = va_arg((*args), unsigned long long);
	if (dst)
		*((unsigned long long *)dst) = ret;
}

void		ftpf_getarg_sint4(void *dst, va_list *args)
{
	int	ret;

	ret = va_arg((*args), int);
	if (dst)
		*((int *)dst) = ret;
}

void		ftpf_getarg_sint8(void *dst, va_list *args)
{
	long long	ret;

	ret = va_arg((*args), long long);
	if (dst)
		*((long long *)dst) = ret;
}
