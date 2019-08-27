/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 16:51:01 by eagulov           #+#    #+#             */
/*   Updated: 2019/08/26 16:48:46 by eagulov          ###   ########.fr       */
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

void	arg_parsing(int argc, char **argv);


extern t_ls_flags g_flags;
#endif
