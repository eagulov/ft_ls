/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 16:51:01 by eagulov           #+#    #+#             */
/*   Updated: 2019/09/03 13:56:55 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "ft_printf/ft_printf.h"
# include <sys/stat.h>
# include <sys/types.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <sys/xattr.h>
# include <sys/ioctl.h>
# include <sys/acl.h>

typedef struct	s_ls_flags {
	bool				l;
	bool				a;
	bool				r;
	bool				t;
	bool				cr;
}				t_ls_flags;

typedef struct	s_file_info {
	struct timespec		tspec;
	char				*name;
	char				*path;
	struct stat			filestat;
}				t_file_info;

typedef struct	s_ls_list {
	struct s_list_node	*top;
	int					cap;
}				t_ls_list;

typedef struct	s_list_node {
	struct s_file_info	*file_info;
	struct s_list_node	*next;
}				t_list_node;

int				arg_parsing(char **argv);
t_file_info		*set_list(char *name, char *path);
t_ls_list		*split_list(char **argv, int flag_end);
void			ls_push_list(t_ls_list *pathlist, t_file_info *infolist);
t_ls_list		*initlist(t_list_node *node);
t_file_info		*ls_pop_list(t_ls_list *pathlist);
t_list_node		*new_node(t_file_info *infolist);
void			print_list(t_ls_list *list, char *title);
void			print_inv_files(t_ls_list *list);
void			free_list(t_ls_list *list);
void			sort_list(t_list_node **headref);
void			print_reg_files(t_ls_list *list);
void			parse_dirs(t_ls_list *list_dirs, bool first);
t_list_node		*reverse_list(t_list_node *list);
int				sort_time(t_list_node *one, t_list_node *two);
void			print_permissions(t_file_info *info);
void			print_l_reg_files(t_ls_list *list, int total);

extern t_ls_flags g_flags;
#endif
