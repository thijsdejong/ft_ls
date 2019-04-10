/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   valid.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/22 12:54:19 by tde-jong       #+#    #+#                */
/*   Updated: 2019/02/22 13:13:03 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_is_flag(const char c)
{
	return (ft_strchr(FLAGS, c) != NULL);
}

int	pf_is_mod(const char c)
{
	return (ft_strchr(MODIFIERS, c) != NULL);
}

int	pf_is_conv(const char c)
{
	return (ft_strchr(CONVERSIONS, c) != NULL);
}

int	pf_is_precision(const char c)
{
	return (ft_strchr(PRECISION, c) != NULL);
}

int	pf_is_valid(const char c)
{
	return (pf_is_flag(c) || pf_is_mod(c) || pf_is_conv(c) || ft_isdigit(c) ||
			pf_is_precision(c));
}
