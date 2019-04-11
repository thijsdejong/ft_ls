/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 18:08:31 by tde-jong       #+#    #+#                */
/*   Updated: 2019/04/11 15:35:10 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>

t_file	*get_file_list(char **filenames, int n)
{
	t_file	*head;
	int		i;

	head = NULL;
	i = 0;
	while (i < n)
	{
		
		i++;
	}
	return (NULL);
}

int		main(int argc, char **argv)
{
	t_dirent *de;
	DIR *dir;
	t_file *file_list;

	if (parse(argv + 1, argc - 1) == 0)
		return (EXIT_FAILURE);
	file_list = get_file_list();
	if (file_list == NULL)
		return (EXIT_FAILURE);
	dir = opendir(".");
	if (dir == NULL)
		ft_printf("Couldn't open directory\n");
	de = readdir(dir);
	while (de)
	{
		if (de->d_name[0] != '.')
			ft_printf("%s\n", de->d_name);
		de = readdir(dir);
	}
	return (EXIT_SUCCESS);
}
