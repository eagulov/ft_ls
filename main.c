/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 17:50:24 by eagulov           #+#    #+#             */
/*   Updated: 2019/08/28 15:56:37 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls_flags g_flags = {0, 0, 0, 0, 0};

t_ls_list	*split_list(char **argv, int nflag)
{
	struct stat stats;
	t_ls_list	*invalid;
	t_ls_list	*files;
	t_ls_list	*dirs;

	invalid = initlist();
	files = initlist();
	dirs = initlist();
	while (argv[nflag])
	{
		stat(argv[nflag], &stats);
		if (S_ISDIR(stats.st_mode))
			ls_push_list(dirs, set_list(1, argv[nflag], argv[nflag]));
		else if (S_ISREG(stats.st_mode))
			ls_push_list(files, set_list(0, argv[nflag], argv[nflag]));
		else
			ls_push_list(invalid, set_list(-1, argv[nflag], argv[nflag]));
		nflag++;
	}
	return (dirs);
}

int	main(int argc, char **argv)
{
	int flag_end;

	if (argc < 2)
	{
		write(1, "yo\n", 3);
	}
	ft_printf("hello, i compiled\n");
	flag_end = arg_parsing(argv);
	split_list(argv, flag_end);
	// split list in 3 parts: invalid, files, dirs
	// open arg_directories and print it
	return (0);
}
