/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   time.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/29 10:21:46 by tde-jong       #+#    #+#                */
/*   Updated: 2019/04/29 11:18:55 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*display_year(char *long_time)
{
	char	*shorter_time;
	char	*ptr;
	char	*year;

	shorter_time = (char*)ft_memalloc(sizeof(char) * 12);
	if (shorter_time == NULL)
		print_error("", MALLOC_ERROR);
	ptr = long_time + 4;
	ptr[20] = '\0';
	year = ft_strdup(ptr + 15);
	shorter_time = ft_strncpy(shorter_time, ptr, 7);
	shorter_time[7] = '\0';
	ptr = shorter_time;
	shorter_time = ft_strjoin(shorter_time, year);
	free(ptr);
	return (shorter_time);
}

int			check_6_months(t_file *file)
{
	time_t	today;

	today = time(NULL);
	if (today - file->time >= 15778800)
		return (1);
	if (today - file->time <= -15778800)
		return (1);
	return (0);
}

char		*keep_necessary_timedata(char *long_time)
{
	char	*shorter_time;
	char	*ptr;

	shorter_time = (char*)ft_memalloc(sizeof(char) * 13);
	if (shorter_time == NULL)
		print_error("", MALLOC_ERROR);
	ptr = long_time + 4;
	shorter_time = ft_strncpy(shorter_time, ptr, 12);
	shorter_time[12] = '\0';
	return (shorter_time);
}

char		*get_date(t_file *file)
{
	char	*date;

	if (check_6_months(file))
		date = display_year(ctime(&file->time));
	else
		date = keep_necessary_timedata(ctime(&file->time));
	return (date);
}
