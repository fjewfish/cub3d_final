/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corozco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 23:36:57 by corozco           #+#    #+#             */
/*   Updated: 2020/02/14 00:36:20 by corozco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		move3(t_data *d)
{
	if (d->move.eright == 1)
	{
		if (d->map.map[(int)(d->pl.posy + d->pl.dirx * d->sp)]
		[(int)(d->pl.posx)] == 0 || d->map.map[(int)(d->pl.posy
		+ d->pl.dirx * d->sp)][(int)(d->pl.posx)] == 3)
			d->pl.posy -= -d->pl.dirx * d->sp;
		if (d->map.map[(int)(d->pl.posy)][(int)(d->pl.posx - d->pl.diry
		* d->sp)] == 0 || d->map.map[(int)(d->pl.posy)]
		[(int)(d->pl.posx - d->pl.diry * d->sp)] == 3)
			d->pl.posx -= d->pl.diry * d->sp;
	}
	if (d->move.qleft == 1)
	{
		if (d->map.map[(int)(d->pl.posy - d->pl.dirx * d->sp)]
		[(int)(d->pl.posx)] == 0 || d->map.map[(int)(d->pl.posy - d->pl.dirx
		* d->sp)][(int)(d->pl.posx)] == 3)
			d->pl.posy += -d->pl.dirx * d->sp;
		if (d->map.map[(int)(d->pl.posy)][(int)(d->pl.posx + d->pl.diry
		* d->sp)] == 0 || d->map.map[(int)(d->pl.posy)]
		[(int)(d->pl.posx + d->pl.diry * d->sp)] == 3)
			d->pl.posx += d->pl.diry * d->sp;
	}
}

static void		move2(t_data *d)
{
	if (d->move.left == 1)
	{
		d->pl.olddirx = d->pl.dirx;
		d->pl.dirx = d->pl.dirx * cos(-d->rt) - d->pl.diry * sin(-d->rt);
		d->pl.diry = d->pl.olddirx * sin(-d->rt) + d->pl.diry * cos(-d->rt);
		d->pl.oldplanex = d->pl.planex;
		d->pl.planex = d->pl.planex * cos(-d->rt) - d->pl.planey * sin(-d->rt);
		d->pl.planey = d->pl.oldplanex * sin(-d->rt)
			+ d->pl.planey * cos(-d->rt);
	}
	if (d->move.right == 1)
	{
		d->pl.olddirx = d->pl.dirx;
		d->pl.dirx = d->pl.dirx * cos(d->rt) - d->pl.diry * sin(d->rt);
		d->pl.diry = d->pl.olddirx * sin(d->rt) + d->pl.diry * cos(d->rt);
		d->pl.oldplanex = d->pl.planex;
		d->pl.planex = d->pl.planex * cos(d->rt) - d->pl.planey * sin(d->rt);
		d->pl.planey = d->pl.oldplanex * sin(d->rt) + d->pl.planey * cos(d->rt);
	}
}

int				move(t_data *d)
{
	if (d->move.up == 1)
	{
		if (d->map.map[(int)(d->pl.posy)][(int)(d->pl.posx + d->pl.dirx
		* d->sp)] == 0 || d->map.map[(int)(d->pl.posy)][(int)(d->pl.posx
		+ d->pl.dirx * d->sp)] == 3)
			d->pl.posx += d->pl.dirx * d->sp;
		if (d->map.map[(int)(d->pl.posy + d->pl.diry * d->sp)]
		[(int)(d->pl.posx)] == 0 || d->map.map[(int)(d->pl.posy + d->pl.diry
		* d->sp)][(int)(d->pl.posx)] == 3)
			d->pl.posy += d->pl.diry * d->sp;
	}
	if (d->move.down == 1)
	{
		if (d->map.map[(int)(d->pl.posy)][(int)(d->pl.posx - d->pl.dirx
		* d->sp)] == 0 || d->map.map[(int)(d->pl.posy)][(int)(d->pl.posx
		- d->pl.dirx * d->sp)] == 3)
			d->pl.posx -= d->pl.dirx * d->sp;
		if (d->map.map[(int)(d->pl.posy - d->pl.diry * d->sp)]
		[(int)(d->pl.posx)] == 0 || d->map.map[(int)(d->pl.posy
		- d->pl.diry * d->sp)][(int)(d->pl.posx)] == 3)
			d->pl.posy -= d->pl.diry * d->sp;
	}
	move2(d);
	move3(d);
	return (0);
}
