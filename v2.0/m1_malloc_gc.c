/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m1_malloc_gc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <fjewfish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 03:02:50 by fjewfish          #+#    #+#             */
/*   Updated: 2020/10/12 17:20:15 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header_v2.h"

void		*malloc_gc(size_t sizemem)
{
	void	*pointer;

	pointer = malloc(sizemem);
	memory_manager(pointer, M_ADD);
	return (pointer);
}

void		*calloc_gc(size_t nmemb, size_t size)
{
	void	*pointer;

	pointer = ft_calloc(nmemb, size);
	memory_manager(pointer, M_ADD);
	return (pointer);
}

void		free_gc(void *ptr)
{
	memory_manager(ptr, M_REMOVE);
}

char		*ft_strdup_gc(char *s1)
{
	char *s_cpy;

	s_cpy = (char *)malloc_gc(sizeof(char) * (ft_strlen(s1) + 1));
	if (s_cpy == NULL)
		return (NULL);
	return (ft_strcpy(s_cpy, (char *)s1));
}
