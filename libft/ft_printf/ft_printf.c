/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/14 10:49:54 by tde-jong       #+#    #+#                */
/*   Updated: 2019/04/10 15:33:15 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	t_info	*info;

	info = (t_info*)ft_memalloc(sizeof(t_info));
	if (info == NULL)
		return (RET_ERROR);
	PF_FD = 1;
	va_start(PF_ARGLIST, format);
	pf_parse_format(info, format);
	free(info);
	va_end(PF_ARGLIST);
	return (PF_RET);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	t_info	*info;

	info = (t_info*)ft_memalloc(sizeof(t_info));
	if (info == NULL)
		return (RET_ERROR);
	PF_FD = fd;
	va_start(PF_ARGLIST, format);
	pf_parse_format(info, format);
	free(info);
	va_end(PF_ARGLIST);
	return (PF_RET);
}
