/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b1_initialization.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <fjewfish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 17:34:02 by fjewfish          #+#    #+#             */
/*   Updated: 2020/10/16 04:10:58 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header_v2.h"

void		ft_initialization(t_aio *aio)
{
	aio->parse_error.map_empty_line = 0;
	aio->parse_error.map_trigger = 0;
	aio->parse_error.player = 0;
	aio ->parse_error.settings = 0;
	aio->mapmod.on_off = 0;
	aio->mapmod.first_hit_x = 0;
	aio->mapmod.first_hit_y = 0;
	aio->mapmod.last_hit_x = 0;
	aio->mapmod.last_hit_y = 0;
	aio->mlx.ptr = NULL;
	aio->win.ptr = NULL;
	aio->img.adr = NULL;
	aio->img.ptr = NULL;
	aio->img.bits_per_pixel = 0;
	aio->img.endian = 0;
	aio->img.line_length = 0;
	aio->map.map = NULL;
	aio->map.cut_after = 0;
	aio->map.cut_left = 0;
	aio->map.cut_right = 0;
	aio->map.height = 0;
	aio->map.width = 0;
	aio->map.list = NULL;
	aio->map.sprite_count = 0;
	ft_initialization_2(aio);
}

void		ft_initialization_2(t_aio *aio)
{
	aio->tex.east = NULL;
	aio->tex.north = NULL;
	aio->tex.south = NULL;
	aio->tex.sprite = NULL;
	aio->tex.west = NULL;
	aio->tex.ea = NULL;
	aio->tex.no = NULL;
	aio->tex.so = NULL;
	aio->tex.sp = NULL;
	aio->tex.we = NULL;
	aio->tex.ce = 0xFF000000;
	aio->tex.fl = 0xFF000000;
	aio->res.map_x = 0;
	aio->res.map_y = 0;
	aio->res.display_x = 0;
	aio->res.display_y = 0;
	aio->plr.dir_x = 0;
	aio->plr.dir_y = 0;
	aio->plr.pos_x = 0;
	aio->plr.pos_y = 0;
	aio->plr.dir_a = 0;
	ft_initialization_3(aio);
}

void		ft_initialization_3(t_aio *aio)
{
	aio->ray.i = 0;
	aio->ray.v = 0;
	aio->ray.w = 0;
	aio->ray.x = 0;
	aio->ray.y = 0;
	aio->hit.c = 0;
	aio->hit.d = 0;
	aio->hit.x = 0;
	aio->hit.y = 0;
	aio->key.a = 0;
	aio->key.d = 0;
	aio->key.e = 0;
	aio->key.h = 0;
	aio->key.l = 0;
	aio->key.r = 0;
	aio->key.s = 0;
	aio->key.w = 0;
	aio->key.x = 0;
}
