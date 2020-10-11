/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 11:10:49 by fjewfish          #+#    #+#             */
/*   Updated: 2020/05/31 11:24:00 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The memccpy() function copies bytes from string s2 to string s1.  If the
** character c (as converted to an unsigned char) occurs in the string s2,
** the copy stops and a pointer to the byte after the copy of c in the
** string s1 is returned.  Otherwise, n bytes are copied, and a NULL pointer
** is returned.
*/

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t			i;
	unsigned char	*d1;
	unsigned char	*d2;

	i = 0;
	d1 = (unsigned char *)s1;
	d2 = (unsigned char *)s2;
	while (i < n)
	{
		d1[i] = d2[i];
		if (d2[i] == (unsigned char)c)
			return ((void *)(d1 + i + 1));
		i++;
	}
	return (NULL);
}
