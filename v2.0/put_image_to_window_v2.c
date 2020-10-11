#include "main_header_v2.h"

int		ft_is(int n, char c)
{
	if (n == WALL && (c == '1' || c == '2' || c == '3' || c == '4'))
		return (1);
	else if (n == WALL && (c == '4' || c == '5' || c == '6'))
		return (1);
	else if ((n == SPRITE || n == PICK) && (c == '7' || c == '8' || c == '-'))
		return (1);
	else if ((n == SPRITE || n == DECOR) && (c == '9' || c == '+' || c == '#'))
		return (1);
	else if ((n == SPRITE || n == DECOR) && (c == '&' || c == '$' || c == '*'))
		return (1);
	else if (n == ENEMY && (c == '+' || c == '#' || c == '&'))
		return (1);
	else if (n == ENEMY && (c == '$' || c == '*'))
		return (1);
	else if (n == POS && (c == 'N' || c == 'S' || c == 'E' || c == 'W'))
		return (1);
	else if (n == 0 && (c == '0' || c == 'O' || c == 'X'))
		return (1);
	else if (n == DOOR && c == 'D')
		return (1);
	else
		return (0);
}

////////////////////////////////////////////////////////////

int		ft_draw(t_all *s)
{
	//if (ft_endflag(s))
	//	ft_close(s, 1);
	mlx_do_sync(s->mlx.ptr);
	ft_screen(s);
	ft_map_mini(s);
	mlx_put_image_to_window(s->mlx.ptr, s->win.ptr, s->img.ptr, 0, 0);
	s->img.ptr = NULL;
	s->img.adr = NULL;
	free(s->img.ptr);
	free(s->img.adr);
	return (0);
}

void	ft_screen(t_all *s)
{
	//int		bpp;
	//int		sl;
	//int		end;

	s->img.ptr = mlx_new_image(s->mlx.ptr, s->res.map_x, s->res.map_y);
	s->img.adr = (unsigned int *)mlx_get_data_addr(s->img.ptr, &s->img.bits_per_pixel, &s->img.line_length, &s->img.endian);
	//ft_sky(s);
	//s->ray.i = 0;
	//while (s->ray.i < s->res.map_y / 2)
	//	ft_floor(s);
	s->stk = malloc(sizeof(t_stk) * s->res.map_x);
	s->ray.i = 0;
	while (s->ray.i < s->res.map_x)
	{
		ft_ray(s);
		ft_dir(s);
		ft_ver(s);
		ft_hor(s);
		ft_stock(s);
		if (s->map_mode != 1)
			ft_column(s, ft_size(s));
		if (s->ray.i == 0)
		{
			s->mapmod.first_hit_x = s->hit.x;
			s->mapmod.first_hit_y = s->hit.y;
		}
		s->ray.i++;
	}
	s->mapmod.last_hit_x = s->hit.x;
	s->mapmod.last_hit_y = s->hit.y;
	mlx_do_sync(s->mlx.ptr);
	//ft_sprite(s);
	//ft_hud(s);
}

unsigned int	ft_pixel(t_all *s, double i)
{
	int	index;

	if (floor(s->hit.y) == s->hit.y || floor(s->hit.y) + 0.5 == s->hit.y)
		index = 64 * floor(64 * i) + 64 * (s->hit.x - floor(s->hit.x));
	else if (floor(s->hit.x) == s->hit.x || floor(s->hit.x) + 0.5 == s->hit.x)
		index = 64 * floor(64 * i) + 64 * (s->hit.y - floor(s->hit.y));
	//if (s->hit.c == '1')
	//	return (s->tex.n[index]);
	//else if (s->hit.c == '2')
	//	return (s->tex.s[index]);
	//else if (s->hit.c == '3')
	//	return (s->tex.e[index]);
	//else if (s->hit.c == '4' || s->hit.c == '6')
	//	return (s->tex.w[index]);
	//else if (s->hit.c == '5')
	//	return (s->tex.x[index]);
	//else if (s->hit.c == 'D')
		//return (s->tex.d[index]);
	if (floor(s->hit.y) == s->hit.y)
	{
		if (s->ray.w == 1)
			return (s->tex.so[index]);
		else if (s->ray.w == 0)
			return (s->tex.no[index]);
	}
	else if (floor(s->hit.x) == s->hit.x)
	{
		if (s->ray.v == 1)
			return (s->tex.ea[index]);
		else if (s->ray.v == 0)
			return (s->tex.we[index]);
	}
	return (GREEN);
}

