/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:35:53 by ozhadaie          #+#    #+#             */
/*   Updated: 2018/11/10 16:35:55 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_neg(int *n, int *sign)
{
	if (*n < 0)
	{
		*n *= -1;
		*sign = 1;
	}
}

char		*ft_itoa(int n)
{
	int		tmp;
	int		l;
	int		sign;
	char	*ret;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tmp = n;
	l = 2;
	sign = 0;
	ft_neg(&n, &sign);
	while (tmp /= 10)
		l++;
	l += sign;
	if ((ret = (char*)malloc(l)) == NULL)
		return (NULL);
	ret[--l] = '\0';
	while (l--)
	{
		ret[l] = n % 10 + '0';
		n /= 10;
	}
	if (sign)
		ret[0] = '-';
	return (ret);
}
