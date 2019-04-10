/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ls.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 18:08:34 by tde-jong       #+#    #+#                */
/*   Updated: 2019/04/10 15:58:44 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <stdint.h>
# include <stddef.h>

# define OPTIONS "Ralrt"
# define OPT_R_UPP	(1 << 0)
# define OPT_A		(1 << 1)
# define OPT_L		(1 << 2)
# define OPT_R		(1 << 3)
# define OPT_T		(1 << 4)

uint8_t ls_options;

#endif
