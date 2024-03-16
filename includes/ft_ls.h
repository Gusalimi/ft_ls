/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:45:26 by gsaile            #+#    #+#             */
/*   Updated: 2024/03/17 00:32:01 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ==== INCLUDES ==== //
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <sys/xattr.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "libft.h"


// ==== DEFINES ==== //

#define RESET   "\x1B[0m"
#define BLACK   "\x1B[30m"
#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE    "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN    "\x1B[36m"
#define WHITE   "\x1B[37m"


// ==== STRUCTURES ==== //
typedef struct s_data {
    int l;
    int a;
    int r;
    int R;
    int t;
} t_data;


// ==== FUNCTIONS ==== //

// == parsing.c == //
t_data  get_options(int argc, char *argv[]);
t_path  *get_paths(int argc, char *argv[]);