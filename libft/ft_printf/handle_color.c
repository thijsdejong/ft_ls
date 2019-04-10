/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_color.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/26 16:18:20 by tde-jong       #+#    #+#                */
/*   Updated: 2019/04/10 15:35:03 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_set(char *str, int val, int *ret, int fd)
{
	ft_putstr_fd(str, fd);
	*ret = val;
}

int			pf_handle_color(t_info *info, const char **format)
{
	int	ret;

	if (!ft_strncmp("{black}", *format, 7))
		put_set(PF_COL_BLACK, 7, &ret, PF_FD);
	else if (!ft_strncmp("{red}", *format, 5))
		put_set(PF_COL_RED, 5, &ret, PF_FD);
	else if (!ft_strncmp("{green}", *format, 7))
		put_set(PF_COL_GREEN, 7, &ret, PF_FD);
	else if (!ft_strncmp("{yellow}", *format, 8))
		put_set(PF_COL_YELLOW, 8, &ret, PF_FD);
	else if (!ft_strncmp("{blue}", *format, 6))
		put_set(PF_COL_BLUE, 6, &ret, PF_FD);
	else if (!ft_strncmp("{magenta}", *format, 9))
		put_set(PF_COL_MAGENTA, 9, &ret, PF_FD);
	else if (!ft_strncmp("{cyan}", *format, 6))
		put_set(PF_COL_CYAN, 6, &ret, PF_FD);
	else if (!ft_strncmp("{white}", *format, 7))
		put_set(PF_COL_WHITE, 7, &ret, PF_FD);
	else if (!ft_strncmp("{eoc}", *format, 5))
		put_set(PF_COL_END, 5, &ret, PF_FD);
	else
		return (0);
	*format += ret;
	PF_RET += 5;
	return (1);
}
