/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 13:11:31 by fjewfish          #+#    #+#             */
/*   Updated: 2020/07/26 17:42:13 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all.h"

/*
** base 16
** unsigned long long
*/

size_t		ft_numsize_p(unsigned long long n)
{
	size_t	i;

	i = 0;
	while (n != 0)
	{
		i++;
		n /= 16;
	}
	return (i);
}

/*
** base 16 or 10
** unsigned int
*/

size_t		ft_numsize_h_u(unsigned int n, int base)
{
	size_t	i;

	i = 0;
	while (n != 0)
	{
		i++;
		n /= base;
	}
	return (i);
}

/*
** all value >= 0
*/

char		*ft_itoa_pointer(unsigned long long n)
{
	char	*num;
	int		numsize;

	if (n == 0)
		return (ft_strdup("0"));
	numsize = ft_numsize_p(n);
	if (!(num = (char *)malloc(sizeof(char) * numsize + 1)))
		return (NULL);
	num[numsize] = 0;
	numsize--;
	while (n != 0)
	{
		if ((n % 16) < 10)
			num[numsize] = (n % 16) + 48;
		else
			num[numsize] = (n % 16) + 87;
		n = n / 16;
		numsize--;
	}
	return (num);
}

/*
** all value >= 0
*/

char		*ft_itoa_hexadecimal(unsigned int n)
{
	char	*num;
	int		numsize;

	if (n == 0)
		return (ft_strdup("0"));
	numsize = ft_numsize_h_u(n, 16);
	if (!(num = (char *)malloc(sizeof(char) * numsize + 1)))
		return (NULL);
	num[numsize] = 0;
	numsize--;
	while (n != 0)
	{
		if ((n % 16) < 10)
			num[numsize] = (n % 16) + 48;
		else
			num[numsize] = (n % 16) + 55;
		n = n / 16;
		numsize--;
	}
	return (num);
}

char		*ft_itoa_unsint(unsigned int n)
{
	char	*num;
	int		numsize;

	if (n == 0)
		return (ft_strdup("0"));
	numsize = ft_numsize_h_u(n, 10);
	if (!(num = (char *)malloc(sizeof(char) * numsize + 1)))
		return (NULL);
	num[numsize] = 0;
	numsize--;
	while (n != 0)
	{
		num[numsize] = n % 10 + 48;
		n = n / 10;
		numsize--;
	}
	return (num);
}
