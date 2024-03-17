/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_entries.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:12:33 by gsaile            #+#    #+#             */
/*   Updated: 2024/03/17 21:36:31 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void get_entries(t_path *paths, t_data data) {
	t_entry			*entries = NULL;
	t_entry			*tmp;
	t_path			*current;
	DIR				*dir;
	struct dirent	*entry;

	if (!paths)
		return;

	current = paths;
	while (current) {
		dir = opendir(current->content);
		while ((entry = readdir(dir))) {
			if (data.a || entry->d_name[0] != '.')
			{
				char *dir_path = ft_strjoin(current->content, "/");
				char *entry_path = ft_strjoin(dir_path, entry->d_name);
				free(dir_path);
				if (!dir_path || !entry_path)
					fatal_error();
				tmp = ft_lstnew_entry(entry);
				if (!tmp)
					fatal_error();
				tmp->path = entry_path;
				if (entry->d_type == DT_LNK)
					lstat(entry_path, &tmp->stat);
				else
					stat(entry_path, &tmp->stat);
				ft_lstadd_back_entry(&entries, tmp);
			}
		}
		current->entries = entries;
		entries = NULL;
		closedir(dir);
		current = current->next;
	}
}