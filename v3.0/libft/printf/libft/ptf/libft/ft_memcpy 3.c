/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 11:19:43 by fjewfish          #+#    #+#             */
/*   Updated: 2020/05/29 11:20:32 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The memcpy() function copies n bytes from memory area s2 to memory area
** s1.  If s1 and s2 overlap, behavior is undefined.  Applications in which
** s1 and s2 might overlap should use memmove(3) instead.
*/

void	*ft_memcpy(void *restrict s1, const void *restrict s2, size_t n)
{
	unsigned char *d1;
	unsigned char *d2;

	d1 = (unsigned char *)s1;
	d2 = (unsigned char *)s2;
	if (!d1 && !d2)
		return (NULL);
	while (n > 0)
	{
		d1[n - 1] = d2[n - 1];
		n--;
	}
	return (s1);
}
