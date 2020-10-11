/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corozco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 01:42:21 by corozco           #+#    #+#             */
/*   Updated: 2020/02/13 01:53:55 by corozco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>
#include <unistd.h>

static void		open_file_texture3(int fd)
{
	if ((fd = open(LIFE0, O_RDONLY)) == -1)
		ft_ms_error(0, "  -File texture corrupted.", (void *)0);
	close(fd);
	if ((fd = open(LIFE1, O_RDONLY)) == -1)
		ft_ms_error(0, "  -File texture corrupted.", (void *)0);
	close(fd);
	if ((fd = open(LIFE2, O_RDONLY)) == -1)
		ft_ms_error(0, "  -File texture corrupted.", (void *)0);
	close(fd);
	if ((fd = open(LIFE3, O_RDONLY)) == -1)
		ft_ms_error(0, "  -File texture corrupted.", (void *)0);
	close(fd);
	if ((fd = open(LIFE4, O_RDONLY)) == -1)
		ft_ms_error(0, "  -File texture corrupted.", (void *)0);
	close(fd);
	if ((fd = open(LIFE5, O_RDONLY)) == -1)
		ft_ms_error(0, "  -File texture corrupted.", (void *)0);
	close(fd);
	if ((fd = open(GAMEOVER, O_RDONLY)) == -1)
		ft_ms_error(0, "  -File texture corrupted.", (void *)0);
	close(fd);
}

static void		open_file_texture2(t_data *d, int fd)
{
	if ((fd = open(d->tex.hand1, O_RDONLY)) == -1)
		ft_ms_error(0, "  -File texture corrupted.", (void *)0);
	close(fd);
	if ((fd = open(d->tex.hand2, O_RDONLY)) == -1)
		ft_ms_error(0, "  -File texture corrupted.", (void *)0);
	close(fd);
	if ((fd = open(d->tex.hand3, O_RDONLY)) == -1)
		ft_ms_error(0, "  -File texture corrupted.", (void *)0);
	close(fd);
	if ((fd = open(POISON, O_RDONLY)) == -1)
		ft_ms_error(0, "  -File texture corrupted.", (void *)0);
	close(fd);
	open_file_texture3(fd);
}

void			open_file_texture(t_data *d, int fd)
{
	if ((fd = open(d->tex.north, O_RDONLY)) == -1)
		ft_ms_error(0, "  -File texture corrupted.", (void *)0);
	close(fd);
	if ((fd = open(d->tex.south, O_RDONLY)) == -1)
		ft_ms_error(0, "  -File texture corrupted.", (void *)0);
	close(fd);
	if ((fd = open(d->tex.east, O_RDONLY)) == -1)
		ft_ms_error(0, "  -File texture corrupted.", (void *)0);
	close(fd);
	if ((fd = open(d->tex.west, O_RDONLY)) == -1)
		ft_ms_error(0, "  -File texture corrupted.", (void *)0);
	close(fd);
	if ((fd = open(d->tex.sky, O_RDONLY)) == -1)
		ft_ms_error(0, "  -File texture corrupted.", (void *)0);
	close(fd);
	if ((fd = open(d->tex.sprite, O_RDONLY)) == -1)
		ft_ms_error(0, "  -File texture corrupted.", (void *)0);
	close(fd);
	if ((fd = open(d->tex.floor, O_RDONLY)) == -1)
		ft_ms_error(0, "  -File texture corrupted.", (void *)0);
	close(fd);
	open_file_texture2(d, fd);
}
