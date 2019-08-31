/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dirs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 11:34:51 by eagulov           #+#    #+#             */
/*   Updated: 2019/08/31 15:14:03 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file_info	*new_file(char *name, char *path)
{
	t_file_info	*infolist;

	infolist = (t_file_info *)malloc(sizeof(t_file_info));
	infolist->name = ft_strdup(name);
	infolist->path = path;
	return (infolist);
}

void		get_dirs(t_ls_list *files_list)
{
	t_ls_list	*dirs;
	t_list_node	*temp;
	struct stat stats;

	temp = files_list->top;
	dirs = initlist(NULL);
	while (temp)
	{
		stat(temp->file_info->path, &stats);
		if (S_ISDIR(stats.st_mode)\
			&& ft_strcmp(temp->file_info->name, ".")\
			&& ft_strcmp(temp->file_info->name, ".."))
			ls_push_list(dirs, set_list(temp->file_info->name,\
										temp->file_info->path));
		temp = temp->next;
	}
	sort_list(&(dirs->top));
	if (dirs->top)
		parse_dirs(dirs, false);
	free_list(dirs);
}

char		*mk_path(char *dir, char *file_name)
{
	int		total_len;
	char	*res;
	int		i;
	int		j;

	j = -1;
	i = 0;
	total_len = ft_strlen(dir) + ft_strlen(file_name) + 2;
	res = (char *)malloc(sizeof(char) * total_len);
	ft_bzero((void*)res, total_len);
	while (dir[++j])
	{
		res[i] = dir[j];
		i++;
	}
	res[i] = '/';
	j = -1;
	i++;
	while (file_name[++j])
	{
		res[i] = file_name[j];
		i++;
	}
	return (res);
}

t_ls_list	*get_files(DIR *dir, t_list_node *temp)
{
	t_ls_list		*files_list;
	struct dirent	*dp;

	files_list = initlist(NULL);
	while ((dp = readdir(dir)) != NULL)
	{
		if (dp->d_name[0] != '.' || g_flags.a)
			ls_push_list(files_list, new_file(dp->d_name,\
				mk_path(temp->file_info->path, dp->d_name)));
	}
	return (files_list);
}

void		parse_dirs(t_ls_list *list_dirs, bool first)
{
	DIR				*dir;
	t_list_node		*temp;
	t_ls_list		*files_list;

	temp = list_dirs->top;
	while (temp)
	{
		if ((dir = opendir(temp->file_info->path)) == NULL)
			ft_printf("ls: %s: Permission denied\n", temp->file_info->name);
		else
		{
			files_list = get_files(dir, temp);
			sort_list(&(files_list->top));
			if (!first)
				ft_printf("%s:\n", temp->file_info->path);
			print_reg_files(files_list);
			if (g_flags.cr)
				get_dirs(files_list);
			free_list(files_list);
			closedir(dir);
		}
		temp = temp->next;
	}
}
