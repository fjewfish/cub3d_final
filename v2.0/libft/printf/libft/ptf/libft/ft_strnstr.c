/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 11:38:50 by fjewfish          #+#    #+#             */
/*   Updated: 2020/06/02 01:05:30 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strnstr() function locates the first occurrence
** of the null-termi-nated null-terminated
** nated string s2 in the string s1, where not more than n characters are
** searched.  Characters that appear after a `\0' character are not
** searched.  Since the strnstr() function is a FreeBSD specific API, it
** should only be used when portability is not a concern.
*/

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	k;
	char	*s3;

	i = 0;
	k = 0;
	s3 = (char *)s1;
	if (s2[0] == '\0')
		return (s3);
	while (s3[i] && (i + ft_strlen(s2)) <= n && n)
	{
		k = ft_strncmp((s3 + i), s2, ft_strlen(s2));
		if (k == 0)
			return (s3 + i);
		i++;
	}
	return (NULL);
}
