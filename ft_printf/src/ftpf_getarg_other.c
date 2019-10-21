/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_getarg_other.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:57:15 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 17:26:40 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_backend.h"

void		ftpf_getarg_null(void *dst, va_list *args)
{
	dst = NULL;
	args = NULL;
}

void		ftpf_getarg_ptr(void *dst, va_list *args)
{
	void	*ret;

	ret = va_arg((*args), void *);
	if (dst)
		*((void **)dst) = ret;
}

void		ftpf_getarg_float(void *dst, va_list *args)
{
	double	ret;

	ret = va_arg((*args), double);
	if (dst)
		*((double *)dst) = ret;
}

void		ftpf_getarg_floatl(void *dst, va_list *args)
{
	long double		ret;

	ret = va_arg((*args), long double);
	if (dst)
		*((long double *)dst) = ret;
}
