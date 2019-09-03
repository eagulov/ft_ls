/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 11:33:39 by eagulov           #+#    #+#             */
/*   Updated: 2019/09/03 11:08:42 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list_node	*reverse_list(t_list_node *list)
{
	t_list_node	*a;
	t_list_node	*b;
	t_list_node	*c;

	a = NULL;
	b = list;
	c = (list)->next;
	while (b)
	{
		c = b->next;
		b->next = a;
		a = b;
		b = c;
	}
	return (a);
}

void		free_list(t_ls_list *list)
{
	t_list_node *tmp;
	t_list_node	*tmp2;

	tmp = list->top;
	while (tmp)
	{
		tmp2 = tmp;
		free(tmp2->file_info->path);
		free(tmp2->file_info);
		tmp = tmp->next;
		free(tmp2);
	}
	free(list);
}

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

void		ls_push_list(t_ls_list *pathlist, t_file_info *infolist)
{
	t_list_node *n_node;

	n_node = new_node(infolist);
	n_node->next = pathlist->top;
	pathlist->top = n_node;
	pathlist->cap += 1;
}

t_ls_list	*initlist(t_list_node *node)
{
	t_ls_list	*list;

	list = (t_ls_list *)malloc(sizeof(t_ls_list));
	list->top = node;
	list->cap = 0;
	return (list);
}
