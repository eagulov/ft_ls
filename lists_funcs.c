/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 11:33:39 by eagulov           #+#    #+#             */
/*   Updated: 2019/08/28 15:46:58 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file_info	*ls_pop_list(t_ls_list *pathlist)
{
	t_list_node	*tmp;
	t_file_info *tmp_info;

	if (!pathlist->top)
		return (NULL);
	tmp = pathlist->top;
	pathlist->top = pathlist->top->next;
	tmp_info = tmp->file_info;
	free(tmp);
	pathlist->cap -= 1;
	return (tmp_info);
}

t_list_node	*new_node(t_file_info *infolist)
{
	t_list_node *n_node;

	n_node = (t_list_node *)malloc(sizeof(t_list_node));
	n_node->file_info = infolist;
	n_node->next = NULL;
	return (n_node);
}

void		ls_push_list(t_ls_list *pathlist, t_file_info *infolist)
{
	t_list_node *n_node;

	n_node = new_node(infolist);
	n_node->next = pathlist->top;
	pathlist->top = n_node;
	pathlist->cap += 1;
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

t_ls_list	*initlist(void)
{
	t_ls_list	*list;

	list = (t_ls_list *)malloc(sizeof(t_ls_list));
	list->top = NULL;
	list->cap = 0;
	return (list);
}
