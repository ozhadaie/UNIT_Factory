/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_ptr_expander.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:58:02 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 17:35:16 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_backend.h"

int			ftpf_ptr_expander(t_ftpf_master_data *md)
{
	md->ex->altform = 1;
	md->ex->size_mod = FTPF_SIZEMOD_L;
	md->ex->precision = -1;
	return (ftpf_hexlower_expander(md));
}
