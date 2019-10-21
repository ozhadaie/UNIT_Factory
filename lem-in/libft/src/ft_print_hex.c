/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 18:01:27 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 18:01:28 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static const char	g_base[] = "0123456789abcdef";

void				ft_print_hex(unsigned int n)
{
	if (n >= 16)
	{
		ft_print_hex(n / 16);
		write(1, g_base + (n % 16), 1);
	}
	else
	{
		write(1, g_base + n, 1);
	}
}

static void			print_hex_padded_rec(unsigned int n, unsigned int width,
		unsigned int digit)
{
	if (n >= 16 || digit < width - 1)
	{
		print_hex_padded_rec(n / 16, width, digit + 1);
		write(1, g_base + (n % 16), 1);
	}
	else
	{
		write(1, g_base + n, 1);
	}
}

void				ft_print_hex_padded(unsigned int n, unsigned int width)
{
	print_hex_padded_rec(n, width, 0);
}

void				ft_printhexbyte(const void *loc)
{
	if (*((unsigned char *)loc) < 16)
		write(1, "0", 1);
	else
		write(1, g_base + (*((unsigned char *)loc) / 16), 1);
	write(1, g_base + (*((unsigned char *)loc) % 16), 1);
}
