/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:44:58 by gsaile            #+#    #+#             */
/*   Updated: 2024/04/15 16:59:54by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_malloc *mlc = NULL;

int ft_ls(t_data data, int argc, char **argv);

void reverseList(t_entry **head) {
    t_entry *prev = NULL;
    t_entry *current = *head;
    t_entry *next = NULL;

    while (current != NULL) {
        next = current->next;  // Store the next node
        current->next = prev;  // Reverse the link

        // Move pointers one position ahead
        prev = current;
        current = next;
    }

    *head = prev;  // Update the head to point to the new first node
}

t_entry* merge(t_entry *left, t_entry *right) {
    if (!left) return right;
    if (!right) return left;

    if ((left->stat.st_mtimespec.tv_sec > right->stat.st_mtimespec.tv_sec) ||
        (left->stat.st_mtimespec.tv_sec == right->stat.st_mtimespec.tv_sec && 
         left->stat.st_mtimespec.tv_nsec > right->stat.st_mtimespec.tv_nsec) ||
        ((left->stat.st_mtimespec.tv_sec == right->stat.st_mtimespec.tv_sec && 
          left->stat.st_mtimespec.tv_nsec == right->stat.st_mtimespec.tv_nsec) && 
         strcmp(left->name, right->name) < 0)) {
        left->next = merge(left->next, right);
        return left;
    } else {
        right->next = merge(left, right->next);
        return right;
    }
}

void split(t_entry *head, t_entry **left, t_entry **right) {
    t_entry *fast, *slow;
    slow = head;
    fast = head->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *left = head;
    *right = slow->next;
    slow->next = NULL;
}

void mergeSort(t_entry **head) {
    t_entry *cur = *head;
    t_entry *left, *right;

    if (cur == NULL || cur->next == NULL)
        return;

    split(cur, &left, &right);
    mergeSort(&left);
    mergeSort(&right);
    *head = merge(left, right);
}

void printList(t_entry *head, t_data data) {
    while (head) {
        if (data.R && head->type == DT_DIR && strcmp(head->name, ".") && strcmp(head->name, "..")) {
            char *new_argv[3] = {"./ft_ls", head->path, NULL};
            ft_ls(data, 2, new_argv);
        }
        else
            ft_printf("%s\n", head->name);
        head = head->next;
    }
    if (data.R)
        printf("\n");
}

char *get_permissions(t_entry *entry)
{
    char *permissions = mallocpp(11 * sizeof(char));

    permissions[0] = ((entry->stat.st_mode & 0170000) == 0040000) ? 'd' : '-';
    permissions[1] = entry->stat.st_mode & 0400 ? 'r' : '-';
    permissions[2] = entry->stat.st_mode & 0200 ? 'w' : '-';
    permissions[3] = entry->stat.st_mode & 0100 ? 'x' : '-';
    permissions[4] = entry->stat.st_mode & 040 ? 'r' : '-';
    permissions[5] = entry->stat.st_mode & 020 ? 'w' : '-';
    permissions[6] = entry->stat.st_mode & 010 ? 'x' : '-';
    permissions[7] = entry->stat.st_mode & 04 ? 'r' : '-';
    permissions[8] = entry->stat.st_mode & 02 ? 'w' : '-';
    permissions[9] = entry->stat.st_mode & 01 ? 'x' : '-';
    permissions[10] = '\0';

    return (permissions);
}

void printl(t_entry *head) {
    while (head) {
        struct passwd *pw = getpwuid(head->stat.st_uid);
        struct group  *gr = getgrgid(head->stat.st_gid);
        printf("%s %d\t%s\t%s\t%lld\t%s\n",
            get_permissions(head),
            head->stat.st_nlink,
            pw->pw_name,
            gr->gr_name,
            head->stat.st_size,
            head->name);
        head = head->next;
    }
}

int ft_ls(t_data data, int argc, char **argv)
{
    t_path *paths = get_paths(argc, argv);
    get_entries(paths, data);
    t_path *tmp = paths;
    t_entry *entry = NULL;
    while (tmp) {
        if (data.R && strcmp(tmp->content, ".") && strcmp(tmp->content, ".."))
            printf("\n%s:\n", tmp->content);
        entry = tmp->entries;
        if (!entry)
            return (1);
        if (data.t)
            mergeSort(&entry);
        if (data.r)
            reverseList(&entry);
        printl(entry);
        tmp = tmp->next;
    }
    return (0);
}

int main(int argc, char *argv[]) {
    t_data data;
    // t_path *paths = NULL;

    data = get_options(argc, argv);
    // printf("==== data ====\n");
    // printf("l : %d\n", data.l);
    // printf("a : %d\n", data.a);
    // printf("r : %d\n", data.r);
    // printf("R : %d\n", data.R);
    // printf("t : %d\n", data.t);

    // printf("\n==== paths ====\n");
    return (ft_ls(data, argc, argv));
}

// int main()
// {
//     int *a = mallocpp(sizeof(int));
//     *a = 12;
//     ft_printf("%d\n", *a);
//     char *s = mallocpp(5 * sizeof(char));
//     s[4] = 0;
//     for (int i = 0; i < 4; i++)
//         s[i] = i + 'a';
//     ft_printf("%s\n", s);
// }
