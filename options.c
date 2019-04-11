/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   options.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/11 14:27:31 by tde-jong       #+#    #+#                */
/*   Updated: 2019/04/11 14:29:21 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	set_option(char opt)
{
	int	i;

	i = ft_isin(opt, OPTIONS);
	if (i < 0)
		return (0);
	g_options |= (1 << i);
	return (1);
}

int			handle_option(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		if (!set_option(str[i]))
		{
			print_invalid_option(str[i]);
			return (0);
		}
		i++;
	}
	return (1);
}
