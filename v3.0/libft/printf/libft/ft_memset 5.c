/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 11:22:14 by fjewfish          #+#    #+#             */
/*   Updated: 2020/05/29 11:46:47 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The memset() function writes n bytes of value c (converted to an unsigned
** char) to the string s.
*/

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char *mas;

	mas = (unsigned char *)b;
	while (n > 0)
	{
		mas[n - 1] = c;
		n--;
	}
	return (b);
}
