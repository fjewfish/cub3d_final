/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 11:39:47 by fjewfish          #+#    #+#             */
/*   Updated: 2020/05/29 11:40:39 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strrchr() function locates the last occurrence of c (converted to a
** char) in the string s.  If c is `\0', strrchr() locates the terminating
** `\0'.
*/

char	*ft_strrchr(const char *s, int c)
{
	size_t i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	while (i > 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s--;
		i--;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
