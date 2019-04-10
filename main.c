/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 18:08:31 by tde-jong       #+#    #+#                */
/*   Updated: 2019/04/10 16:04:01 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_invalid_option(char c)
{
	ft_dprintf(STDERR_FILENO, "ft_ls: illegal option -- %c\n"
				"usage: ft_ls [-%s] [file ...]\n", c, OPTIONS);
}

int		set_option(uint8_t *options, char opt)
{
	int	i;

	i = ft_isin(opt, OPTIONS);
	if (i < 0)
		return (0);
	*options |= (1 << i);
	return (1);
}

int		handle_option(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		if (!set_option(&ls_options, str[i]))
		{
			print_invalid_option(str[i]);
			return (0);
		}
		i++;
	}
	return (1);
}

int		parse(char **arguments, int limit)
{
	int i;
	int	stage;

	i = 0;
	stage = 1;
	while (i < limit)
	{
		if (stage == 1 && ft_strnequ("-", arguments[i], 1) && arguments[i][1])
		{
			handle_option(arguments[i] + 1);
		}
		else
		{
			stage = 2;
			ft_printf("stage2\n");
		}
		i++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc > 1)
		parse(argv + 1, argc - 1);
	if (ls_options & OPT_R_UPP)
		ft_printf("R is on!\n");
	if (ls_options & OPT_A)
		ft_printf("a is on!\n");
	if (ls_options & OPT_L)
		ft_printf("l is on!\n");
	if (ls_options & OPT_R)
		ft_printf("r is on!\n");
	if (ls_options & OPT_T)
		ft_printf("t is on!\n");
	return (0);
}
