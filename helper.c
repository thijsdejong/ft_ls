/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helper.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/11 14:27:06 by tde-jong       #+#    #+#                */
/*   Updated: 2019/04/16 12:29:04 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <errno.h>

void	print_error(char *str, int e)
{
	if (e == USAGE)
		ft_dprintf(STDERR_FILENO, "ft_ls: illegal option -- %s\n"
				"usage: ft_ls [-%s] [file ...]\n", str, OPTIONS);
	else if (e == ERRNO)
		ft_dprintf(STDERR_FILENO, "ft_ls: %s: %s", str, strerror(errno));
}
