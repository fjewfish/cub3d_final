/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corozco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 01:11:16 by corozco           #+#    #+#             */
/*   Updated: 2020/02/11 01:25:12 by corozco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			draw_sky(t_data *d)
{
	int			x;
	int			y;
	int			ctmp;

	x = -1;
	while (++x < d->res.r_x)
	{
		y = -1;
		while (++y < d->res.r_y / 2)
		{
			ctmp = d->txt[4].data[y % 1366 * 1366 + x % 1366];
			d->img.data[y * d->res.r_x + x] = ctmp;
		}
	}
}

static void		value_wall(t_data *d)
{
	if (d->rtc.side == 0 || d->rtc.side == 2)
		d->rtc.wallx = d->pl.posy + d->rtc.perpwalldist * d->rtc.raydiry;
	else
		d->rtc.wallx = d->pl.posx + d->rtc.perpwalldist * d->rtc.raydirx;
	d->rtc.wallx -= (int)(d->rtc.wallx);
	d->rtc.texx = (int)(d->rtc.wallx * (double)TEXS);
	if ((d->rtc.side == 0 || d->rtc.side == 2) && d->rtc.raydirx > 0)
		d->rtc.texx = TEXS - d->rtc.texx - 1;
	if ((d->rtc.side == 1 || d->rtc.side == 3) && d->rtc.raydiry < 0)
		d->rtc.texx = TEXS - d->rtc.texx - 1;
}

void			draw_wall(t_data *d, int x, int y, int texy)
{
	if ((d->rtc.side == 0 || d->rtc.side == 2) && d->rtc.raydirx >= 0)
		d->rtc.texnum = 3;
	else if ((d->rtc.side == 0 || d->rtc.side == 2) && d->rtc.raydirx < 0)
		d->rtc.texnum = 2;
	else if ((d->rtc.side == 1 || d->rtc.side == 3) && d->rtc.raydiry < 0)
		d->rtc.texnum = 0;
	else
		d->rtc.texnum = 1;
	y = d->rtc.drawstart;
	value_wall(d);
	while (y <= d->rtc.drawend)
	{
		texy = (((y - (d->res.r_y / 2) + (d->rtc.lineheight / 2)) * TEXS)
		/ d->rtc.lineheight);
		d->rtc.color = d->txt[d->rtc.texnum].data[TEXS * texy + d->rtc.texx];
		d->img.data[y++ * d->res.r_x + x] = d->rtc.color;
	}
}

static void		possible_directions(t_data *d)
{
	if (d->rtc.side == 2)
	{
		d->flr.floorxwall = d->rtc.mapx;
		d->flr.floorywall = d->rtc.mapy + d->rtc.wallx;
	}
	else if (d->rtc.side == 0)
	{
		d->flr.floorxwall = d->rtc.mapx + 1.0;
		d->flr.floorywall = d->rtc.mapy + d->rtc.wallx;
	}
	else if (d->rtc.side == 3)
	{
		d->flr.floorxwall = d->rtc.mapx + d->rtc.wallx;
		d->flr.floorywall = d->rtc.mapy;
	}
	else if (d->rtc.side == 1)
	{
		d->flr.floorxwall = d->rtc.mapx + d->rtc.wallx;
		d->flr.floorywall = d->rtc.mapy + 1.0;
	}
}

void			draw_floor(t_data *d, int x)
{
	int y;

	x = (d->res.r_x - 1) - x;
	y = d->rtc.drawend;
	possible_directions(d);
	d->flr.distplayer = 0.0;
	while (y < d->res.r_y)
	{
		d->flr.currentdist = d->res.r_y / (2.0 * y - d->res.r_y);
		d->flr.weight = (d->flr.currentdist - d->flr.distplayer) /
		(d->rtc.perpwalldist - d->flr.distplayer);
		d->flr.currentfloorx = d->flr.weight * d->flr.floorxwall +
		(1.0 - d->flr.weight) * d->pl.posx;
		d->flr.currentfloory = d->flr.weight * d->flr.floorywall +
		(1.0 - d->flr.weight) * d->pl.posy;
		d->flr.floortexx = (int)(d->flr.currentfloorx * TEXS) % TEXS;
		d->flr.floortexy = (int)(d->flr.currentfloory * TEXS) % TEXS;
		d->rtc.color = d->txt[6].data[TEXS * d->flr.floortexy
			+ d->flr.floortexx];
		d->img.data[y * d->res.r_x + x] = d->rtc.color;
		y++;
	}
}
