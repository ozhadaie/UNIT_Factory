/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <ozhadaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 21:44:05 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/30 21:54:17 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_isxdigit(char c)
{
	const char	*digits = "0123456789ABCDEF";
	int			i;

	i = -1;
	while (++i < 16)
		if (digits[i] == ft_toupper(c))
			return (i);
	return (-1);
}

static int	ft_isprefix(const char *str)
{
	size_t	i;

	i = 0;
	if (str[i++] != '0')
		return (1);
	if (str[i] == 'x' || str[i] == 'X')
		return (1);
	return (0);
}

int			ft_isvalid(char *str)
{
	size_t		i;
	size_t		digits;

	i = 0;
	digits = 0;
	while (ft_isspace(str[i]))
		i++;
	if (!ft_isprefix(&str[i]))
		return (0);
	i += 2;
	while (ft_isxdigit(str[i]) >= 0)
	{
		i++;
		digits++;
	}
	return ((!str[i] && digits) ? 1 : 0);
}

int			ft_ctoi(const char *str)
{
	unsigned long	result;
	size_t			i;
	int				sign;

	result = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (!ft_isprefix(&str[i]))
		return (0);
	i += 2;
	while (ft_isxdigit(str[i]) >= 0)
		result = result * 16 + ft_isxdigit(str[i++]);
	return ((int)(result * sign));
}
