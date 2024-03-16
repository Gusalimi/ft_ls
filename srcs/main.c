#include "ft_ls.h"

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
    return 0;
}
