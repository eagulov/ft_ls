/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 17:50:24 by eagulov           #+#    #+#             */
/*   Updated: 2019/09/03 14:22:59 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// flag r
// extra \n
// bag with reg_files in args

t_ls_flags g_flags = {0, 0, 0, 0, 0};

void		print_not_dirs(t_ls_list *inv, t_ls_list *files)
{
	sort_list(&(inv->top));
	print_inv_files(inv);
	free_list(inv);
	sort_list(&(files->top));
	print_reg_files(files);
	free_list(files);
	write(1, "\n", 1);
}

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
			ls_push_list(dirs, set_list(argv[end], argv[end]));
		else if (S_ISREG(stats.st_mode))
			ls_push_list(files, set_list(argv[end], argv[end]));
		else
			ls_push_list(inv, set_list(argv[end], argv[end]));
		end++;
		ft_bzero(&stats, sizeof(struct stat));
	}
	if (files->top || inv->top)
		print_not_dirs(inv, files);
	return (dirs);
}

int	main(int argc, char **argv)
{
	int			flag_end;
	t_ls_list	*arg_dirs;

	flag_end = arg_parsing(argv);
	arg_dirs = split_list(argv, flag_end);
	if (flag_end == argc)
		ls_push_list(arg_dirs, set_list(".", "."));
	sort_list(&(arg_dirs->top));
	if (argc - 1 == flag_end || argc == flag_end)
		parse_dirs(arg_dirs, true);
	else
		parse_dirs(arg_dirs, false);
	free_list(arg_dirs);
	// while(1);
	return (0);
}
