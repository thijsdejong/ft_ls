/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   display_detailed.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 14:43:36 by tde-jong       #+#    #+#                */
/*   Updated: 2019/04/29 09:58:44 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	*get_time(t_file *file)
{
	time_t	today;

	time(&today);
	return (ctime(&(file->time)));
}

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
	output[1] = (S_IRUSR & file->mode) ? 'r' : '-';
	output[2] = (S_IWUSR & file->mode) ? 'w' : '-';
	output[3] = (S_IXUSR & file->mode) ? 'x' : '-';
	output[4] = (S_IRGRP & file->mode) ? 'r' : '-';
	output[5] = (S_IWGRP & file->mode) ? 'w' : '-';
	output[6] = (S_IXGRP & file->mode) ? 'x' : '-';
	output[7] = (S_IROTH & file->mode) ? 'r' : '-';
	output[8] = (S_IWOTH & file->mode) ? 'w' : '-';
	output[9] = (S_IXOTH & file->mode) ? 'x' : '-';
	ft_putstr(output);
	free(output);
}

void		display_list_detailed(t_file *file)
{
	char	lnk[NAME_MAX + 1];

	ft_printf("total %zd\n", get_total_blocks(file));
	while (file)
	{
		print_permissions(file);
		ft_printf(" %hu ", file->st_nlink);
		if (getpwuid(file->st_uid) == NULL)
			ft_printf("%u ", file->st_uid);
		else
			ft_printf("%s ", getpwuid(file->st_uid)->pw_name);
		if (getgrgid(file->st_gid) == NULL)
			ft_printf("%u ", file->st_uid);
		else
			ft_printf("%s ", getgrgid(file->st_gid)->gr_name);
		ft_printf("%lli %.16s %s", file->size, get_time(file), file->name);
		if (S_ISLNK(file->mode))
		{
			ft_bzero(lnk, NAME_MAX + 1);
			readlink(file->full_path, lnk, NAME_MAX);
			ft_printf(" -> %s", lnk);
		}
		ft_putchar('\n');
		file = file->next;
	}
}
