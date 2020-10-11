/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corozco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 01:09:02 by corozco           #+#    #+#             */
/*   Updated: 2020/02/11 22:10:53 by corozco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		length_ray(t_data *d)
{
	d->rtc.camerax = 2.0 * (double)d->rtc.ln / (double)d->res.r_x - 1.0;
	d->rtc.raydirx = d->pl.dirx + d->pl.planex * d->rtc.camerax;
	d->rtc.raydiry = d->pl.diry + d->pl.planey * d->rtc.camerax;
	d->rtc.mapx = (int)(d->pl.posx);
	d->rtc.mapy = (int)(d->pl.posy);
	d->rtc.deltadistx = fabs(1 / d->rtc.raydirx);
	d->rtc.deltadisty = fabs(1 / d->rtc.raydiry);
}

static void		initial_sidedist(t_data *d)
{
	if (d->rtc.raydirx < 0)
	{
		d->rtc.stepx = -1;
		d->rtc.sidedistx = (d->pl.posx - d->rtc.mapx) * d->rtc.deltadistx;
	}
	else
	{
		d->rtc.stepx = 1;
		d->rtc.sidedistx = (d->rtc.mapx + 1.0 - d->pl.posx) * d->rtc.deltadistx;
	}
	if (d->rtc.raydiry < 0)
	{
		d->rtc.stepy = -1;
		d->rtc.sidedisty = (d->pl.posy - d->rtc.mapy) * d->rtc.deltadisty;
	}
	else
	{
		d->rtc.stepy = 1;
		d->rtc.sidedisty = (d->rtc.mapy + 1.0 - d->pl.posy) * d->rtc.deltadisty;
	}
}

static void		lowest_highest_pixel(t_data *d, int x)
{
	x = (d->res.r_x - 1) - x;
	d->zbuffer[x] = d->rtc.perpwalldist;
	d->rtc.lineheight = (int)(d->res.r_y / d->rtc.perpwalldist);
	d->rtc.drawstart = -1 * d->rtc.lineheight / 2 + d->res.r_y / 2;
	if (d->rtc.drawstart < 0)
		d->rtc.drawstart = 0;
	d->rtc.drawend = d->rtc.lineheight / 2 + d->res.r_y / 2;
	if (d->rtc.drawend >= d->res.r_y)
		d->rtc.drawend = d->res.r_y - 1;
}

static void		put_image(t_data *d)
{
	if (d->map.map[(int)d->pl.posy][(int)d->pl.posx] == 3)
	{
		d->map.map[(int)d->pl.posy][(int)d->pl.posx] = 0;
		d->pl.life -= 1;
	}
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img.img_ptr, 0, 0);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr,
	d->txt[7 + d->pl.mobile].img_ptr, d->res.r_x / 2 - 700, d->res.r_y - 930);
	if (d->pl.mobile == 1)
		d->pl.mobile = 2;
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr,
		d->txt[11 + d->pl.life].img_ptr, 0, 0);
	if (d->pl.life == 0)
	{
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr,
		d->txt[10].img_ptr, 1 / 2, 0);
		d->sp = 0.0;
		d->rt = 0.0;
	}
}

int				raycasting(t_data *d)
{
	d->rtc.ln = -1;
	draw_sky(d);
	while (++d->rtc.ln < d->res.r_x)
	{
		length_ray(d);
		initial_sidedist(d);
		perform_dda(d, 0);
		lowest_highest_pixel(d, d->rtc.ln);
		draw_wall(d, (d->res.r_x - 1) - d->rtc.ln, 0, 0);
		draw_floor(d, d->rtc.ln);
	}
	sprites_casting(d, -1);
	move(d);
	put_image(d);
	return (0);
}
