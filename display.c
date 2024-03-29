/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   display.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 09:49:26 by tde-jong       #+#    #+#                */
/*   Updated: 2019/04/29 11:08:33 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_file	*read_dir(char path[PATH_MAX], char *name)
{
	t_file		*head;
	DIR			*dir;
	t_dirent	*de;

	head = NULL;
	dir = opendir(path);
	if (dir == NULL)
	{
		if (errno != ENOTDIR)
			print_error(name, ERRNO);
	}
	else
	{
		de = readdir(dir);
		while (de != NULL)
		{
			if (de->d_name[0] != '.' || g_options & OPT_A)
				add_file(path, de->d_name, &head);
			de = readdir(dir);
		}
		closedir(dir);
	}
	return (head);
}

static void		print_full_path(char *full_path, int count)
{
	static int next;

	if (count > 1)
	{
		if (next || g_options & OPT_R_UPP)
			ft_printf("\n");
		else
			next = 1;
		ft_printf("%s:\n", full_path);
	}
}

static void		display_list(t_file *file)
{
	if (g_options & OPT_L)
		display_list_detailed(file, false);
	else
	{
		while (file)
		{
			ft_printf("%s\n", file->name);
			file = file->next;
		}
	}
}

void			display(t_file *file, int count, bool first)
{
	t_file *sub;

	if (!(g_options & OPT_R_UPP) && first == false)
		return ;
	while (file != NULL)
	{
		if ((S_ISDIR(file->mode) || S_ISLNK(file->mode)) && (first ||
			(ft_strcmp(file->name, ".") && ft_strcmp(file->name, ".."))))
		{
			sub = read_dir(file->full_path, file->name);
			if (sub || S_ISDIR(file->mode))
				print_full_path(file->full_path, count);
			if (first && (g_options & OPT_L) && S_ISLNK(file->mode))
				display_list_detailed(file, true);
			else if (sub)
			{
				sort(&sub);
				display_list(sub);
				display(sub, 2, false);
				free_lst(&sub);
			}
		}
		file = file->next;
	}
}
