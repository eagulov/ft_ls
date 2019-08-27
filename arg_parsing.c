/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 15:04:44 by eagulov           #+#    #+#             */
/*   Updated: 2019/08/26 17:29:17 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// need to write list functions !!!
// init list
// push to list
// pop from list
// sort list
// free list

void	flag_error(char c)
{
	ft_printf("ls: illegal option -- %c \n usage: ls [-Rartl] [file ...]", c);
	exit(0);
}

t_list	*path_parsing(char **argv, int nflag)
{
	t_list *pathlist;

	while (argv[nflag])
	{
		// copy argv[nflag] to list 
		// iterate nflag 
	}



	return(pathlist);
}

int		flag_parsing(char **argv)
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

void	arg_parsing(int argc, char **argv)
{
	int		nflag;
	t_list	*pathlist;

	nflag = 0;
	if (argc < 2)
	{
		while (0);
	}
	nflag = flag_parsing(argv);
	pathlist = path_parsing(argv, nflag);
	// sort list
	// split it for 2 parts (1st is invalid and 2nd is valid)
	// print invalid list and delete from memory
	ft_printf("%d, %d, %d, %d, %d", g_flags.a, g_flags.cr, g_flags.l, g_flags.r, g_flags.t);

}