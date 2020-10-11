/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr 2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <fjewfish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 11:39:47 by fjewfish          #+#    #+#             */
/*   Updated: 2020/10/11 20:12:17 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strrchr() function locates the last occurrence of c (converted to a
** char) in the string s.  If c is `\0', strrchr() locates the terminating
** `\0'.
*/

char	*ft_strrchr(const char *aio, int c)
{
	size_t i;

	i = 0;
	while (*aio)
	{
		i++;
		s++;
	}
	while (i > 0)
	{
		if (*aio == (char)c)
			return ((char *)s);
		s--;
		i--;
	}
	if (*aio == (char)c)
		return ((char *)s);
	return (NULL);
}
