/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_casting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corozco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 22:15:38 by corozco           #+#    #+#             */
/*   Updated: 2020/02/11 23:25:06 by corozco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void			sort_sprite(t_data *d, int k, int i)
{
	t_spr		temp;

	while (k == 1)
	{
		k = 0;
		i = -1;
		while (++i < d->sprcount - 1)
		{
			if (d->sprite[i].spritedist < d->sprite[i + 1].spritedist)
			{
				temp = d->sprite[i];
				d->sprite[i] = d->sprite[i + 1];
				d->sprite[i + 1] = temp;
				k = 1;
				break ;
			}
		}
	}
}

static void			calculate_lowest(t_data *d)
{
	d->drawstarty = -d->spriteheight / 2 + d->res.r_y / 2;
	d->drawstarty = d->drawstarty < 0 ? 0 : d->drawstarty;
	d->drawendy = d->spriteheight / 2 + d->res.r_y / 2;
	d->drawendy = d->drawendy >= d->res.r_y ? d->res.r_y - 1 : d->drawendy;
	d->spritewidth = (int)fabs(d->res.r_y / d->transformy);
	d->drawstartx = -d->spritewidth / 2 + d->spritescreenx;
	d->drawstartx = d->drawstartx < 0 ? 0 : d->drawstartx;
	d->drawendx = d->spritewidth / 2 + d->spritescreenx;
	d->drawendx = d->drawendx >= d->res.r_x ? d->res.r_x - 1
	: d->drawendx;
}

static void			translate_sprite(t_data *d, int j, double idev)
{
	d->spritex = d->sprite[j].x - d->pl.posx;
	d->spritey = d->sprite[j].y - d->pl.posy;
	idev = 1.0 / (d->pl.planex * d->pl.diry - d->pl.dirx * d->pl.planey);
	d->transformx = idev * (d->pl.diry * d->spritex - d->pl.dirx * d->spritey);
	d->transformy = idev * (-d->pl.planey * d->spritex
		+ d->pl.planex * d->spritey);
	d->spritescreenx = (int)((d->res.r_x / 2)
		* (1 + d->transformx / d->transformy));
	d->spritescreenx = d->res.r_x - 1 - d->spritescreenx;
	d->spriteheight = (int)fabs(d->res.r_y / d->transformy);
	calculate_lowest(d);
}

static void			draw_sprite(t_data *d, int stripe, int k, int t)
{
	stripe = d->drawstartx;
	while (stripe < d->drawendx)
	{
		k = d->drawstarty;
		d->rtc.texx = (int)((stripe - (d->spritescreenx - d->spritewidth / 2))
		* TEXS / d->spritewidth);
		if (d->transformy > 0 && stripe > 0 && stripe < d->res.r_x
		&& d->transformy < d->zbuffer[stripe])
			while (k < d->drawendy)
			{
				d->texy = (k - d->res.r_y / 2 + d->spriteheight / 2) * TEXS
				/ d->spriteheight;
				d->rtc.color = d->txt[d->sprite[t].texture].data[TEXS * d->texy
				+ d->rtc.texx];
				if (d->rtc.color != 0xFFFFFF)
					d->img.data[k * d->res.r_x + stripe] = d->rtc.color;
				k++;
			}
		stripe++;
	}
}

void				sprites_casting(t_data *d, int i)
{
	while (++i < d->sprcount)
		d->sprite[i].spritedist = (d->pl.posx - d->sprite[i].x)
		* (-d->sprite[i].x + d->pl.posx) + (d->pl.posy - d->sprite[i].y)
		* (d->pl.posy - d->sprite[i].y);
	sort_sprite(d, 1, 0);
	i = -1;
	while (++i < d->sprcount)
	{
		translate_sprite(d, i, 0.0);
		draw_sprite(d, 0, 0, i);
	}
}
