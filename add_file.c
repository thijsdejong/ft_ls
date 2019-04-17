/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_file.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/16 13:45:37 by tde-jong       #+#    #+#                */
/*   Updated: 2019/04/17 09:46:44 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		get_full_path(char path[PATH_MAX], char *name,
								char full_path[PATH_MAX])
{
	int	i;

	i = 0;
	while (path[i])
	{
		full_path[i] = path[i];
		i++;
	}
	if (i && i < PATH_MAX)
		if (!(path[0] == '/' && path[1] == '\0'))
		{
			full_path[i] = '/';
			i++;
		}
	while (*name && i < PATH_MAX)
	{
		full_path[i] = *name;
		i++;
		name++;
	}
	if (i < PATH_MAX)
		full_path[i] = '\0';
	else
		errno = ENAMETOOLONG;
	return ((i < PATH_MAX) ? 1 : 0);
}

static t_file	*new_file(char path[PATH_MAX], char *name, t_stat *stat)
{
	t_file	*new;

	if (
		(new = (t_file*)ft_memalloc(sizeof(t_file))) == NULL ||
		(new->name = ft_strdup(name)) == NULL)
		print_error("", MALLOC_ERROR);
	new->mode = stat->st_mode;
	new->st_nlink = stat->st_nlink;
	new->st_uid = stat->st_uid;
	new->st_gid = stat->st_gid;
	new->size = stat->st_size;
	new->st_rdev = stat->st_rdev;
	new->time = stat->st_mtimespec.tv_sec;
	new->ntime = stat->st_mtimespec.tv_nsec;
	new->st_blocks = stat->st_blocks;
	get_full_path(path, name, new->full_path);
	new->next = NULL;
	return (new);
}

int				add_file(char path[PATH_MAX], char *name, t_file **lst)
{
	t_stat	stat;
	char	full_path[PATH_MAX];

	if (get_full_path(path, name, full_path) == 0)
	{
		print_error(name, ERRNO);
		return (-1);
	}
	if (lstat(full_path, &stat) == -1)
		return (-1);
	if (*lst == NULL)
		*lst = new_file(path, name, &stat);
	else
	{
		while ((*lst)->next)
			lst = &((*lst)->next);
		(*lst)->next = new_file(path, name, &stat);
	}
	return (1);
}
