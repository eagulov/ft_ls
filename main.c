/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 17:50:24 by eagulov           #+#    #+#             */
/*   Updated: 2019/08/29 16:24:05 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// pretty print invalid and files
// RFLAG

t_ls_flags g_flags = {0, 0, 0, 0, 0};

t_ls_list	*split_list(char **argv, int end)
{
	struct stat stats;
	t_ls_list	*inv;
	t_ls_list	*files;
	t_ls_list	*dirs;

	inv = initlist(NULL);
	files = initlist(NULL);
	dirs = initlist(NULL);
	while (argv[end])
	{
		stat(argv[end], &stats);
		if (S_ISDIR(stats.st_mode))
			ls_push_list(dirs, set_list(1, argv[end], ft_strdup(argv[end])));
		else if (S_ISREG(stats.st_mode))
			ls_push_list(files, set_list(0, argv[end], ft_strdup(argv[end])));
		else
			ls_push_list(inv, set_list(-1, argv[end], ft_strdup(argv[end])));
		end++;
	}
	sort_list(&(inv->top));
	print_list(inv, "inv");
	free_list(inv);
	print_list(files, "files");
	free_list(files);
	return (dirs);
}

int	main(int argc, char **argv)
{
	int			flag_end;
	t_ls_list	*arg_dirs;

	if (argc < 2)
	{
		write(1, "yo\n", 3);
	}
	ft_printf("hello, i compiled\n");
	flag_end = arg_parsing(argv);
	arg_dirs = split_list(argv, flag_end);
	print_list(arg_dirs, "dirs");
	free_list(arg_dirs);
	// open arg_directories and print it
	while(1);
	return (0);
}
