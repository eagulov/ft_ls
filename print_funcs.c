/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 10:58:56 by eagulov           #+#    #+#             */
/*   Updated: 2019/08/30 13:21:53 by eagulov          ###   ########.fr       */
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

void		print_reg_files(t_ls_list *list)
{
	t_list_node *temp;

	temp = list->top;
	while (temp)
	{
		ft_printf("%s \t", temp->file_info->name);
		temp = temp->next;
	}
	if (list->top)
		write(1, "\n", 1);
}
