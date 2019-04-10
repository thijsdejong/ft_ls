/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle1.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/01 10:50:18 by tde-jong       #+#    #+#                */
/*   Updated: 2019/04/10 15:36:50 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_d_i_arg(t_info *info)
{
	if (PF_ARG == NULL)
		PF_OUTPUT = pf_strjoin(PF_OUTPUT, ft_strndup("0", PF_PRECISION));
	else if (ISON(MOD_HH))
		PF_OUTPUT = pf_strjoin(PF_OUTPUT, pf_itoa((signed char)PF_ARG));
	else if (ISON(MOD_H))
		PF_OUTPUT = pf_strjoin(PF_OUTPUT, pf_itoa((short)PF_ARG));
	else if (ISON(MOD_L))
		PF_OUTPUT = pf_strjoin(PF_OUTPUT, pf_itoa((long)PF_ARG));
	else if (ISON(MOD_LL))
		PF_OUTPUT = pf_strjoin(PF_OUTPUT, pf_itoa((long long)PF_ARG));
	else if (ISON(MOD_J))
		PF_OUTPUT = pf_strjoin(PF_OUTPUT, pf_itoa((intmax_t)PF_ARG));
	else if (ISON(MOD_Z))
		PF_OUTPUT = pf_strjoin(PF_OUTPUT, pf_itoa((ssize_t)PF_ARG));
	else
		PF_OUTPUT = pf_strjoin(PF_OUTPUT, pf_itoa((int)PF_ARG));
}

void		pf_handle_d_i(t_info *info)
{
	handle_d_i_arg(info);
	if (ft_isin('-', PF_OUTPUT) != -1)
		PF_NEGATIVE = 1;
	PF_OUTPUT = pf_strjoin_nb(pf_get_precision(info), PF_OUTPUT, info);
	if (ISON(F_PLUS) && (int)PF_ARG >= 0)
		PF_OUTPUT = pf_strjoin(ft_strdup("+"), PF_OUTPUT);
	else if (ISON(F_SPACE) && ((int)PF_ARG >= 0 || PF_ARG == NULL))
		PF_OUTPUT = pf_strjoin(ft_strdup(" "), PF_OUTPUT);
	if (PF_NEGATIVE && ft_isin('-', PF_OUTPUT) == -1)
		PF_OUTPUT = pf_strjoin(ft_strdup("-"), PF_OUTPUT);
	if (ISON(F_MINUS))
		PF_OUTPUT = pf_strjoin(PF_OUTPUT, pf_get_spaces(info));
	else
		PF_OUTPUT = pf_strjoin(pf_get_spaces(info), PF_OUTPUT);
	PF_RET += ft_strlen(PF_OUTPUT);
	ft_putstr_fd(PF_OUTPUT, PF_FD);
}

static void	handle_o_arg(t_info *info)
{
	if (PF_ARG == NULL && !(ISON(F_HASH)))
		PF_OUTPUT = pf_strjoin(PF_OUTPUT, ft_strndup("0", PF_PRECISION));
	if (ISON(MOD_HH) && PF_ARG)
		PF_OUTPUT = pf_strjoin(PF_OUTPUT,
								pf_itoa_base((unsigned char)PF_ARG, 8));
	else if (ISON(MOD_H) && PF_ARG)
		PF_OUTPUT = pf_strjoin(PF_OUTPUT,
								pf_itoa_base((unsigned short)PF_ARG, 8));
	else if (ISON(MOD_L) && PF_ARG)
		PF_OUTPUT = pf_strjoin(PF_OUTPUT,
								pf_itoa_base((unsigned long)PF_ARG, 8));
	else if (ISON(MOD_LL) && PF_ARG)
		PF_OUTPUT = pf_strjoin(PF_OUTPUT,
								pf_itoa_base((unsigned long long)PF_ARG, 8));
	else if (ISON(MOD_J) && PF_ARG)
		PF_OUTPUT = pf_strjoin(PF_OUTPUT,
								pf_itoa_base((uintmax_t)PF_ARG, 8));
	else if (ISON(MOD_Z) && PF_ARG)
		PF_OUTPUT = pf_strjoin(PF_OUTPUT, pf_itoa_base((size_t)PF_ARG, 8));
	else if (PF_ARG)
		PF_OUTPUT = pf_strjoin(PF_OUTPUT,
								pf_itoa_base((unsigned int)PF_ARG, 8));
}

void		pf_handle_o(t_info *info)
{
	handle_o_arg(info);
	if (PF_PRECISION > 0 && PF_PRECISION != 2147483647)
		PF_OUTPUT = pf_strjoin(pf_get_precision(info), PF_OUTPUT);
	if (ISON(F_HASH))
		PF_OUTPUT = pf_strjoin(ft_strdup("0"), PF_OUTPUT);
	if (ISON(F_MINUS))
		PF_OUTPUT = pf_strjoin(PF_OUTPUT, pf_get_spaces(info));
	else
		PF_OUTPUT = pf_strjoin(pf_get_spaces(info), PF_OUTPUT);
	PF_RET += ft_strlen(PF_OUTPUT);
	ft_putstr_fd(PF_OUTPUT, PF_FD);
}

void		pf_handle_f(t_info *info)
{
	if (PF_PRECISION < 0 || PF_PRECISION == 2147483647)
		PF_PRECISION = 6;
	if (ISON(MOD_L_UPP))
		PF_OUTPUT = pf_strjoin(PF_OUTPUT,
					ft_ldtoa(va_arg(PF_ARGLIST, long double), PF_PRECISION));
	else
		PF_OUTPUT = pf_strjoin(PF_OUTPUT,
					ft_ldtoa(va_arg(PF_ARGLIST, double), PF_PRECISION));
	if (ISON(F_PLUS) && ft_isin('-', PF_OUTPUT) == -1)
		PF_OUTPUT = pf_strjoin(ft_strdup("+"), PF_OUTPUT);
	else if (ISON(F_SPACE) && ft_isin('-', PF_OUTPUT) == -1)
		PF_OUTPUT = pf_strjoin(ft_strdup(" "), PF_OUTPUT);
	if (ISON(F_MINUS))
		PF_OUTPUT = pf_strjoin(PF_OUTPUT, pf_get_spaces(info));
	else
		PF_OUTPUT = pf_strjoin(pf_get_spaces(info), PF_OUTPUT);
	PF_RET += ft_strlen(PF_OUTPUT);
	ft_putstr_fd(PF_OUTPUT, PF_FD);
}
