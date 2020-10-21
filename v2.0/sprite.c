/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 00:59:02 by fjewfish          #+#    #+#             */
/*   Updated: 2020/10/21 16:53:17 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header_v2.h"

#include <stdio.h>
int				ft_slist(t_aio *aio);
void			ft_sprite(t_aio *aio);
void			ft_sorder(t_aio *aio);
void			ft_slocate(t_aio *aio, double dirx, double diry, double dist);
void			ft_sdraw(t_aio *aio, int loc, double dist);
unsigned int	ft_spixel(t_aio *aio, int index, unsigned int col, int x);

int		ft_slist(t_aio *aio)
{
	int		i;
	int		j;
	int		k;

	//if (aio->spr != NULL)
	//	free(aio->spr);
	if (!(aio->spr = malloc(sizeof(t_spr) * aio->map.sprite_count)))
		return (-1);
	i = 0;
	j = 0;
	while (j < aio->map.height)
	{
		k = 0;
		while (k < aio->map.width)
		{
			if (aio->map.map[j][k] == '2')
			{
				aio->spr[i].y = (double)j + 0.5;
				aio->spr[i++].x = (double)k + 0.5;
			}
			k++;
		}
		j++;
	}
	return (1);
}

void			ft_sprite(t_aio *aio)
{
	int		i;
	double	dist;

	dist = hypot(aio->plr.dir_x, aio->plr.dir_y);
	if (aio->plr.dir_y <= 0)
		aio->plr.dir_a = acos(aio->plr.dir_x / dist) * 180 / M_PI;
	else
		aio->plr.dir_a = 360 - acos(aio->plr.dir_x / dist) * 180 / M_PI;
	i = 0;
	while (i < aio->map.sprite_count)
	{
		aio->spr[i].d = hypot(aio->spr[i].x - aio->plr.pos_x, aio->spr[i].y - aio->plr.pos_y);
		i++;
	}
	ft_sorder(aio);
	i = 0;
	while (i < aio->map.sprite_count)
	{
		ft_slocate(aio, aio->spr[i].x, aio->spr[i].y, aio->spr[i].d);
		i++;
	}
	//free(aio->stk);
}

void			ft_sorder(t_aio *aio)
{
	t_spr	tmp;
	int		i;
	int		j;

	i = 0;
	while (i < aio->map.sprite_count - 1)
	{
		j = i + 1;
		while (j < aio->map.sprite_count)
		{
			if (aio->spr[i].d < aio->spr[j].d)
			{
				tmp = aio->spr[i];
				aio->spr[i] = aio->spr[j];
				aio->spr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void			ft_slocate(t_aio *aio, double dirx, double diry, double dist)
{
	double	angle;

	dirx = (dirx - aio->plr.pos_x) / dist;
	diry = (diry - aio->plr.pos_y) / dist;
	if (diry <= 0)
		angle = acos(dirx) * 180 / M_PI;
	else
		angle = 360 - acos(dirx) * 180 / M_PI;
	angle = aio->plr.dir_a - angle + 33;
	if (angle >= 180)
		angle -= 360;
	else if (angle <= -180)
		angle += 360;
printf("\nX-%f,  Y-%f, D-%f\n", aio->spr->x, aio->spr->y, aio->spr->d);
	ft_sdraw(aio, angle * aio->res.map_x / 66, dist);
}

void			ft_sdraw(t_aio *aio, int loc, double dist)
{
	unsigned int	col;
	double			size;
	int				index;
	int				y;
	int				x;

	y = 0;
	x = 0;
	size = aio->res.map_y / dist / 2;
	loc = loc - size / 2;
	while (y < size)
	{
		while ((loc + y >= 0 && loc + y < aio->res.map_x) &&
				(x < size && aio->stk[loc + y].d > dist))
		{
			col = 64 * floor(64 * (double)x / size) + (double)y / size * 64;
			col = aio->tex.sp[col];
			index = loc + y + (aio->res.map_y / 2 + x) * aio->res.map_x + x*aio->img.coef_dylib;
			if (index < (aio->res.map_x * aio->res.map_y + x*aio->img.coef_dylib))
				aio->img.adr[index] = GREEN;
				//aio->img.adr[index] = ft_spixel(aio, index, col, x);
			x++;
		}
		y++;
		x = 0;
	}
}

unsigned int	ft_spixel(t_aio *aio, int index, unsigned int col, int x)
{
	int	t;
	int	r;
	int	g;
	int	b;

	if (col >= 0xFF000000)
		return (aio->img.adr[index]);
	else if (col < 256 * 256 * 256)
		return (col);
	t = col / (256 * 256 * 256);
	r = (col / (256 * 256) % 256) * (1 - (double)t / 256);
	g = (col / 256 % 256) * (1 - (double)t / 256);
	b = (col % 256) * (1 - (double)t / 256);
	r += (aio->img.adr[index] / (256 * 256) % 256) * ((double)t / 256);
	g += (aio->img.adr[index] / 256 % 256) * ((double)t / 256);
	b += (aio->img.adr[index] % 256) * ((double)t / 256);
	return (r * 256 * 256 + g * 256 + b);
}
