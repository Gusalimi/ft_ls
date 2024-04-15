/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:54:56 by gsaile            #+#    #+#             */
/*   Updated: 2024/04/15 15:40:51 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_path	*ft_lstnew(void *content)
{
	t_path	*list;

	list = mallocpp(sizeof(t_path));
	if (list == NULL)
		return (NULL);
	list->content = content;
	list->entries = NULL;
	list->next = NULL;
	return (list);
}

t_entry	*ft_lstnew_entry(char *entry_name, int entry_type)
{
	t_entry	*list;

	list = mallocpp(sizeof(t_entry));
	if (list == NULL)
		return (NULL);
	list->name = entry_name;
	list->type = entry_type;
	list->path = NULL;
	list->next = NULL;
	return (list);
}
