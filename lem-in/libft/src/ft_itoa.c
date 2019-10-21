/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:58:44 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 17:58:49 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static const char	g_base[] = "0123456789ABCDEF";

static char	*format_return(char *buff, int len)
{
	int		i;
	char	*ret;

	ret = malloc(len + 1);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = buff[len - i - 1];
		i++;
	}
	ret[len] = '\0';
	return (ret);
}

char		*ft_itoa(int value)
{
	int		negative;
	char	buff[11];
	int		len;

	negative = 0;
	if (value < 0)
		negative = 1;
	len = 0;
	while (value || len == 0)
	{
		buff[len] = '0' + ABS(value % 10);
		len++;
		value /= 10;
	}
	if (negative)
	{
		buff[len] = '-';
		len++;
	}
	return (format_return(buff, len));
}

char		*ft_itoa_base(int value, int base)
{
	int		negative;
	char	buff[33];
	int		len;

	negative = 0;
	if ((base == 10) && value < 0)
		negative = 1;
	len = 0;
	while (value || len == 0)
	{
		buff[len] = g_base[ABS(value % base)];
		len++;
		value /= base;
	}
	if (negative && base == 10)
	{
		buff[len] = '-';
		len++;
	}
	return (format_return(buff, len));
}
