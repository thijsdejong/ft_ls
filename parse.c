/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/11 14:27:49 by tde-jong       #+#    #+#                */
/*   Updated: 2019/04/11 14:48:48 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		parse(char **arguments, int limit)
{
	int i;
	int	stage;

	i = 0;
	stage = 1;
	while (i < limit)
	{
		if (stage == 1 && ft_strnequ("-", arguments[i], 1) && arguments[i][1])
		{
			if (handle_option(arguments[i] + 1) == 0)
				return (0);
		}
		else
		{
			stage = 2;
			ft_printf("file: %s\n", arguments[i]);
		}
		i++;
	}
	return (1);
}
