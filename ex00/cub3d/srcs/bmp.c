/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corozco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 02:05:01 by corozco           #+#    #+#             */
/*   Updated: 2020/02/14 00:34:55 by corozco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void	fill_bmp(char **data, t_data *d)
{
	int i;
	int j;
	int x;
	int y;

	i = 122;
	y = d->res.r_y;
	while (y--)
	{
		x = -1;
		while (++x < d->res.r_x)
		{
			j = (x * (d->img.bpp / 8)) + (y * d->img.size_l);
			*(*data + i++) = *((char *)d->img.data + j++);
			*(*data + i++) = *((char *)d->img.data + j++);
			*(*data + i++) = *((char *)d->img.data + j);
		}
	}
}

void	header_bmp(char **data, t_data *d)
{
	unsigned int size;

	size = d->res.r_y * d->res.r_x * 3;
	*(unsigned short *)*data = *(const unsigned int *)(unsigned long)"BM";
	*(unsigned int *)(*data + 2) = (size + 122);
	*(unsigned int *)(*data + 6) = 0u;
	*(unsigned char *)(*data + 10) = 122;
	*(unsigned int *)(*data + 14) = 122 - 14;
	*(unsigned int *)(*data + 18) = d->res.r_x;
	*(unsigned int *)(*data + 22) = d->res.r_y;
	*(unsigned short *)(*data + 26) = 1;
	*(unsigned short *)(*data + 28) = 24;
	*(unsigned int *)(*data + 30) = 0;
	*(unsigned int *)(*data + 34) = (unsigned int)size;
	*(unsigned int *)(*data + 38) = 3780;
	*(unsigned int *)(*data + 42) = 3780;
	*(int *)(*data + 46) = 0;
	*(int *)(*data + 50) = 0;
}

void	export_bmp(char *filename, t_data *d)
{
	int				fd;
	unsigned int	size;
	unsigned int	i;
	char			*data;

	size = d->res.r_y * d->res.r_x * 3;
	if (!(data = malloc((size + 122))))
		free_coordinates(d, "  -Allocating memory", 0);
	i = 0;
	while (i < size + 122)
		data[i++] = 0;
	header_bmp(&data, d);
	fill_bmp(&data, d);
	if ((fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644)) <= 0)
		free_coordinates(d, "  -Cannot create/Trunc/Write in file .bmp", 0);
	write(fd, data, (size + 122));
	close(fd);
	exit(0);
}

char	*create_bmp_filename(char *file, int i, t_data *d)
{
	char		*filename;
	int			n;

	if (!(filename = malloc(sizeof(char) * (i + 5))))
		free_coordinates(d, "  -Allocating memory", 0);
	n = -1;
	while (++n <= i)
		*(filename + n) = *(file + n);
	*(unsigned int *)(filename + n) =
	*(const unsigned int *)(unsigned long)"bmp\0";
	return (filename);
}
