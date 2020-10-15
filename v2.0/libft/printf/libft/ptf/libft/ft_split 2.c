/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 11:25:21 by fjewfish          #+#    #+#             */
/*   Updated: 2020/05/31 17:44:05 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Parameters
** #1. The string to be split.
** #2. The delimiter character.
** Description
** Allocates (with malloc(3)) and returns an array
** of strings obtained by splitting ’s’ using the
** character ’c’ as a delimiter. The array must be
** ended by a NULL pointer.
*/

void	ft_free_spl(char **splited, size_t k)
{
	while (k > 0)
	{
		k--;
		free(splited[k]);
	}
	free(splited[k]);
}

void	**ft_write_words(char *str, char c, char **splited, size_t count)
{
	size_t start;
	size_t end;
	size_t i;
	size_t k;

	i = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		start = i;
		while (str[i] != c && str[i] != 0)
			i++;
		end = i - 1;
		if (k < count)
		{
			splited[k] = ft_substr(str, start, end - start + 1);
			if (splited[k] == NULL)
				ft_free_spl(splited, k);
		}
		k++;
	}
	return (NULL);
}

size_t	ft_how_many_words(char *s, char c)
{
	size_t i;
	size_t words;

	i = 0;
	words = 0;
	while (s[i] == c && s[i])
		i++;
	if (s[i] != c && s[i])
	{
		while (s[i])
		{
			if (s[i] == c)
			{
				while (s[i] == c && s[i])
					i++;
				if (s[i])
					words++;
			}
			else
				i++;
		}
	}
	else
		return (0);
	return (words + 1);
}

char	**ft_split(char const *s, char c)
{
	char	**splited;
	char	*str;
	size_t	count;

	if (s == NULL)
		return (NULL);
	if (!(str = ft_strdup((char *)s)))
		return (NULL);
	count = ft_how_many_words(str, c);
	if (!(splited = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	if (count)
		ft_write_words(str, c, splited, count);
	if (splited)
		splited[count] = NULL;
	free(str);
	return (splited);
}
