/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:58:58 by gsaile            #+#    #+#             */
/*   Updated: 2024/04/11 19:59:08 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i++] == c)
			return (1);
	}
	return (0);
}

static int	get_len(char *s1, char const *set)
{
	int	i;

	while (is_in_set(*s1, set))
		s1++;
	i = ft_strlen(s1);
	if (i == 0)
		return (0);
	while (is_in_set(s1[i - 1], set))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	char	*tmp;
	int		len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	tmp = (char *)s1;
	len = get_len(tmp, set);
	ret = mallocpp((len + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	while (is_in_set(*tmp, set))
		tmp++;
	ft_strlcpy(ret, tmp, len + 1);
	return (ret);
}
