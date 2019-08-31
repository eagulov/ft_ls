/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 17:50:24 by eagulov           #+#    #+#             */
/*   Updated: 2019/08/31 15:26:38 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// fix dirs names before printing
// make l, t, r flags

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
			ls_push_list(dirs, set_list(argv[end], argv[end]));
		else if (S_ISREG(stats.st_mode))
			ls_push_list(files, set_list(argv[end], argv[end]));
		else
			ls_push_list(inv, set_list(argv[end], argv[end]));
		end++;
		ft_bzero(&stats, sizeof(struct stat));
	}
	sort_list(&(inv->top));
	print_inv_files(inv);
	free_list(inv);
	print_reg_files(files);
	free_list(files);
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
	parse_dirs(arg_dirs, true);
	free_list(arg_dirs);
	while(1);
	return (0);
}
