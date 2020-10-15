/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 11:27:30 by fjewfish          #+#    #+#             */
/*   Updated: 2020/05/29 11:31:24 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strdup() function allocates sufficient memory for a copy of the
** string s1, does the copy, and returns a pointer to it.  The pointer may
** subsequently be used as an argument to the function free(3).
**
** If insufficient memory is available, NULL is returned and errno is set to
** ENOMEM.
*/

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	char *s_cpy;

	s_cpy = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (s_cpy == NULL)
		return (NULL);
	return (ft_strcpy(s_cpy, (char *)s1));
}
