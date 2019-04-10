/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ldtoa.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 15:03:09 by tde-jong       #+#    #+#                */
/*   Updated: 2019/04/01 11:33:45 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_ldtoa_solve(t_ldtoa *db)
{
	while (db->nb > 0 || db->prec || (db->multi >= db->divi && db->prec == 0))
	{
		db->multi++;
		if (db->multi > db->divi &&
			(db->divi = 999999) && db->prec > 0)
		{
			if (!db->i || db->ret[(db->i - 1)] == '-')
			{
				db->ret[db->i] = '0';
				db->i++;
			}
			db->ret[db->i] = '.';
			db->i++;
		}
		if (db->divi == 999999 &&
			(--(db->prec) < 0))
			break ;
		db->nb *= 10;
		db->ret[db->i] = ((int)db->nb) + '0';
		db->i++;
		db->nb -= (int)db->nb;
	}
}

static void	ft_ldtoa_round(t_ldtoa *db)
{
	if (((int)(db->nb * 10)) < 5)
		return ;
	db->i = (int)ft_strlen(db->ret);
	--db->i;
	while (db->ret[db->i])
	{
		if (db->ret[db->i] == '.')
			continue ;
		else if (db->ret[db->i] == '9')
			db->ret[db->i] = '0';
		else
			break ;
		--db->i;
	}
	db->ret[db->i] = ((db->ret[db->i] - '0') + 1) + '0';
}

char		*ft_ldtoa(long double nb, int prec)
{
	t_ldtoa		db;
	char		*ret;

	ft_bzero(&db, sizeof(t_ldtoa));
	if (
		!(db.ret = ft_strnew(2048)))
		return ((char *)NULL);
	if ((1 / nb) < 0 &&
		(db.isneg = 1))
	{
		db.ret[db.i] = '-';
		db.i++;
		nb *= -1;
	}
	db.save = nb;
	db.nb = nb;
	db.prec = prec;
	while (db.nb >= 1 &&
			++db.divi)
		db.nb /= 10;
	ft_ldtoa_solve(&db);
	ft_ldtoa_round(&db);
	ret = ft_strdup(db.ret);
	ft_strdel(&db.ret);
	return (ret);
}
