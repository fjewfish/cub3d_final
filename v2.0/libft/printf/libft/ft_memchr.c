/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 11:16:49 by fjewfish          #+#    #+#             */
/*   Updated: 2020/05/29 23:00:46 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**The memchr() function locates the first occurrence of c (converted to an
**unsigned char) in string s.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*d;

	d = (unsigned char *)s;
	while (n)
	{
		if (*d == (unsigned char)c)
			return ((void *)d);
		d++;
		n--;
	}
	return (NULL);
}
