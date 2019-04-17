/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 11:11:06 by tde-jong       #+#    #+#                */
/*   Updated: 2019/04/17 11:31:08 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_file	*reverse_lst(t_file *lst)
{
	t_file *a;
	t_file *b;
	t_file *c;

	a = NULL;
	b = lst;
	c = (lst)->next;
	while (b)
	{
		c = b->next;
		b->next = a;
		a = b;
		b = c;
	}
	return (a);
}

static t_file	*sort_ascii(t_file *lst)
{
	if (!lst)
		return (NULL);
	if (lst->next && ft_strcmp(lst->name, lst->next->name) > 0)
		lst = ft_lstswap(lst, lst->next);
	lst->next = sort_ascii(lst->next);
	if (lst->next && ft_strcmp(lst->name, lst->next->name) > 0)
	{
		lst = ft_lstswap(lst, lst->next);
		lst->next = sort_ascii(lst->next);
	}
	return (lst);
}

static t_file	*sort_time(t_file *lst)
{
	if (!lst)
		return (NULL);
	if (lst->next && (lst->time < lst->next->time))
		lst = ft_lstswap(lst, lst->next);
	else if (lst->next && lst->time == lst->next->time)
		if (lst->next && (lst->ntime < lst->next->ntime))
			lst = ft_lstswap(lst, lst->next);
	lst->next = sort_time(lst->next);
	if (lst->next && (lst->time < lst->next->time))
	{
		lst = ft_lstswap(lst, lst->next);
		lst->next = sort_time(lst->next);
	}
	else if (lst->next && lst->time == lst->next->time)
	{
		if (lst->next && (lst->ntime < lst->next->ntime))
		{
			lst = ft_lstswap(lst, lst->next);
			lst->next = sort_time(lst->next);
		}
	}
	return (lst);
}

static t_file	*sort_size(t_file *lst)
{
	if (!lst)
		return (NULL);
	if (lst->next && (lst->size < lst->next->size))
		lst = ft_lstswap(lst, lst->next);
	lst->next = sort_size(lst->next);
	if (lst->next && (lst->size < lst->next->size))
	{
		lst = ft_lstswap(lst, lst->next);
		lst->next = sort_size(lst->next);
	}
	return (lst);
}

void			sort(t_file **head)
{
	*head = sort_ascii(*head);
	if (g_options & OPT_T)
		*head = sort_time(*head);
	if (g_options & OPT_R)
		*head = reverse_lst(*head);
	if (g_options & OPT_S_UPP)
		*head = sort_size(*head);
}
