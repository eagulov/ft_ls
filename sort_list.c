/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:25:06 by eagulov           #+#    #+#             */
/*   Updated: 2019/08/29 16:20:28 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		frnt_bck_splt(t_list_node *source, t_list_node **frnt,
														t_list_node **bck)
{
	t_list_node	*slow;
	t_list_node	*fast;

	slow = source;
	fast = slow->next;
	while (fast)
	{
		fast = fast->next;
		if (fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*frnt = source;
	*bck = slow->next;
	slow->next = NULL;
}

t_list_node	*sorted_merge(t_list_node *a, t_list_node *b)
{
	t_list_node *res;

	res = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (ft_strcmp(a->file_info->name, b->file_info->name) < 0)
	{
		res = a;
		res->next = sorted_merge(a->next, b);
	}
	else
	{
		res = b;
		res->next = sorted_merge(a, b->next);
	}
	return (res);
}

void		sort_list(t_list_node **headref)
{
	t_list_node *a;
	t_list_node *b;
	t_list_node	*head;

	head = *headref;
	if (head == NULL || head->next == NULL)
		return ;
	frnt_bck_splt(head, &a, &b);
	sort_list(&a);
	sort_list(&b);
	*headref = sorted_merge(a, b);
}
