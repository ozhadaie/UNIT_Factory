/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:38:03 by ozhadaie          #+#    #+#             */
/*   Updated: 2018/11/08 18:38:04 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ret_atoi(t_ull ret, int sign, const char *s)
{
	int	count;

	count = 0;
	while (*s <= '1' || *s >= '9')
		s++;
	while (ft_isdigit(*(s + count)))
		count++;
	if (count >= 19)
		return (sign == -1 ? 0 : -1);
	if (ret > 9223372036854775807)
		return (sign == -1 ? 0 : -1);
	else
		return (ret * sign);
}

int			ft_atoi(const char *str)
{
	t_ull	ret;
	int		len;
	int		i;
	int		sign;

	ret = 0;
	sign = 1;
	i = -1;
	while (ft_isspace(*str))
		str++;
	len = ft_strlen(str);
	while (++i <= len)
	{
		if (ft_isdigit(str[i]))
			ret = ret * 10 + str[i] - '0';
		else if (i == 0 && (str[i] == '-' || str[i] == '+'))
			sign = str[i] == '-' ? -1 : 1;
		else
			return (ft_ret_atoi(ret, sign, str));
	}
	return (ft_ret_atoi(ret, sign, str));
}
