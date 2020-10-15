/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <fjewfish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 11:37:39 by fjewfish          #+#    #+#             */
/*   Updated: 2020/10/12 16:53:59 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strcmp() and strncmp() functions lexicographically
** compare the null-terminated nullterminated
** terminated strings s1 and s2.
**
** The strncmp() function compares not more than n characters.  Because
** strncmp() is designed for comparing strings rather than binary data,
** characters that appear after a `\0' character are not compared.
*/

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i] && i < n - 1)
		i++;
	if (n != 0)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	if (s1[i] != '\0' || s2[i] != '\0')
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
