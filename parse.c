/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/11 14:27:49 by tde-jong       #+#    #+#                */
/*   Updated: 2019/04/16 12:35:21 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		parse(char **arguments, int limit, t_file **file_list)
{
	int i;
	int	stage;
	int	opt;

	i = 0;
	opt = 1;
	while (i < limit)
	{
		if (opt == 1 && ft_strnequ("-", arguments[i], 1) && arguments[i][1])
		{
			if (handle_option(arguments[i] + 1) == 0)
				return (0);
		}
		else
		{
			opt = 0;

			ft_printf("file: %s\n", arguments[i]);
		}
		i++;
	}
	return (1);
}
