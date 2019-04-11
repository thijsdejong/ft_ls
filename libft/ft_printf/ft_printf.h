/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/14 10:50:08 by tde-jong       #+#    #+#                */
/*   Updated: 2019/04/11 08:46:40 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** -------------------------- Headers ------------------------------------------
*/

# include "../libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>

/*
** -------------------------- Flags and Conversions ----------------------------
** Adjust MODIFIERS_CNT manually
*/

# define FLAGS			"#0-+ "
# define FLAGS_CNT		5
# define FLAGS_START	0
# define FLAGS_END		FLAGS_START + FLAGS_CNT

# define MODIFIERS		"hlLjz"
# define MODIFIERS_CNT	7
# define MOD_START		FLAGS_END
# define MOD_END		MOD_START + MODIFIERS_CNT

# define CONVERSIONS	"cspdDioOuUxXfF%"
# define CONV_CNT		15
# define CONV_START		MOD_END
# define CONV_END		CONV_START + CONV_CNT

# define PRECISION		"$*."
# define PREC_CNT		3
# define PREC_START		CONV_END
# define PREC_END		PREC_START + PREC_CNT

# define F_HASH		(1 << (FLAGS_START + 0))
# define F_ZERO		(1 << (FLAGS_START + 1))
# define F_MINUS	(1 << (FLAGS_START + 2))
# define F_PLUS		(1 << (FLAGS_START + 3))
# define F_SPACE	(1 << (FLAGS_START + 4))
# define MOD_HH		(1 << (MOD_START + 0))
# define MOD_H		(1 << (MOD_START + 1))
# define MOD_L		(1 << (MOD_START + 2))
# define MOD_L_UPP	(1 << (MOD_START + 3))
# define MOD_LL		(1 << (MOD_START + 4))
# define MOD_J		(1 << (MOD_START + 5))
# define MOD_Z		(1 << (MOD_START + 6))
# define C_C		(1 << (CONV_START + 0))
# define C_S		(1 << (CONV_START + 1))
# define C_P		(1 << (CONV_START + 2))
# define C_D		(1 << (CONV_START + 3))
# define C_D_UPP	(1 << (CONV_START + 4))
# define C_I		(1 << (CONV_START + 5))
# define C_O		(1 << (CONV_START + 6))
# define C_O_UPP	(1 << (CONV_START + 7))
# define C_U		(1 << (CONV_START + 8))
# define C_U_UPP	(1 << (CONV_START + 9))
# define C_X		(1 << (CONV_START + 10))
# define C_X_UPP	(1 << (CONV_START + 11))
# define C_F		(1 << (CONV_START + 12))
# define C_F_UPP	(1 << (CONV_START + 13))
# define C_PERCENT	(1 << (CONV_START + 14))
# define PREC_DOL	(1 << (PREC_START + 0))
# define PREC_WILD	(1 << (PREC_START + 1))
# define PREC_DOT	(1 << (PREC_START + 2))

# define O_END		(1 << (PREC_END + 1))

/*
** -------------------------- Structures ---------------------------------------
*/

typedef	struct		s_attr
{
	uint32_t	options;
	int			width;
	int			precision;
	int			len;
	char		*output;
	int			print_zero;
	int			neg;
}					t_attr;

typedef	struct		s_info
{
	t_attr		*attr;
	va_list		arglist;
	void		*arg;
	void		*temp;
	int			tempint;
	int			ret;
	int			fd;
}					t_info;

/*
** -------------------------- Defines ------------------------------------------
*/
# define PF_ATTR		info->attr
# define PF_OPT			PF_ATTR->options
# define PF_WIDTH		PF_ATTR->width
# define PF_PRECISION	PF_ATTR->precision
# define PF_ATTRLEN		PF_ATTR->len
# define PF_OUTPUT		PF_ATTR->output
# define PF_PRINT_ZERO	PF_ATTR->print_zero
# define PF_NEGATIVE	PF_ATTR->neg
# define PF_RET			info->ret
# define PF_ARGLIST		info->arglist
# define PF_ARG			info->arg
# define PF_TEMP		info->temp
# define PF_FD			info->fd

# define RET_ERROR	-1
# define RET_ZERO	0
# define RET_OK		1

/*
** -------------------------- Colors -------------------------------------------
*/

# define PF_COL_BLACK	"\e[30m"
# define PF_COL_RED		"\e[31m"
# define PF_COL_GREEN	"\e[32m"
# define PF_COL_YELLOW	"\e[33m"
# define PF_COL_BLUE	"\e[34m"
# define PF_COL_MAGENTA	"\e[35m"
# define PF_COL_CYAN	"\e[36m"
# define PF_COL_WHITE	"\e[37m"
# define PF_COL_END		"\e[0m"

/*
** -------------------------- Function Prototypes ------------------------------
*/

int					ft_printf(const char *format, ...);
int					ft_dprintf(int fd, const char *format, ...);

/*
** -------------------------- Parsing ------------------------------
*/

int					pf_parse(t_info *info, const char **format);
void				pf_parse_format(t_info *info, const char *format);
int					pf_parse_get_flags(t_info *info, char f);
void				pf_parse_get_width(t_info *info, const char **format);
void				pf_parse_get_precision(t_info *info, const char **format);
void				pf_parse_get_mod(t_info *info, const char **format);
int					pf_parse_get_conv(t_info *info, char c);

/*
** -------------------------- Handling ----------------------------
*/

int					pf_handle(t_info *info);
int					pf_handle_color(t_info *info, const char **format);
void				pf_handle_s(t_info *info);
void				pf_handle_c(t_info *info);
void				pf_handle_p(t_info *info);
void				pf_handle_percent(t_info *info);
void				pf_handle_d_i(t_info *info);
void				pf_handle_o(t_info *info);
void				pf_handle_f(t_info *info);
void				pf_handle_u(t_info *info);
void				pf_handle_x(t_info *info);

/*
** -------------------------- Helper ------------------------------
*/

char				*pf_strjoin(char *s1, char *s2);
char				*pf_strjoin_nb(char *s1, char *s2, t_info *info);
char				*pf_get_precision(t_info *info);
char				*pf_get_spaces(t_info *info);
char				*pf_itoa(intmax_t n);
char				*pf_ctoa(int c);
char				*pf_itoa_base(uintmax_t n, unsigned char base);
char				*pf_sitoa_base(intmax_t n, unsigned char base);
void				pf_putnbr_ull(unsigned long long int n);
void				pf_putstr_precision(char *str, t_info *info);
int					ft_min(int a, int b);
int					ft_max(int a, int b);
void				pf_putstr_zero(char const *s, t_info *info);

#endif
