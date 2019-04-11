/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helper.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/11 14:27:06 by tde-jong       #+#    #+#                */
/*   Updated: 2019/04/11 14:27:15 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_invalid_option(char c)
{
	ft_dprintf(STDERR_FILENO, "ft_ls: illegal option -- %c\n"
				"usage: ft_ls [-%s] [file ...]\n", c, OPTIONS);
}
