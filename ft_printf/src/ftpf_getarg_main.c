/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_getarg_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:57:12 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 17:26:11 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_backend.h"

int			ftpf_getarg(t_ftpf_master_data *md, void *dst)
{
	void					*hatptr;
	va_list					args_copy;
	short					arg_num;
	short					i;
	t_ftpf_getarg_func		f;

	va_copy(args_copy, md->args);
	arg_num = (md->ex->arg_num < 0 ? md->next_arg_num : md->ex->arg_num);
	md->next_arg_num = arg_num + 1;
	i = 1;
	while (i < arg_num)
	{
		if (((hatptr = ft_hataccess(md->arg_getters, i)) == NULL)
				|| ((f = *((t_ftpf_getarg_func *)hatptr)) == NULL))
			return (FTPF_ERROR);
		f(NULL, &(args_copy));
		i++;
	}
	if (((hatptr = ft_hataccess(md->arg_getters, i)) == NULL)
			|| ((f = *((t_ftpf_getarg_func *)hatptr)) == NULL))
		return (FTPF_ERROR);
	f(dst, &(args_copy));
	va_end(args_copy);
	return (1);
}
