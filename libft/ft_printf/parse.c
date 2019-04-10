/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/20 12:09:23 by tde-jong       #+#    #+#                */
/*   Updated: 2019/03/30 13:39:59 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			parse(t_info *info, const char **format)
{
	while (parse_get_flags(info, **format))
		(*format)++;
	parse_get_width(info, format);
	parse_get_width(info, format);
	PF_PRECISION = 2147483647;
	parse_get_precision(info, format);
	if (PF_PRECISION < 0)
		PF_PRECISION = 2147483647;
	parse_get_mod(info, format);
	if (parse_get_conv(info, **format))
	{
		if (PF_PRECISION < 0 && !(ISON(C_F)))
			PF_PRECISION = 0;
		(ISON(C_D_UPP) || ISON(C_O_UPP) || ISON(C_U_UPP)) ? ENABLE(MOD_L) : 0;
		(ISON(C_D_UPP)) ? ENABLE(C_D) : 0;
		(ISON(C_O_UPP)) ? ENABLE(C_O) : 0;
		(ISON(C_U_UPP)) ? ENABLE(C_U) : 0;
		return (RET_OK);
	}
	else
		return (RET_ZERO);
}

void		pf_parse_format(t_info *info, const char *format)
{
	while (*format)
	{
		if (*format == '{' && handle_color(info, &format))
			continue;
		if (*format == '%')
		{
			PF_ATTR = (t_attr*)ft_memalloc(sizeof(t_attr));
			format++;
			if (PF_ATTR && parse(info, &format) && handle(info))
				free(PF_ATTR);
			else
			{
				free(PF_ATTR);
				continue ;
			}
		}
		else
		{
			ft_putchar(*format);
			PF_RET += 1;
		}
		format++;
	}
}
