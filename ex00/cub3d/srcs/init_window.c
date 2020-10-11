/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corozco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 08:15:26 by corozco           #+#    #+#             */
/*   Updated: 2020/02/14 03:04:06 by corozco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		xpm_null(t_data *d)
{
	int i;

	i = -1;
	while (++i < 18)
		if (d->txt[i].img_ptr == NULL)
			ft_ms_error(0, "  -File corrupted.", (void *)0);
}

static void		textures2(t_data *d)
{
	int i;

	d->txt[12].img_ptr = mlx_xpm_file_to_image(d->mlx_ptr, LIFE1,
	&d->txt[12].size_l, &d->txt[12].endian);
	d->txt[13].img_ptr = mlx_xpm_file_to_image(d->mlx_ptr, LIFE2,
	&d->txt[13].size_l, &d->txt[13].endian);
	d->txt[14].img_ptr = mlx_xpm_file_to_image(d->mlx_ptr, LIFE3,
	&d->txt[14].size_l, &d->txt[14].endian);
	d->txt[15].img_ptr = mlx_xpm_file_to_image(d->mlx_ptr, LIFE4,
	&d->txt[15].size_l, &d->txt[15].endian);
	d->txt[16].img_ptr = mlx_xpm_file_to_image(d->mlx_ptr, LIFE5,
	&d->txt[16].size_l, &d->txt[16].endian);
	d->txt[17].img_ptr = mlx_xpm_file_to_image(d->mlx_ptr, POISON,
	&d->txt[17].size_l, &d->txt[17].endian);
	xpm_null(d);
	i = -1;
	while (++i < 18)
		d->txt[i].data = (int *)mlx_get_data_addr(d->txt[i].img_ptr,
		&d->txt[i].bpp, &d->txt[i].size_l, &d->txt[i].endian);
}

static void		textures(t_data *d)
{
	d->txt[0].img_ptr = mlx_xpm_file_to_image(d->mlx_ptr, d->tex.north,
	&d->txt[0].size_l, &d->txt[0].endian);
	d->txt[1].img_ptr = mlx_xpm_file_to_image(d->mlx_ptr, d->tex.south,
	&d->txt[1].size_l, &d->txt[1].endian);
	d->txt[2].img_ptr = mlx_xpm_file_to_image(d->mlx_ptr, d->tex.west,
	&d->txt[2].size_l, &d->txt[2].endian);
	d->txt[3].img_ptr = mlx_xpm_file_to_image(d->mlx_ptr, d->tex.east,
	&d->txt[3].size_l, &d->txt[3].endian);
	d->txt[4].img_ptr = mlx_xpm_file_to_image(d->mlx_ptr, d->tex.sky,
	&d->txt[4].size_l, &d->txt[4].endian);
	d->txt[5].img_ptr = mlx_xpm_file_to_image(d->mlx_ptr, d->tex.sprite,
	&d->txt[5].size_l, &d->txt[5].endian);
	d->txt[6].img_ptr = mlx_xpm_file_to_image(d->mlx_ptr, d->tex.floor,
	&d->txt[6].size_l, &d->txt[6].endian);
	d->txt[7].img_ptr = mlx_xpm_file_to_image(d->mlx_ptr, d->tex.hand1,
	&d->txt[7].size_l, &d->txt[7].endian);
	d->txt[8].img_ptr = mlx_xpm_file_to_image(d->mlx_ptr, d->tex.hand2,
	&d->txt[8].size_l, &d->txt[8].endian);
	d->txt[9].img_ptr = mlx_xpm_file_to_image(d->mlx_ptr, d->tex.hand3,
	&d->txt[9].size_l, &d->txt[9].endian);
	d->txt[10].img_ptr = mlx_xpm_file_to_image(d->mlx_ptr, GAMEOVER,
	&d->txt[10].size_l, &d->txt[10].endian);
	d->txt[11].img_ptr = mlx_xpm_file_to_image(d->mlx_ptr, LIFE0,
	&d->txt[11].size_l, &d->txt[11].endian);
	textures2(d);
}

void			init(t_data *d)
{
	d->mlx_ptr = mlx_init();
	d->win_ptr = mlx_new_window(d->mlx_ptr, d->res.r_x, d->res.r_y, "Cub3D");
	d->img.img_ptr = mlx_new_image(d->mlx_ptr, d->res.r_x, d->res.r_y);
	d->img.data = (int *)mlx_get_data_addr(d->img.img_ptr,
	&d->img.bpp, &d->img.size_l, &d->img.endian);
	textures(d);
}
