/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 18:48:00 by ozhadaie          #+#    #+#             */
/*   Updated: 2018/10/24 18:48:02 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int result;
	int i;

	result = 1;
	i = 0;
	if (nb <= 13 && nb >= 0)
	{
		while (++i <= nb)
			result *= i;
		return (result);
	}
	return (0);
}
