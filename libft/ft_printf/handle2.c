/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/01 10:50:36 by tde-jong       #+#    #+#                */
/*   Updated: 2019/04/10 14:39:03 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_u_arg(t_info *info)
{
	if (PF_ARG == NULL)
		PF_OUTPUT = pf_strjoin(PF_OUTPUT, ft_strndup("0", PF_PRECISION));
	if (ISON(MOD_HH) && PF_ARG)
		PF_OUTPUT = pf_strjoin(PF_OUTPUT,
								pf_itoa_base((unsigned char)PF_ARG, 10));
	else if (ISON(MOD_H) && PF_ARG)
		PF_OUTPUT = pf_strjoin(PF_OUTPUT,
								pf_itoa_base((unsigned short)PF_ARG, 10));
	else if (ISON(MOD_L) && PF_ARG)
		PF_OUTPUT = pf_strjoin(PF_OUTPUT,
								pf_itoa_base((unsigned long)PF_ARG, 10));
	else if (ISON(MOD_LL) && PF_ARG)
		PF_OUTPUT = pf_strjoin(PF_OUTPUT,
								pf_itoa_base((unsigned long long)PF_ARG, 10));
	else if (ISON(MOD_J) && PF_ARG)
		PF_OUTPUT = pf_strjoin(PF_OUTPUT,
								pf_itoa_base((uintmax_t)PF_ARG, 10));
	else if (ISON(MOD_Z) && PF_ARG)
		PF_OUTPUT = pf_strjoin(PF_OUTPUT,
								pf_itoa_base((size_t)PF_ARG, 10));
	else if (PF_ARG)
		PF_OUTPUT = pf_strjoin(PF_OUTPUT,
								pf_itoa_base((unsigned int)PF_ARG, 10));
}

void		pf_handle_u(t_info *info)
{
	handle_u_arg(info);
	if (PF_PRECISION > 0 && PF_PRECISION != 2147483647)
		PF_OUTPUT = pf_strjoin(get_precision(info), PF_OUTPUT);
	if (ISON(F_MINUS))
		PF_OUTPUT = pf_strjoin(PF_OUTPUT, get_spaces(info));
	else
		PF_OUTPUT = pf_strjoin(get_spaces(info), PF_OUTPUT);
	PF_RET += ft_strlen(PF_OUTPUT);
	ft_putstr(PF_OUTPUT);
}

static void	handle_x_arg(t_info *info)
{
	if (PF_ARG == NULL)
		PF_OUTPUT = pf_strjoin(PF_OUTPUT, ft_strndup("0", PF_PRECISION));
	if (ISON(MOD_HH) && PF_ARG)
		PF_OUTPUT = pf_strjoin(PF_OUTPUT,
								pf_itoa_base((unsigned char)PF_ARG, 16));
	else if (ISON(MOD_H) && PF_ARG)
		PF_OUTPUT = pf_strjoin(PF_OUTPUT,
								pf_itoa_base((unsigned short)PF_ARG, 16));
	else if (ISON(MOD_L) && PF_ARG)
		PF_OUTPUT = pf_strjoin(PF_OUTPUT,
								pf_itoa_base((unsigned long)PF_ARG, 16));
	else if (ISON(MOD_LL) && PF_ARG)
		PF_OUTPUT = pf_strjoin(PF_OUTPUT,
								pf_itoa_base((unsigned long long)PF_ARG, 16));
	else if (ISON(MOD_J) && PF_ARG)
		PF_OUTPUT = pf_strjoin(PF_OUTPUT, pf_itoa_base((uintmax_t)PF_ARG, 16));
	else if (ISON(MOD_Z) && PF_ARG)
		PF_OUTPUT = pf_strjoin(PF_OUTPUT, pf_itoa_base((size_t)PF_ARG, 16));
	else if (PF_ARG)
		PF_OUTPUT = pf_strjoin(PF_OUTPUT,
								pf_itoa_base((unsigned int)PF_ARG, 16));
}

void		pf_handle_x(t_info *info)
{
	handle_x_arg(info);
	if (PF_PRECISION > 0 && PF_PRECISION != 2147483647)
		PF_OUTPUT = pf_strjoin(get_precision(info), PF_OUTPUT);
	if (ISON(F_HASH) && !(ISON(F_ZERO)) && PF_ARG)
		PF_OUTPUT = pf_strjoin(ft_strdup("0x"), PF_OUTPUT);
	if (ISON(F_MINUS))
		PF_OUTPUT = pf_strjoin(PF_OUTPUT, get_spaces(info));
	else
		PF_OUTPUT = pf_strjoin(get_spaces(info), PF_OUTPUT);
	if (ISON(F_HASH) && ISON(F_ZERO) && PF_ARG)
		PF_OUTPUT = pf_strjoin(ft_strdup("0x"), PF_OUTPUT);
	PF_RET += ft_strlen(PF_OUTPUT);
	(ISON(C_X_UPP)) ? ft_strtoupper(PF_OUTPUT) : 0;
	ft_putstr(PF_OUTPUT);
}
