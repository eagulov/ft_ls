/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 10:58:56 by eagulov           #+#    #+#             */
/*   Updated: 2019/09/10 11:46:44 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_inv_files(t_ls_list *list)
{
	t_list_node	*temp;

	temp = list->top;
	while (temp)
	{
		ft_printf("ls: %s: No such file or directory\n", temp->file_info->name);
		temp = temp->next;
	}
}

void		print_l_reg_files(t_ls_list *list, int total)
{
	if (g_flags.l)
		ft_printf("total %d\n", total);
	print_reg_files(list);
}

void		print_reg_files(t_ls_list *list)
{
	t_list_node *temp;

	temp = list->top;
	while (temp)
	{
		if (g_flags.l)
		{
			print_permissions(temp->file_info);
			if (temp->next)
				write(1, "\n", 1);
		}
		else
			ft_printf("%s \t", temp->file_info->name);
		temp = temp->next;
	}
	if (list->top)
		write(1, "\n", 1);
}
