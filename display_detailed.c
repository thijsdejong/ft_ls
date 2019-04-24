/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   display_detailed.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 14:43:36 by tde-jong       #+#    #+#                */
/*   Updated: 2019/04/24 16:53:02 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static size_t		get_total_blocks(t_file *file)
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

static char		get_type(t_file *file)
{
	if (S_ISDIR(file->mode))
		return ('d');
	else if (S_ISLNK(file->mode))
		return ('l');
	else if (S_ISBLK(file->mode))
		return ('b');
	else if (S_ISCHR(file->mode))
		return ('c');
	else if (S_ISSOCK(file->mode))
		return ('s');
	else if (S_ISFIFO(file->mode))
		return ('p');
	else
		return ('-');
}

static void	print_permissions(t_file *file)
{
	char *output;

	output = (char*)ft_memalloc(sizeof(char) * 11);
	if (output == NULL)
		print_error("", MALLOC_ERROR);
	output[0] = get_type(file);
	ft_putstr(output);
	free(output);
}

void		display_list_detailed(t_file *file)
{
	ft_printf("total %zd\n", get_total_blocks(file));
	while (file)
	{
		print_permissions(file);
		ft_printf(" %s\n", file->name);
		file = file->next;
	}
}
