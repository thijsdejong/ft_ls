/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/20 12:09:23 by tde-jong       #+#    #+#                */
/*   Updated: 2019/04/10 14:49:26 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			pf_parse(t_info *info, const char **format)
{
	while (pf_parse_get_flags(info, **format))
		(*format)++;
	pf_parse_get_width(info, format);
	pf_parse_get_width(info, format);
	PF_PRECISION = 2147483647;
	pf_parse_get_precision(info, format);
	if (PF_PRECISION < 0)
		PF_PRECISION = 2147483647;
	pf_parse_get_mod(info, format);
	if (pf_parse_get_conv(info, **format))
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
		if (*format == '{' && pf_handle_color(info, &format))
			continue;
		if (*format == '%')
		{
			PF_ATTR = (t_attr*)ft_memalloc(sizeof(t_attr));
			format++;
			if (PF_ATTR && pf_parse(info, &format) && pf_handle(info))
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
