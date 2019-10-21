/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multistringer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 18:01:10 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 18:01:10 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mswrite(t_multistringer *ms, const char *str)
{
	if (ms == NULL || str == NULL)
		return ;
	if (ms->sb.type == 'B')
		ft_sbwrite((t_stringbuilder *)ms, str);
	else if (ms->sb.type == 'W')
		ft_swwrite((t_stringwriter *)ms, str);
	else if (ms->sb.type == 'U')
		ft_bwwrite((t_stringwriter *)ms, str);
	else if (ms->sb.type == 'F')
		ft_fdwwrite((t_fdwriter *)ms, str);
}

void	ft_mswriten(t_multistringer *ms, const char *str, size_t n)
{
	if (ms == NULL || str == NULL)
		return ;
	if (ms->sb.type == 'B')
		ft_sbwriten((t_stringbuilder *)ms, str, n);
	else if (ms->sb.type == 'W')
		ft_swwriten((t_stringwriter *)ms, str, n);
	else if (ms->sb.type == 'U')
		ft_bwwriten((t_stringwriter *)ms, str, n);
	else if (ms->sb.type == 'F')
		ft_fdwwriten((t_fdwriter *)ms, str, n);
}

void	ft_msclear(t_multistringer *ms)
{
	if (ms == NULL)
		return ;
	if (ms->sb.type == 'B')
		ft_sbclear((t_stringbuilder *)ms);
	else if (ms->sb.type == 'W')
		ft_swclear((t_stringwriter *)ms);
	else if (ms->sb.type == 'U')
		ft_bwclear((t_stringwriter *)ms);
	else if (ms->sb.type == 'F')
		ft_fdwclear((t_fdwriter *)ms);
}

void	ft_msdel(t_multistringer **ms)
{
	if (ms == NULL || *ms == NULL)
		return ;
	if ((*ms)->sb.type == 'B')
		ft_sbdel((t_stringbuilder **)ms);
	else if ((*ms)->sb.type == 'W')
		ft_swdel((t_stringwriter **)ms);
	else if ((*ms)->sb.type == 'U')
		ft_swdel((t_stringwriter **)ms);
	else if ((*ms)->sb.type == 'F')
		ft_fdwdel((t_fdwriter **)ms);
}
