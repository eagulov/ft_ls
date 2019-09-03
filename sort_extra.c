/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_extra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 11:10:51 by eagulov           #+#    #+#             */
/*   Updated: 2019/09/03 12:51:09 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		sort_time(t_list_node *one, t_list_node *two)
{
	if (one->file_info->tspec.tv_sec == two->file_info->tspec.tv_sec)
	{
		if (one->file_info->tspec.tv_nsec == two->file_info->tspec.tv_nsec)
			return (ft_strcmp(one->file_info->name, two->file_info->name) < 0);
		else
			return (one->file_info->tspec.tv_nsec >\
											two->file_info->tspec.tv_nsec);
	}
	return (one->file_info->tspec.tv_sec > two->file_info->tspec.tv_sec);
}
