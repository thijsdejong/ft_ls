/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strndup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/10 14:40:06 by tde-jong       #+#    #+#                */
/*   Updated: 2019/04/10 14:40:30 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
