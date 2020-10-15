/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 01:19:29 by fjewfish          #+#    #+#             */
/*   Updated: 2020/06/03 01:19:33 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strlcat() function appends the NUL-terminated string src to the end
** of dst.  It will append at most size - strlen(dst) - 1 bytes,
** NUL-termi-nating NUL-terminating
** nating the result.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t l1;
	size_t l2;

	j = 0;
	l1 = ft_strlen(dst);
	i = l1;
	l2 = ft_strlen(src);
	if (size == 0)
		return (l2);
	if (size < l1)
		return (l2 + size);
	else
	{
		while (src[j] && (l1 + j) < size)
			dst[i++] = src[j++];
		if ((l1 + j) == size && l1 < size)
			dst[--i] = '\0';
		else
			dst[i] = '\0';
		return (l1 + l2);
	}
}
