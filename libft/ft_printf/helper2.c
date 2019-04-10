/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helper2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 15:50:05 by tde-jong       #+#    #+#                */
/*   Updated: 2019/03/30 15:50:13 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

int		ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

char	*ft_strndup(const char *s1, size_t n)
{
	int		len;
	char	*str;

	len = ft_min(ft_strlen(s1), n);
	str = (char *)ft_memalloc(len + 1);
	if (str == NULL)
		return (NULL);
	ft_strncpy(str, s1, len);
	return (str);
}
