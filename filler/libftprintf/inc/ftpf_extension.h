/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_extension.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 12:53:50 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 17:38:40 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPF_EXTENSION_H
# define FTPF_EXTENSION_H

typedef struct						s_ftpf_ext_dict_entry
{
	const char						directive[32];
	const int						position;
	const int						code;
}									t_ftpf_ext_dict_entry;

extern const t_ftpf_ext_dict_entry	g_ftpf_ext_dict[];

typedef struct						s_ftpf_extension_spec
{
	int								codes[3];
}									t_ftpf_extension_spec;

#endif
