/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:44:52 by gsaile            #+#    #+#             */
/*   Updated: 2024/03/16 23:44:53 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_data  get_options(int argc, char *argv[]) {
    t_data data;
    int i;
    int j;

    i = 1;
    data.l = 0;
    data.a = 0;
    data.r = 0;
    data.R = 0;
    data.t = 0;
    while (i < argc) {
        if (argv[i][0] == '-')
        {
            j = 1;
            while (argv[i][j])
            {
                if (argv[i][j] == 'l')
                    data.l = 1;
                else if (argv[i][j] == 'a')
                    data.a = 1;
                else if (argv[i][j] == 'r')
                    data.r = 1;
                else if (argv[i][j] == 'R')
                    data.R = 1;
                else if (argv[i][j] == 't')
                    data.t = 1;
                else
                {
                    printf("ft_ls: illegal option -- %c\n", argv[i][j]);
                    printf("usage: ft_ls [-Ralrt] [file ...]\n");
                    exit(1);
                }
                j++;
            }
        }
        i++;
    }
    return data;
}

t_path  *get_paths(int argc, char *argv[]) {
    t_path *paths = NULL;
    t_path *tmp;
    int i;

    i = 1;
    while (i < argc) {
        if (argv[i][0] != '-') {
            tmp = ft_lstnew(argv[i]);
            if (!tmp) {
                printf("malloc error\n");
                exit(1);
            }
            ft_lstadd_back(&paths, tmp);
        }
        i++;
    }
    return paths;
}