void			  ft_column(t_all *s, int size)
{
	unsigned int	color;
	int				start;
	int				count;

	int x_con = s->ray.i;
	int y_con = 0;

	start = s->res.map_x * (s->res.map_y - size) / 2;
	if (size > s->res.map_y)
		count = (size - s->res.map_y) / 2;
	else
		count = 0;
	color = s->tex.ce;
	while (s->ray.i < s->res.map_x * s->res.map_y)
	{
		if (s->ray.i >= start && count < size)
		{
			color = ft_pixel(s, (double)count / size);
			count++;
		}
		else if (count == size)
			color = s->tex.fl;
		if (color != NONE)
		{
			char    *dst;
			dst = (char *)(s->img.adr + (y_con * s->img.line_length + x_con * (s->img.bits_per_pixel / 8)) / 4);
			*(unsigned int*)dst = mlx_get_color_value(s->mlx.ptr, color);
		}
		//{
		//	ft_printf("dasf\n");
		//	char    *dst;
		//	dst = (char *)(s->img.adr + ((s->ray.i / s->res.map_x) * s->img.line_length + (save_ray) * (s->img.bits_per_pixel / 8)) / 4);
		//	ft_printf("dasf\n");
		//	*(unsigned int*)dst = mlx_get_color_value(s->mlx.ptr, color);
		//	ft_printf("dasf\n");
		//}
			//s->img.adr[s->ray.i] = mlx_get_color_value(s->mlx.ptr, color);
		s->ray.i += s->res.map_x;
		y_con++;
	}
	s->ray.i -= s->res.map_x * s->res.map_y;
}

//unsigned int	ft_shadow(t_all *s, unsigned int col)
//{
//	double	shadow;
//	int		r;
//	int		g;
//	int		b;

//	if (SHADOW == 0)
//		return (col);
//	shadow = 1 - hypot(s->plr.pos_x - s->hit.x, s->plr.pos_y - s->hit.y) / SHADOW;
//	if (shadow < 0)
//		shadow = 0;
//	r = (col / (256 * 256) % 256) * shadow;
//	g = (col / 256 % 256) * shadow;
//	b = (col % 256) * shadow;
//	col = r * 256 * 256 + g * 256 + b;
//	return (col);
//}


void	ft_ray(t_all *s)
{
	double	angle;
	double	dist;

	angle = ((double)s->ray.i - (s->res.map_x / 2)) * ANG / (s->res.map_x / 2);
	s->ray.x = s->plr.dir_x * cos(angle) - s->plr.dir_y * sin(angle);
	s->ray.y = s->plr.dir_y * cos(angle) + s->plr.dir_x * sin(angle);
	dist = hypot(s->ray.x, s->ray.y);
	s->ray.x /= dist;
	s->ray.y /= dist;
}

void	ft_dir(t_all *s)
{
	if (s->ray.x >= 0)
		s->ray.v = 1;
	else
		s->ray.v = 0;
	if (s->ray.y >= 0)
		s->ray.w = 1;
	else
		s->ray.w = 0;
}

void	ft_ver(t_all *s)
{
	double	x;
	double	y;
	char	c;

	x = floor(s->plr.pos_x) + s->ray.v;
	y = s->plr.pos_y + (x - s->plr.pos_x) * (s->ray.y / s->ray.x);
	while ((int)floor(y) > 0 && (int)floor(y) < s->map.height)
	{
		c = s->map.map[(int)floor(y)][(int)floor(x - 1 + s->ray.v)];
		if (ft_is(WALL, c))
		{
			s->hit.x = x;
			s->hit.y = y;
			s->hit.d = hypot(x - s->plr.pos_x, y - s->plr.pos_y);
			s->hit.c = c;
			//ft_is(DOOR, c) ? ft_verdoor(s, x, y) : 0;
			return ;
		}
		x += (2 * s->ray.v - 1);
		y += (2 * s->ray.v - 1) * s->ray.y / s->ray.x;
	}
	s->hit.x = s->plr.pos_x;
	s->hit.y = s->plr.pos_y;
	s->hit.d = 1000000000;
	s->hit.c = 0;
}

void	ft_hor(t_all *s)
{
	double	y;
	double	x;
	char	c;

	y = floor(s->plr.pos_y) + s->ray.w;
	x = s->plr.pos_x + (y - s->plr.pos_y) * (s->ray.x / s->ray.y);
	while ((int)floor(x) > 0 && (int)floor(x) < s->map.width)
	{
		c = s->map.map[(int)floor(y - 1 + s->ray.w)][(int)floor(x)];
		if (ft_is(WALL, c))
		{
			if (s->hit.d > hypot(x - s->plr.pos_x, y - s->plr.pos_y) && ft_is(WALL, c))
			{
				s->hit.x = x;
				s->hit.y = y;
				s->hit.d = hypot(x - s->plr.pos_x, y - s->plr.pos_y);
				s->hit.c = c;
			}
			//else if (s->hit.d > hypot(x - s->plr.pos_x, y - s->plr.pos_y))
			//	ft_hordoor(s, x, y);
			return ;
		}
		y += (2 * s->ray.w - 1);
		x += (2 * s->ray.w - 1) * s->ray.x / s->ray.y;
	}
}


void			ft_stock(t_all *aio)
{
	aio->stk[aio->ray.i].x = aio->ray.x;
	aio->stk[aio->ray.i].y = aio->ray.y;
	aio->stk[aio->ray.i].d = aio->hit.d;
}

int				ft_size(t_all *aio)
{
	double	correc;
	double	fisheye;

	fisheye = fabs((double)aio->ray.i / (aio->res.map_x / 2) - 1);
	fisheye *= 28 * M_PI / 180;
	correc = (double)aio->hit.d * cos(fisheye);
	return (round(aio->res.map_y / correc));
}
