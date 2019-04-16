/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ls.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tde-jong <tde-jong@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 18:08:34 by tde-jong       #+#    #+#                */
/*   Updated: 2019/04/16 16:11:33 by tde-jong      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <stdint.h>
# include <stddef.h>
# include <limits.h>
# include <errno.h>
# include <dirent.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <time.h>
# include <sys/acl.h>
# include <sys/xattr.h>
# include <sys/ioctl.h>

# define OPTIONS "Ralrt"
# define OPT_R_UPP	(1 << 0)
# define OPT_A		(1 << 1)
# define OPT_L		(1 << 2)
# define OPT_R		(1 << 3)
# define OPT_T		(1 << 4)

enum
{
	USAGE,
	ERRNO,
	MALLOC_ERROR
}	e_errors;

typedef struct stat		t_stat;
typedef struct dirent	t_dirent;
typedef struct passwd	t_passwd;
typedef struct group	t_group;


typedef struct			s_file
{
	blkcnt_t			st_blocks;
	mode_t				mode;
	nlink_t				st_nlink;
	uid_t				st_uid;
	gid_t				st_gid;
	off_t				size;
	dev_t				st_rdev;
	time_t				time;
	long				ntime;
	char				*name;
	char				full_path[PATH_MAX];
	struct s_file		*next;
	t_list				list;
}						t_file;

uint8_t g_options;

/*
** ADD_FILE.C
*/

int						add_file(char path[PATH_MAX], char *name,
									t_file **head);

/*
** OPTIONS.C
*/

int						handle_option(char *str);

/*
** PARSE.C
*/

int						parse(char **arguments, int limit, t_file **file_list);

/*
** HELPER.C
*/

void					print_error(char *str, int e);

#endif
