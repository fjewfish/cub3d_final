/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 11:32:43 by fjewfish          #+#    #+#             */
/*   Updated: 2020/05/31 17:27:40 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Parameters
** #1. The prefix string.
** #2. The suffix string.
** Description
** Allocates (with malloc(3)) and returns a new
** string, which is the result of the concatenation
** of ’s1’ and ’s2’.
*/

void	ft_write_result(char const *s1, char const *s2, char *result)
{
	size_t	i;

	i = 0;
	while (*s1)
	{
		result[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		result[i] = *s2;
		i++;
		s2++;
	}
	result[i] = 0;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len;

	if (!s1 && !s2)
		return (NULL);
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_write_result(s1, s2, result);
	return (result);
}
