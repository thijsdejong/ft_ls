/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ctoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/16 12:18:34 by tde-jong       #+#    #+#                */
/*   Updated: 2019/04/16 12:19:13 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ctoa(int c)
{
	char	*str;

	str = ft_strnew(1);
	if (str == NULL)
		return (NULL);
	str[0] = c;
	return (str);
}
