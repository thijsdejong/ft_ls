/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   display_detailed.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 14:43:36 by tde-jong       #+#    #+#                */
/*   Updated: 2019/04/18 14:57:46 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

size_t		get_total_blocks(t_file *file)
{
	size_t blocks;

	blocks = 0;
	while (file)
	{
		blocks += file->st_blocks;
		file = file->next;
	}
	return (blocks);
}

void		display_list_detailed(t_file *file)
{
	ft_printf("total %zd\n", get_total_blocks(file));
	while (file)
	{

		file = file->next;
	}
}
