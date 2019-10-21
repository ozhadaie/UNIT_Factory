/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 18:00:11 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 18:00:11 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*ret;
	size_t	i;

	if (size == 0)
		return (NULL);
	ret = malloc(size);
	i = 0;
	if (ret == NULL)
		return (NULL);
	while (i < size)
	{
		*((unsigned char *)ret + i) = 0;
		i++;
	}
	return (ret);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t i;

	i = 0;
	while (i++ < len)
		*((char *)b + i - 1) = (unsigned char)c;
	return (b);
}

void	ft_bzero(void *s, size_t len)
{
	size_t i;

	i = 0;
	while (i++ < len)
		*((char *)s + i - 1) = '\0';
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *)dst + i) = *((unsigned char *)src + i);
		i++;
	}
	return (dst);
}

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *)dst + i) = *((unsigned char *)src + i);
		if (*((unsigned char *)dst + i) == (unsigned char)c)
			return ((void *)((unsigned char *)dst + i + 1));
		i++;
	}
	return (NULL);
}
