/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 18:08:31 by tde-jong       #+#    #+#                */
/*   Updated: 2019/04/17 14:09:03 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	*get_file_list(char **filenames, int n, bool first)
{
	t_file	*head;
	int		i;

	head = NULL;
	if (n == 0)
		add_file("", ".", &head);
	else
		;
	i = 0;
	while (i < n)
	{
		if (add_file("", filenames[i], &head) == -1 && first == true)
			print_error(filenames[i], ERRNO);
		i++;
	}
	return (head);
}

int		main(int argc, char **argv)
{
	t_file		*file_list;
	int			offset;

	offset = parse(argv + 1, argc - 1, &file_list);
	if (offset == -1)
		return (EXIT_FAILURE);
	file_list = get_file_list(argv + 1 + offset, argc - 1 - offset, true);
	if (file_list == NULL)
		return (EXIT_FAILURE);
	display(file_list, argc - 1 - offset, true);
	free_lst(&file_list);
	while (1);
	return (EXIT_SUCCESS);
}
