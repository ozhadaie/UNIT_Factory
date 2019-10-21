/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:01:28 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 18:03:11 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int					ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	value;
	int	spaces;

	sign = 1;
	value = 0;
	spaces = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			value = value * 10 + sign * (str[i] - '0');
		else if (i == spaces && str[i] == '+')
			;
		else if (i <= spaces && str[i] == '-')
			sign = -1;
		else if (i <= spaces && (str[i] == ' '
					|| (str[i] >= 9 && str[i] <= 13)))
			spaces++;
		else
			break ;
		i++;
	}
	return (value);
}

unsigned long		ft_atoul(const char *str)
{
	int				i;
	unsigned long	value;
	int				spaces;

	value = 0;
	spaces = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			value = value * 10 + (str[i] - '0');
		else if (i == spaces && str[i] == '+')
			;
		else if (i <= spaces && str[i] == '-')
			return (0);
		else if (i <= spaces && (str[i] == ' '
					|| (str[i] >= 9 && str[i] <= 13)))
			spaces++;
		else
			break ;
		i++;
	}
	return (value);
}
