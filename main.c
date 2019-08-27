/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 17:50:24 by eagulov           #+#    #+#             */
/*   Updated: 2019/08/27 16:07:24 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
t_ls_flags g_flags = {0, 0, 0, 0, 0};

int	main(int argc, char **argv)
{
	ft_printf("hello, i compiled\n");
	arg_parsing(argc, argv);
	// split list in 3 parts: invalid, files, dirs
	// open arg_directories and print it
	return (0);
}