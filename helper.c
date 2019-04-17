/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helper.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/11 14:27:06 by tde-jong       #+#    #+#                */
/*   Updated: 2019/04/17 12:31:57 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_error(char *str, int e)
{
	if (e == USAGE)
		ft_dprintf(STDERR_FILENO, "ft_ls: illegal option -- %s\n"
				"usage: ft_ls [-%s] [file ...]\n", str, OPTIONS);
	else if (e == ERRNO)
		ft_dprintf(STDERR_FILENO, "ft_ls: %s: %s\n", str, strerror(errno));
	else if (e == MALLOC_ERROR)
		ft_dprintf(STDERR_FILENO, "ft_ls: %s\n", strerror(errno));
}

t_file	*ft_lstswap(t_file *lst1, t_file *lst2)
{
	lst1->next = lst2->next;
	lst2->next = lst1;
	return (lst2);
}

void	free_lst(t_file **lst)
{
	while (*lst)
	{
		free((*lst)->name);
		free(*lst);
		*lst = (*lst)->next;
	}
}
