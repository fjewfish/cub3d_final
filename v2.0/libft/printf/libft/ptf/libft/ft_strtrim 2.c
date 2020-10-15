/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 17:47:52 by fjewfish          #+#    #+#             */
/*   Updated: 2020/06/03 17:47:56 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Parameters
** #1. The string to be trimmed.
** #2. The reference set of characters to trim.
** Description
** Allocates (with malloc(3)) and returns a copy of
** ’s1’ with the characters specified in ’set’ removed
** from the beginning and the end of the string.
*/

int		ft_check_cymbol(char const c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1)
		return (ft_substr(s1, 0, 0));
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_check_cymbol(s1[start], set) && s1[start])
		start++;
	while (ft_check_cymbol(s1[end], set) && end)
		end--;
	if (start < end)
		return (ft_substr(s1, start, end - start + 1));
	else
		return (ft_substr(s1, 0, 0));
}
