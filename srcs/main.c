/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:44:58 by gsaile            #+#    #+#             */
/*   Updated: 2024/03/17 00:26:01 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int ft_ls(t_data data, t_path *paths) {
    (void)data;
    (void)paths;
    int names = paths->next ? 1 : 0;
    t_path *tmp = paths;
    DIR *dir;
    struct dirent *entry;
    while (tmp) {
        dir = opendir(tmp->content);
        if (names)
            printf("%s:\n", tmp->content);
        while ((entry = readdir(dir))) {
            if (data.a || entry->d_name[0] != '.')
                printf("%s\n", entry->d_name);
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
    printf("==== paths ====\n");
    while (tmp) {
        printf("%s\n", tmp->content);
        tmp = tmp->next;
    }

    printf("==== ft_ls ====\n");
    return ft_ls(data, paths);
}
