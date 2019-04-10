/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/21 14:20:25 by tde-jong       #+#    #+#                */
/*   Updated: 2019/04/01 10:52:13 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle(t_info *info)
{
	PF_OUTPUT = ft_strnew(0);
	if (PF_OUTPUT == NULL)
		return (RET_ZERO);
	if (ISON(C_PERCENT))
		handle_percent(info);
	else
	{
		if (!(ISON(C_F)))
			PF_ARG = va_arg(PF_ARGLIST, void*);
		ISON(C_S) ? handle_s(info) : 0;
		ISON(C_C) ? handle_c(info) : 0;
		ISON(C_P) ? handle_p(info) : 0;
		ISON(C_D) || ISON(C_I) ? handle_d_i(info) : 0;
		ISON(C_O) ? handle_o(info) : 0;
		ISON(C_U) ? handle_u(info) : 0;
		ISON(C_X) || ISON(C_X_UPP) ? handle_x(info) : 0;
		ISON(C_F) || ISON(C_F_UPP) ? handle_f(info) : 0;
	}
	free(PF_OUTPUT);
	return (RET_OK);
}

void	handle_s(t_info *info)
{
	if (PF_ARG == NULL)
		PF_OUTPUT = pf_strjoin(PF_OUTPUT, ft_strndup("(null)", PF_PRECISION));
	else
		PF_OUTPUT = pf_strjoin(PF_OUTPUT, ft_strndup((const char*)PF_ARG,
								PF_PRECISION));
	if (ISON(F_MINUS))
		PF_OUTPUT = pf_strjoin(PF_OUTPUT, get_spaces(info));
	else
		PF_OUTPUT = pf_strjoin(get_spaces(info), PF_OUTPUT);
	PF_RET += ft_strlen(PF_OUTPUT);
	ft_putstr(PF_OUTPUT);
}

void	handle_c(t_info *info)
{
	if ((int)PF_ARG == 0)
	{
		PF_OUTPUT = pf_strjoin(PF_OUTPUT, pf_ctoa(-1));
		PF_PRINT_ZERO = 1;
	}
	PF_OUTPUT = pf_strjoin(PF_OUTPUT, pf_ctoa((int)PF_ARG));
	if (ISON(F_MINUS))
		PF_OUTPUT = pf_strjoin(PF_OUTPUT, get_spaces(info));
	else
		PF_OUTPUT = pf_strjoin(get_spaces(info), PF_OUTPUT);
	PF_RET += ft_max(ft_strlen(PF_OUTPUT), 1);
	pf_putstr_zero(PF_OUTPUT, info);
}

void	handle_p(t_info *info)
{
	PF_OUTPUT = pf_strjoin(ft_strdup("0x"), PF_OUTPUT);
	if (PF_ARG == NULL)
		PF_OUTPUT = pf_strjoin(PF_OUTPUT, ft_strdup("0"));
	else
		PF_OUTPUT = pf_strjoin(PF_OUTPUT, pf_itoa_base((uintmax_t)PF_ARG, 16));
	if (ISON(F_MINUS))
		PF_OUTPUT = pf_strjoin(PF_OUTPUT, get_spaces(info));
	else
		PF_OUTPUT = pf_strjoin(get_spaces(info), PF_OUTPUT);
	PF_RET += ft_strlen(PF_OUTPUT);
	ft_putstr(PF_OUTPUT);
}

void	handle_percent(t_info *info)
{
	PF_OUTPUT = pf_strjoin(PF_OUTPUT, ft_strdup("%"));
	if (ISON(F_MINUS))
		PF_OUTPUT = pf_strjoin(PF_OUTPUT, get_spaces(info));
	else
		PF_OUTPUT = pf_strjoin(get_spaces(info), PF_OUTPUT);
	PF_RET += ft_strlen(PF_OUTPUT);
	ft_putstr(PF_OUTPUT);
}
