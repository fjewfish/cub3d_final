/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corozco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 00:53:42 by corozco           #+#    #+#             */
/*   Updated: 2020/02/11 00:59:46 by corozco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		check_no_wall(t_data *d)
{
	if (d->rtc.side == 0 || d->rtc.side == 2)
		d->rtc.perpwalldist = (double)(d->rtc.mapx - d->pl.posx
		+ (1 - d->rtc.stepx) / 2.0) / d->rtc.raydirx;
	else
		d->rtc.perpwalldist = (double)(d->rtc.mapy - d->pl.posy
		+ (1 - d->rtc.stepy) / 2.0) / d->rtc.raydiry;
}

void			perform_dda(t_data *d, int hit)
{
	while (hit == 0)
	{
		if (d->rtc.sidedistx < d->rtc.sidedisty)
		{
			d->rtc.sidedistx += d->rtc.deltadistx;
			d->rtc.mapx += d->rtc.stepx;
			if (d->rtc.raydirx < 0)
				d->rtc.side = 0;
			else
				d->rtc.side = 2;
		}
		else
		{
			d->rtc.sidedisty += d->rtc.deltadisty;
			d->rtc.mapy += d->rtc.stepy;
			if (d->rtc.raydiry < 0)
				d->rtc.side = 1;
			else
				d->rtc.side = 3;
		}
		if ((d->map.map[d->rtc.mapy][d->rtc.mapx] > 0
		&& d->map.map[d->rtc.mapy][d->rtc.mapx] < 2))
			hit = 1;
	}
	check_no_wall(d);
}
