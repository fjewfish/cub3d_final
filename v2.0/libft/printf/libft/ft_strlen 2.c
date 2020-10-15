/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 11:35:39 by fjewfish          #+#    #+#             */
/*   Updated: 2020/05/29 11:36:07 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strlen() function computes the length of the string s.
*/

size_t	ft_strlen(const char *s)
{
	size_t sum;

	sum = 0;
	while (*s)
	{
		sum++;
		s++;
	}
	return (sum);
}
