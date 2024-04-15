/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:44:58 by gsaile            #+#    #+#             */
/*   Updated: 2024/04/15 15:41:38 by gsaile           ###   ########.fr       */
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

    if (left->stat.st_mtime > right->stat.st_mtime ||
        (left->stat.st_mtime == right->stat.st_mtime && strcmp(left->name, right->name) >= 0)) {
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
        // char modified_time[20];
        // strftime(modified_time, sizeof(modified_time), "%Y-%m-%d %H:%M:%S", localtime(&(head->stat.st_mtime)));
        // printf("%s\t%s\t%s\n", head->name, modified_time, head->path);
        if (data.R && head->type == DT_DIR && strcmp(head->name, ".") && strcmp(head->name, "..")) {
            char *new_path = ft_strjoin(head->path, "/");
            char *new_argv[3] = {"./ft_ls", new_path, NULL};
            ft_ls(data, 2, new_argv);
        }
        else
        // printf("1: %p\n", head->entry->d_name);
            printf("%s\n", head->name);
        head = head->next;
    }
    if (data.R)
        printf("\n");
}

int ft_ls(t_data data, int argc, char **argv)
{
    t_path *paths = get_paths(argc, argv);
    get_entries(paths, data);
    t_path *tmp = paths;
    t_entry *entry = NULL;
    // printf("FT_LS %p %p\n", paths, paths->entries);
    while (tmp) {
        // printf("hehe\n");
        // printf("tmp [%p] | tmp->content [%p]\n", tmp, tmp->content);
        // printf("\n%s:\n", tmp->content);
        if (data.R && strcmp(tmp->content, ".") && strcmp(tmp->content, ".."))
            printf("%s:\n", tmp->content);
        entry = tmp->entries;
        if (!entry)
            return (1);
        if (data.t)
            mergeSort(&entry);
        if (data.r)
            reverseList(&entry);
        printList(entry, data);
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
