/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sbtostr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 18:01:43 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 18:01:45 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_sbtostr(t_stringbuilder *sb)
{
	char	*str;

	str = (char *)ft_hat_toarr(sb->hat, 0, sb->len);
	return (str);
}
