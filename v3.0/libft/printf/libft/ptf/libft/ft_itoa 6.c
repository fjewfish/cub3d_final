/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 10:54:31 by fjewfish          #+#    #+#             */
/*   Updated: 2020/05/29 17:28:16 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_numsize_sing(int n)
{
	size_t i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		numsize;

	numsize = ft_numsize_sing(n);
	if (!(num = (char *)malloc(sizeof(char) * numsize + 1)))
		return (NULL);
	num[numsize] = 0;
	numsize--;
	if (n == 0)
	{
		num[numsize] = '0';
		numsize--;
	}
	while (n != 0)
	{
		if (n < 0)
			num[numsize] = (n % 10) * (-1) + 48;
		else
			num[numsize] = n % 10 + 48;
		n = n / 10;
		numsize--;
	}
	if (numsize == 0)
		num[0] = '-';
	return (num);
}
