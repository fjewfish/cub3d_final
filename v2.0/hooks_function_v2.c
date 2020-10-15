#include "main_header_v2.h"

void	ft_reset(t_aio *s)
{
	//s->map.tab = NULL;
	//s->tex.n = NULL;
	//s->tex.s = NULL;
	//s->tex.e = NULL;
	//s->tex.w = NULL;
	//s->tex.d = NULL;
	//s->tex.x = NULL;
	//s->tex.f = NULL;
	//s->tex.c = NULL;
	//s->tex.i = NULL;
	//s->tex.j = NULL;
	//s->res.map_x = 0;
	//s->res.map_y = 0;
	//s->map.x = 0;
	//s->map.y = 0;
	//s->map.spr = 0;
	//s->err.m = 0;
	//s->err.n = 0;
	//s->err.p = 0;
}

void	ft_free(t_aio *aio)
{
	//int	i;

	//i = 0;
	//while (i < s->map.y)
	//	free(s->map.tab[i++]);
	//free(s->map.tab);
	//free(s->spr);
	//free(s->tex.n);
	//free(s->tex.s);
	//free(s->tex.e);
	//free(s->tex.w);
	//free(s->tex.d);
	//free(s->tex.x);
	//free(s->tex.f);
	//free(s->tex.c);
	//free(s->tex.i);
	//free(s->tex.j);
}

int		ft_set(t_aio *aio, int key, int set)
{
	if (key == ESC)
		aio->key.e = set;
	else if (key == W)
		aio->key.w = set;
	else if (key == A)
		aio->key.a = set;
	else if (key == S)
		aio->key.s = set;
	else if (key == D)
		aio->key.d = set;
	else if (key == LEFT)
		aio->key.l = set;
	else if (key == RIGHT)
		aio->key.r = set;
	else if (key == 3 && aio->mapmod.on_off == 0 && set != 0)
		aio->mapmod.on_off = 1;
	else if (key == 3 && set != 0)
		aio->mapmod.on_off =0;
	//else if (key == SHIFT && set)
	//	ft_open(s);
	//else if (key == SPACE)
	//	s->key.x = set;
	return (1);
}

int		ft_press(int key, void *arg)
{
	ft_set(arg, key, 1);
	return (1);
}

int		ft_release(int key, void *arg)
{
	ft_set(arg, key, 0);
	return (1);
}

void	ft_move(t_aio *aio, double coeff)
{
	char	c;

	aio->plr.pos_x += coeff * (aio->plr.dir_x * SPEED / 100);
	c = aio->map.map[(int)floor(aio->plr.pos_y)][(int)floor(aio->plr.pos_x)];
	if (ft_is(WALL, c))
		aio->plr.pos_x -= coeff * (aio->plr.dir_x* SPEED / 100);
	aio->plr.pos_y += coeff * (aio->plr.dir_y * SPEED / 100);
	c = aio->map.map[(int)floor(aio->plr.pos_y)][(int)floor(aio->plr.pos_x)];
	if (ft_is(WALL, c))
		aio->plr.pos_y -= coeff * (aio->plr.dir_y * SPEED / 100);
	c = aio->map.map[(int)floor(aio->plr.pos_y)][(int)floor(aio->plr.pos_x)];
	//if (ft_is(PICK, c))
	//{
	//	if (c == '7')
	//		s->hud.h += 35;
	//	else if (c == '8')
	//		s->hud.s += 1000;
	//	else if (c == '-')
	//		s->hud.a += 3;
	//	s->map.tab[(int)floor(s->plr.pos_y)][(int)floor(s->plr.pos_x)] = '0';
	//	s->map.spr--;
	//	ft_slist(s);
	//}
}

void	ft_strafe(t_aio *aio, double coeff)
{
	char	c;

	aio->plr.pos_x -= coeff * (aio->plr.dir_y * SPEED / 100);
	c = aio->map.map[(int)floor(aio->plr.pos_y)][(int)floor(aio->plr.pos_x)];
	if (ft_is(WALL, c))
		aio->plr.pos_x += coeff * (aio->plr.dir_y * SPEED / 100);
	aio->plr.pos_y += coeff * (aio->plr.dir_x * SPEED / 100);
	c = aio->map.map[(int)floor(aio->plr.pos_y)][(int)floor(aio->plr.pos_x)];
	if (ft_is(WALL, c))
		aio->plr.pos_y -= coeff * (aio->plr.dir_x * SPEED / 100);
	c = aio->map.map[(int)floor(aio->plr.pos_y)][(int)floor(aio->plr.pos_x)];
	//if (ft_is(PICK, c))
	//{
	//	if (c == '7')
	//		s->hud.h += 35;
	//	else if (c == '8')
	//		s->hud.s += 1000;
	//	else if (c == '-')
	//		s->hud.a += 3;
	//	s->map.tab[(int)floor(aio->plr.pos_y)][(int)floor(aio->plr.pos_x)] = '0';
	//	s->map.spr--;
	//	ft_slist(s);
	//}
}

void	ft_rotate(t_aio *aio, double c)
{
	double	dist;

	aio->plr.dir_x = aio->plr.dir_x * cos(c * TURN) - aio->plr.dir_y * sin(c * TURN);
	aio->plr.dir_y = aio->plr.dir_y * cos(c * TURN) + aio->plr.dir_x* sin(c * TURN);
	dist = hypot(aio->plr.dir_x, aio->plr.dir_y);
	aio->plr.dir_x /= dist;
	aio->plr.dir_y /= dist;
	dist = hypot(aio->plr.dir_x, aio->plr.dir_y);
	if (aio->plr.dir_y <= 0)
		aio->plr.dir_a = acos(aio->plr.dir_x / dist) * 180 / M_PI;
	else
		aio->plr.dir_a = 360 - acos(aio->plr.dir_x / dist) * 180 / M_PI;
}

int		ft_key(t_aio *aio)
{
	if (aio->key.e)
		ft_close(aio, 1);
	if (aio->key.w)
		ft_move(aio, 1);
	if (aio->key.a)
		ft_strafe(aio, -1);
	if (aio->key.s)
		ft_move(aio, -1);
	if (aio->key.d)
		ft_strafe(aio, 1);
	if (aio->key.l)
		ft_rotate(aio, -1);
	if (aio->key.r)
		ft_rotate(aio, 1);
	//if (aio->key.x)
	//{
	//	if (aio->hud.f == 0)
	//		s->hud.f++;
	//}



	ft_draw(aio);
	if (aio->mapmod.on_off == 1)
		ft_map_mode(aio);




	//ft_global_map(aio);
	return (1);
}

