/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helper.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 16:13:20 by tde-jong       #+#    #+#                */
/*   Updated: 2019/04/10 14:39:13 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_strjoin(char *s1, char *s2)
{
	char *str;

	str = ft_strjoin(s1, s2);
	if (str == NULL)
		return (NULL);
	free(s1);
	free(s2);
	return (str);
}

char	*pf_strjoin_nb(char *s1, char *s2, t_info *info)
{
	char *str;

	str = ft_strjoin(s1, s2 + PF_NEGATIVE);
	if (str == NULL)
		return (NULL);
	free(s1);
	free(s2);
	return (str);
}

char	*pf_get_precision(t_info *info)
{
	ssize_t count;
	char	*str;

	count = 0;
	if (ISON(F_ZERO) && !(ISON(F_MINUS)) && (PF_PRECISION == 0 ||
		PF_PRECISION == 2147483647))
	{
		if (ISON(F_PLUS) && !PF_NEGATIVE)
			PF_WIDTH -= 1;
		count = PF_WIDTH - ft_strlen(PF_OUTPUT);
	}
	else if (PF_PRECISION != 2147483647)
		count = PF_PRECISION - ft_strlen(PF_OUTPUT) + PF_NEGATIVE;
	if (ISON(F_SPACE) && !(ISON(F_PLUS)) && PF_PRECISION == 2147483647)
		count -= 1;
	if (count > 0)
	{
		str = ft_strnew(count);
		if (str)
			ft_memset(str, '0', count);
		return (str);
	}
	else
		return (ft_strnew(0));
}

char	*get_spaces(t_info *info)
{
	ssize_t count;
	char	*str;

	count = PF_WIDTH - ft_strlen(PF_OUTPUT);
	if (ISON(C_X) && ISON(F_HASH) && ISON(F_ZERO) && PF_ARG)
		count -= 2;
	if (count > 0)
	{
		str = ft_strnew(count);
		if (str && ISON(F_ZERO) && ((((ISON(C_D) || ISON(C_I)) &&
			PF_WIDTH <= PF_PRECISION)) || ISON(C_O) || ISON(C_U) ||
			ISON(C_X) || ISON(C_X_UPP) || ISON(C_F)) && ((PF_PRECISION == 0
			|| PF_PRECISION == 2147483647) || ISON(C_F)) && !(ISON(F_MINUS)))
			ft_memset(str, '0', count);
		else if (str)
			ft_memset(str, ' ', count);
		return (str);
	}
	else
		return (ft_strnew(0));
}

char	*pf_ctoa(int c)
{
	char	*str;

	str = ft_strnew(1);
	if (str == NULL)
		return (NULL);
	str[0] = c;
	return (str);
}
