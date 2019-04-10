/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_color.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/26 16:18:20 by tde-jong       #+#    #+#                */
/*   Updated: 2019/03/26 10:48:41 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_set(char *str, int val, int *ret)
{
	ft_putstr(str);
	*ret = val;
}

int			handle_color(t_info *info, const char **format)
{
	int	ret;

	if (!ft_strncmp("{black}", *format, 7))
		put_set(PF_COL_BLACK, 7, &ret);
	else if (!ft_strncmp("{red}", *format, 5))
		put_set(PF_COL_RED, 5, &ret);
	else if (!ft_strncmp("{green}", *format, 7))
		put_set(PF_COL_GREEN, 7, &ret);
	else if (!ft_strncmp("{yellow}", *format, 8))
		put_set(PF_COL_YELLOW, 8, &ret);
	else if (!ft_strncmp("{blue}", *format, 6))
		put_set(PF_COL_BLUE, 6, &ret);
	else if (!ft_strncmp("{magenta}", *format, 9))
		put_set(PF_COL_MAGENTA, 9, &ret);
	else if (!ft_strncmp("{cyan}", *format, 6))
		put_set(PF_COL_CYAN, 6, &ret);
	else if (!ft_strncmp("{white}", *format, 7))
		put_set(PF_COL_WHITE, 7, &ret);
	else if (!ft_strncmp("{eoc}", *format, 5))
		put_set(PF_COL_END, 5, &ret);
	else
		return (0);
	*format += ret;
	PF_RET += 5;
	return (1);
}
