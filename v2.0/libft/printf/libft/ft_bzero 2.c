/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero 2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <fjewfish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 10:38:34 by fjewfish          #+#    #+#             */
/*   Updated: 2020/10/11 20:12:17 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The bzero() function writes n zeroed bytes to the string s.  If n is
** zero, bzero() does nothing.
*/

void	ft_bzero(void *aio, size_t n)
{
	unsigned char *mas;

	mas = (unsigned char *)s;
	if (n > 0)
	{
		while (n > 0)
		{
			mas[n - 1] = '\0';
			n--;
		}
	}
}
