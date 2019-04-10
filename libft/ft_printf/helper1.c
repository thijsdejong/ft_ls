/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helper1.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 15:49:06 by tde-jong       #+#    #+#                */
/*   Updated: 2019/04/10 15:38:15 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_itoa_base(uintmax_t n, unsigned char base)
{
	char	*str;
	char	*base_string;
	int		len;

	base_string = "0123456789abcdef";
	if (n == 0)
		return (ft_strdup("0"));
	len = ft_intlen_base_uintmax(n, base);
	str = ft_memalloc(len + 1);
	if (str == NULL)
		return (NULL);
	while (n)
	{
		len--;
		str[len] = base_string[n % base];
		n /= base;
	}
	return (str);
}

char	*pf_itoa(intmax_t n)
{
	char	*str;
	int		len;
	int		i;

	if (n == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	i = 0;
	len = ft_intlen(n);
	str = ft_memalloc(len + 1);
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
		i += 1;
	}
	while (i < len)
	{
		len--;
		str[len] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

void	pf_putstr_precision(char *str, t_info *info)
{
	int i;

	if (PF_PRECISION == 0)
		ft_putchar_fd(0, PF_FD);
	else
	{
		i = 0;
		while (str[i] && i < PF_PRECISION)
		{
			ft_putchar_fd(str[i], PF_FD);
			i++;
		}
	}
}

void	pf_putstr_zero(char const *s, t_info *info)
{
	int i;

	if (s)
	{
		i = 0;
		while (s[i] != '\0')
		{
			if (s[i] == -1 && PF_PRINT_ZERO)
				ft_putchar_fd(0, PF_FD);
			else
				ft_putchar_fd(s[i], PF_FD);
			i++;
		}
	}
}
