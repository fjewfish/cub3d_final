/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corozco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 16:07:50 by corozco           #+#    #+#             */
/*   Updated: 2020/02/14 00:30:13 by corozco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>
#include <unistd.h>

static void			resolution(t_data *d)
{
	d->map.error = 0;
	d->tmps.cmp_map = 0;
	d->map.y = 0;
	d->map.boolean = 0;
	d->move.up = 0;
	d->move.down = 0;
	d->move.left = 0;
	d->move.right = 0;
	d->move.qleft = 0;
	d->move.eright = 0;
	d->sp = 0.0500001;
	d->rt = 0.06;
	d->sprcount = 0;
	d->cmp_sp = 0;
	d->pl.mobile = 0;
	d->pl.life = 5;
	d->tex.resolu = 0;
}

static void			ft_cont_map(char *av, t_data *d)
{
	int				fd;
	char			*line;

	if ((fd = open(av, O_RDONLY)) == -1)
		ft_ms_error(0, "  -Could not open file.", (void *)0);
	d->tmps.cmp_map = 0;
	while ((d->tmps.ret = ft_gnl(fd, &line)) > 0)
	{
		if (line[0] == 0)
		{
			free(line);
			continue ;
		}
		d->tmps.cmp_map += 1;
		free(line);
	}
	if (line[0] != 0)
		d->tmps.cmp_map += 1;
	free(line);
	close(fd);
	d->tmps.cmp_map -= 11;
	if (d->tmps.cmp_map < 4)
		ft_ms_error(0, "  -Map corrupted.", (void *)0);
}

void				ft_init_map(char *av, t_data *d)
{
	int				fd;

	resolution(d);
	ft_cont_map(av, d);
	if (!(d->map.map = (int **)malloc(sizeof(int *) * d->tmps.cmp_map)))
		free_coordinates(d, "  -Allocating memory", 0);
	if ((fd = open(av, O_RDONLY)) == -1)
		ft_ms_error(0, "  -Could not open file.", (void *)0);
	if (init_parser(fd, d) == -1)
		ft_ms_error(0, "  -Reading from file.", (void *)0);
	close(fd);
	if (d->map.boolean == 0 || d->map.boolean > 1)
		free_map(d, d->map.y - 1, "  -Multiple positions.");
	if (!(d->sprite = (t_spr *)malloc(sizeof(t_spr) * d->sprcount)))
		free_map(d, d->map.y - 1, "  -Allocating memory (sprites)");
	ft_verif(d, d->map.map, 0, d->map.x);
}
