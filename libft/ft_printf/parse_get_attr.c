/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_get_attr.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/25 15:04:09 by tde-jong       #+#    #+#                */
/*   Updated: 2019/03/29 10:02:22 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_get_flags(t_info *info, char f)
{
	ssize_t	flags;

	flags = ft_isin(f, FLAGS);
	if (flags != -1)
	{
		ENABLE((1 << (FLAGS_START + flags)));
		return (1);
	}
	return (0);
}

void	parse_get_width(t_info *info, const char **format)
{
	int	len;

	if (**format == '*')
	{
		PF_WIDTH = va_arg(PF_ARGLIST, int);
		if (PF_WIDTH < 0)
		{
			PF_WIDTH *= -1;
			ENABLE(F_MINUS);
		}
		(*format)++;
	}
	else
	{
		len = 0;
		while (ft_isdigit(*(*format + len)))
			len += 1;
		if (len != 0)
		{
			PF_TEMP = ft_strsub(*format, 0, (size_t)len);
			PF_WIDTH = ft_atoi(PF_TEMP);
			free(PF_TEMP);
			*format += len;
		}
	}
}

void	parse_get_precision(t_info *info, const char **format)
{
	int	len;

	if (**format == '.')
	{
		PF_PRECISION = 0;
		(*format)++;
		if (**format == '*')
		{
			PF_PRECISION = va_arg(PF_ARGLIST, int);
			(*format)++;
		}
		else
		{
			len = 0;
			while (ft_isdigit(*(*format + len)))
				len += 1;
			if (len != 0)
			{
				PF_TEMP = ft_strsub(*format, 0, (size_t)len);
				PF_PRECISION = ft_atoi(PF_TEMP);
				free(PF_TEMP);
				*format += len;
			}
		}
	}
}

void	parse_get_mod(t_info *info, const char **format)
{
	if (ft_isin(**format, MODIFIERS) != -1)
	{
		if (**format == 'h')
			*(*format + 1) == 'h' ? ENABLE(MOD_HH) : (ENABLE(MOD_H));
		else if (**format == 'l')
			*(*format + 1) == 'l' ? ENABLE(MOD_LL) : (ENABLE(MOD_L));
		else if (**format == 'L')
			ENABLE(MOD_L_UPP);
		else if (**format == 'j')
			ENABLE(MOD_J);
		else if (**format == 'z')
			ENABLE(MOD_Z);
		if (ISON(MOD_LL) || ISON(MOD_HH))
			*format += 1;
		*format += 1;
	}
}

int		parse_get_conv(t_info *info, char c)
{
	ssize_t	conv;

	conv = ft_isin(c, CONVERSIONS);
	if (conv != -1)
	{
		ENABLE((1 << (CONV_START + conv)));
		return (1);
	}
	return (0);
}
