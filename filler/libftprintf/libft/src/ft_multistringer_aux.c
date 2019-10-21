/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multistringer_aux.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 18:01:15 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 18:01:22 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ms_put_ul(t_multistringer *ms, unsigned long nb)
{
	char	c;

	c = '0' + (nb % 10);
	if (nb >= 10)
	{
		ft_ms_put_ul(ms, nb / 10);
		ft_mswriten(ms, &c, 1);
	}
	else
		ft_mswriten(ms, &c, 1);
}

void	ft_msputnchar(t_multistringer *ms, char c, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_mswriten(ms, &c, 1);
		i++;
	}
}
