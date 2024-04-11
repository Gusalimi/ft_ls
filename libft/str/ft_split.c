/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:56:47 by gsaile            #+#    #+#             */
/*   Updated: 2024/04/11 19:58:20 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	to_next_del(char **s, char c)
{
	int	i;

	i = 0;
	while ((*s)[i] != c && (*s)[i])
		i++;
	if (i == 0)
		(*s)++;
	return (i);
}

static int	count_words(char const *s, char c)
{
	char	*tmp;
	int		count_to_next;
	int		i;

	i = 0;
	tmp = (char *)s;
	while (*tmp)
	{
		count_to_next = to_next_del(&tmp, c);
		if (count_to_next)
		{
			i++;
			tmp += count_to_next;
		}
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	char	*tmp;
	int		count_to_next;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	tmp = (char *)s;
	ret = ft_calloc((count_words(s, c) + 1), sizeof(char *));
	if (ret == NULL)
		return (NULL);
	while (*tmp)
	{
		count_to_next = to_next_del(&tmp, c);
		if (count_to_next)
		{
			ret[i] = mallocpp((count_to_next + 1) * sizeof(char));
			if (ret[i] == NULL)
				return (NULL);
			ft_strlcpy(ret[i++], tmp, count_to_next + 1);
			tmp += count_to_next;
		}
	}
	return (ret);
}
