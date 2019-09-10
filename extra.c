/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 13:17:00 by eagulov           #+#    #+#             */
/*   Updated: 2019/09/10 11:04:49 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list_node	*new_node(t_file_info *infolist)
{
	t_list_node *n_node;

	n_node = (t_list_node *)malloc(sizeof(t_list_node));
	n_node->file_info = infolist;
	n_node->next = NULL;
	return (n_node);
}

t_file_info	*set_list(char *name, char *path)
{
	t_file_info *infolist;
	struct stat	stats;

	lstat(path, &stats);
	infolist = (t_file_info *)malloc(sizeof(t_file_info));
	infolist->name = ft_strdup(name);
	infolist->path = ft_strdup(path);
	infolist->tspec = stats.st_mtimespec;
	infolist->filestat = stats;
	return (infolist);
}
