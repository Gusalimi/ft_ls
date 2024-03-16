/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:44:58 by gsaile            #+#    #+#             */
/*   Updated: 2024/03/17 00:37:23 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int ft_ls(t_data data, t_path *paths) {
    // TODO: protect opendir, readdir and NULL paths
    if (!paths)
        return (1);
    int		names = paths->next ? 1 : 0;
    t_path  *tmp = paths;
    DIR		*dir;
    struct dirent *entry;
    while (tmp) {
        dir = opendir(tmp->content);
        if (names)
            printf("%s:\n", tmp->content);
        while ((entry = readdir(dir))) {
			// if (entry->d_type == DT_DIR)
			// 	printf(BOLDCYAN);
            if (data.a || entry->d_name[0] != '.')
                printf("%s\n", entry->d_name);
			// printf(RESET);
        }
        closedir(dir);
        tmp = tmp->next;
        if (names && tmp)
            printf("\n");
    }
    return 0;
}

int main(int argc, char *argv[]) {
    t_data data;
    t_path *paths = NULL;

    data = get_options(argc, argv);
    printf("==== data ====\n");
    printf("l : %d\n", data.l);
    printf("a : %d\n", data.a);
    printf("r : %d\n", data.r);
    printf("R : %d\n", data.R);
    printf("t : %d\n", data.t);

    paths = get_paths(argc, argv);
    t_path *tmp = paths;
    printf("\n==== paths ====\n");
    while (tmp) {
        printf("%s\n", tmp->content);
        tmp = tmp->next;
    }

    printf("\n==== ft_ls ====\n");
    return ft_ls(data, paths);
}
