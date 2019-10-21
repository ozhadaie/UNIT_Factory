/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:53:00 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/03/17 16:29:02 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 9999
# define MAX_FD 256

typedef struct	s_read
{
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;
}				t_read;

int				get_next_line(const int fd, char **line);

#endif
