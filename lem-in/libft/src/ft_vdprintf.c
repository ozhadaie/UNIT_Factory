/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 12:54:38 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 15:50:52 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ftpf_backend.h"

int		ft_vdprintf(int fd, const char *fmt, va_list args)
{
	t_multistringer	*ms;
	int				ret_val;

	ms = (t_multistringer *)ft_fdwnew(fd);
	if (!ms)
		return (FTPF_ERROR);
	ret_val = ftpf_master(ms, fmt, FTPF_UNLIMITED_LEN, args);
	ft_fdwdel((t_fdwriter **)(&ms));
	return (ret_val);
}
