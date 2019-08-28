/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 15:04:44 by eagulov           #+#    #+#             */
/*   Updated: 2019/08/28 14:34:14 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// sort list
// free list

void		flag_error(char c)
{
	ft_printf("ls: illegal option -- %c \n usage: ls [-Rartl] [file ...]", c);
	exit(0);
}

// t_ls_list	*path_parsing(char **argv, int nflag)
// {
// 	t_ls_list	*pathlist;
// 	int			type;

// 	pathlist = initlist();

// 	while (argv[nflag])
// 	{
// 		ls_push_list(pathlist, set_list(0, argv[nflag], argv[nflag]));
// 		nflag++;
// 	}
// 	return (pathlist);
// }

int			arg_parsing(char **argv)
{
	int flag_end;
	int i;

	flag_end = 1;
	while (argv[flag_end] && argv[flag_end][0] == '-' && argv[flag_end][1])
	{
		i = 0;
		while (argv[flag_end][++i])
			if (argv[flag_end][i] == 'R')
				g_flags.cr = true;
			else if (argv[flag_end][i] == 'r')
				g_flags.r = true;
			else if (argv[flag_end][i] == 'l')
				g_flags.l = true;
			else if (argv[flag_end][i] == 't')
				g_flags.t = true;
			else if (argv[flag_end][i] == 'a')
				g_flags.a = true;
			else
				flag_error(argv[flag_end][i]);
		flag_end++;
	}
	return (flag_end);
}
