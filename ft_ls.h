/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 16:51:01 by eagulov           #+#    #+#             */
/*   Updated: 2019/08/27 12:26:34 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "ft_printf/ft_printf.h"

typedef struct	s_ls_flags {
	bool	l;
	bool	a;
	bool	r;
	bool	t;
	bool	cr;
}				t_ls_flags;

typedef struct	s_file_info {
	int		type;
	char	*name;
	char	*path;
}				t_file_info;

typedef struct	s_ls_list {
	struct s_list_node	*top;
	int					cap;
}				t_ls_list;

typedef struct	s_list_node {
	struct s_file_info	*file_info;
	struct s_list_node	*next;
}				t_list_node;

void		arg_parsing(int argc, char **argv);
t_file_info	*set_list(int type, char *name, char *path);

extern t_ls_flags g_flags;
#endif
