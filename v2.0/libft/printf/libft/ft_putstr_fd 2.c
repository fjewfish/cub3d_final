/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 01:19:12 by fjewfish          #+#    #+#             */
/*   Updated: 2020/06/03 01:19:15 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Parameters
** #1. The string to output.
** #2. The file descriptor on which to write.
** Description
** Outputs the string ’s’ to the given file
** descriptor.
*/

void	ft_putstr_fd(char *s, int fd)
{
	if (fd >= 0 && s)
	{
		write(fd, s, ft_strlen(s));
	}
}
