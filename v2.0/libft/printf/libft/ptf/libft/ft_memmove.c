/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <fjewfish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 11:20:40 by fjewfish          #+#    #+#             */
/*   Updated: 2020/10/11 20:12:17 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The memmove() function copies n bytes from string s2 to string s1.  The
** two strings may overlap; the copy is always done in a non-destructive
** manner.
*/

void	*ft_memmove(void *aio1, const void *aio2, size_t n)
{
	size_t			i;
	unsigned char	*d1;
	unsigned char	*d2;

	i = 0;
	d1 = (unsigned char *)s1;
	d2 = (unsigned char *)s2;
	if (!d1 && !d2)
		return (NULL);
	if (d1 > d2)
	{
		ft_memcpy(d1, d2, n);
	}
	else
	{
		while (i < n)
		{
			d1[i] = d2[i];
			i++;
		}
	}
	return (s1);
}
