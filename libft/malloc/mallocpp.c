/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mallocpp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:42:58 by gsaile            #+#    #+#             */
/*   Updated: 2024/03/22 22:44:44 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstadd_back_malloc(void *new)
{
	t_malloc	*current;

	if (mlc == NULL)
	{
		mlc = new;
		return ;
	}
	current = mlc;
	while (current->next)
		current = current->next;
	current->next = new;
}

static t_malloc	*ft_lstnew_malloc(void *content)
{
	t_malloc	*list;

	list = malloc(sizeof(t_malloc));
	if (list == NULL)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

void	*mallocpp(int size)
{
	void *mal = malloc(size);
	if (!mal)
		return (NULL);
	t_malloc *new = ft_lstnew_malloc(mal);
	if (!new)
	{
		free(mal);
		return (NULL);
	}
	ft_lstadd_back_malloc(new);
	return (mal);
}

void free_all(void)
{
	t_malloc *current = mlc;
	t_malloc *tmp;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp->content);
		free(tmp);
	}
	mlc = NULL;
}