/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:54:56 by gsaile            #+#    #+#             */
/*   Updated: 2024/03/17 18:18:21 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_path	*ft_lstnew(void *content)
{
	t_path	*list;

	list = malloc(sizeof(t_path));
	if (list == NULL)
		return (NULL);
	list->content = content;
	list->entries = NULL;
	list->next = NULL;
	return (list);
}

t_entry	*ft_lstnew_entry(struct dirent *entry)
{
	t_entry	*list;

	list = malloc(sizeof(t_entry));
	if (list == NULL)
		return (NULL);
	list->entry = entry;
	list->next = NULL;
	return (list);
}
