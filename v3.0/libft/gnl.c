/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 22:53:45 by fjewfish          #+#    #+#             */
/*   Updated: 2020/09/22 21:39:54 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_join_bufpart(char **bufpart, char **eol)
{
	char		*line;

	if (!(*bufpart))
	{
		if (!(*bufpart = ft_calloc(BUFFER_SIZE, sizeof(char))))
			return (NULL);
	}
	if ((*eol = gnl_ft_strchr(*bufpart)))
	{
		**eol = '\0';
		if (!(line = ft_strdup(*bufpart)))
			return (NULL);
		ft_strcpy(*bufpart, ++(*eol));
	}
	else
	{
		if (!(line = calloc((ft_strlen(*bufpart) + 1), sizeof(char))))
			return (NULL);
		ft_strcpy(line, *bufpart);
	}
	return (line);
}

int				ft_what_to_return(int length_b, char **bufpart, int case_1)
{
	if (length_b == 0)
	{
		if (*bufpart)
			free(*bufpart);
		*bufpart = NULL;
		return (0);
	}
	if (length_b == -1 || case_1 == 1)
	{
		if (*bufpart)
			free(*bufpart);
		*bufpart = NULL;
		return (-1);
	}
	return (1);
}

int				get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*bufpart;
	int			length_b;
	char		*eol;
	char		*clear;

	eol = NULL;
	length_b = -2;
	if (!(*line = ft_join_bufpart(&bufpart, &eol)) || fd < 0 || BUFFER_SIZE < 1)
		return (ft_what_to_return(length_b, &bufpart, 1));
	while (!eol && ((length_b = read(fd, buf, BUFFER_SIZE)) > 0))
	{
		buf[length_b] = '\0';
		if ((eol = gnl_ft_strchr(buf)))
		{
			*eol = '\0';
			ft_strcpy(bufpart, ++eol);
		}
		clear = *line;
		if (!(*line = ft_strjoin(*line, buf)))
			return (-1);
		if (clear)
			free(clear);
	}
	return (ft_what_to_return(length_b, &bufpart, 2));
}
