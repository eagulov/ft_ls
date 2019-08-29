/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 13:17:00 by eagulov           #+#    #+#             */
/*   Updated: 2019/08/29 13:22:42 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_list(t_ls_list *list, char *title)
{
	t_list_node	*temp;

	temp = list->top;
	ft_printf("%s:\n", title);
	while (temp)
	{
		ft_printf("%s;\n", temp->file_info->name);
		temp = temp->next;
	}
}

t_list_node	*new_node(t_file_info *infolist)
{
	t_list_node *n_node;

	n_node = (t_list_node *)malloc(sizeof(t_list_node));
	n_node->file_info = infolist;
	n_node->next = NULL;
	return (n_node);
}

t_file_info	*set_list(int type, char *name, char *path)
{
	t_file_info *infolist;

	infolist = (t_file_info *)malloc(sizeof(t_file_info));
	infolist->name = name;
	infolist->path = path;
	infolist->type = type;
	return (infolist);
}