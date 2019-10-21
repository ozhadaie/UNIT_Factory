/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 18:01:32 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 18:01:34 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putchar_np(char c, char c_if_nonprintable)
{
	if (c >= 32 && c <= 126)
		write(1, &c, 1);
	else
		write(1, &c_if_nonprintable, 1);
}
