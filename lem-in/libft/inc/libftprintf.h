/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 12:53:57 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/09/17 19:00:53 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft.h"

# define FTPF_NONPRINTABLE_REPLACECHAR '.'

int		ft_printf(const char *fmt, ...);
int		ft_dprintf(int fd, const char *fmt, ...);
int		ft_sprintf(char *str, const char *fmt, ...);
int		ft_asprintf(char **ret, const char *fmt, ...);
int		ft_sbprintf(t_stringbuilder *sb, const char *fmt, ...);
int		ft_snprintf(char *str, size_t size, const char *fmt, ...);

int		ft_vsbprintf(t_stringbuilder *sb, const char *fmt, va_list args);
int		ft_vdprintf(int fd, const char *fmt, va_list args);
int		ft_vsprintf(char *str, const char *fmt, va_list args);
int		ft_vsnprintf(char *str, size_t size, const char *fmt, va_list args);
int		ft_vprintf(const char *fmt, va_list args);

#endif
