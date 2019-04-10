/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 07:23:12 by tde-jong       #+#    #+#                */
/*   Updated: 2019/04/10 12:10:32 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../libft.h"
# include <unistd.h>
# include <stdlib.h>

# define BUFF_SIZE 42

typedef struct			s_gnl_list
{
	ssize_t				fd;
	ssize_t				str_len;
	char				*str;
	struct s_gnl_list	*next;
}						t_gnl_list;

int						get_next_line(const int fd, char **line);

#endif
