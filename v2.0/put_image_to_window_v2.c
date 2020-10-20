#include "main_header_v2.h"

int		ft_is(int n, char c)
{
	if (n == WALL && (c == '1'))
		return (1);
	//else if (n == WALL && (c == '4' || c == '5' || c == '6'))
	//	return (1);
	else if ((n == ITEM) && (c == '2'))
		return (1);
	else if (n == POS && (c == 'N' || c == 'S' || c == 'E' || c == 'W'))
		return (1);
	else if (n == 0 && (c == '0' || c == 'O' || c == 'X'))
		return (1);
	else
		return (0);
}

////////////////////////////////////////////////////////////

int		ft_draw(t_aio *aio)
{
	char *spr_print;
	//if (ft_endflag(s))
	//	ft_close(s, 1);
	mlx_do_sync(aio->mlx.ptr);
	ft_screen(aio);
	ft_map_mini(aio);
	mlx_put_image_to_window(aio->mlx.ptr, aio->win.ptr, aio->img.ptr, 0, 0);
	mlx_string_put(aio->mlx.ptr, aio->win.ptr , aio->res.map_x - 200, 20,
							WHITE, "left to collect ");
	spr_print = ft_itoa(aio->map.sprite_count);
	mlx_string_put(aio->mlx.ptr, aio->win.ptr , aio->res.map_x - 30, 20,
							WHITE, spr_print);
	aio->img.ptr = NULL;
	aio->img.adr = NULL;
	free(aio->img.ptr);
	free(aio->img.adr);
	return (0);
}

void	ft_screen(t_aio *aio)
{
	//int		bpp;
	//int		sl;
	//int		end;

	aio->img.ptr = mlx_new_image(aio->mlx.ptr, aio->res.map_x, aio->res.map_y);
	aio->img.adr = (unsigned int *)mlx_get_data_addr(aio->img.ptr, &aio->img.bits_per_pixel, &aio->img.line_length, &aio->img.endian);
	if (aio->img.coef_dylib == 0)
		aio->img.coef_dylib = aio->img.line_length/4 - aio->res.map_x;
	//ft_sky(s);
	//aio->ray.i = 0;
	//while (aio->ray.i < aio->res.map_y / 2)
	//	ft_floor(s);
	aio->stk = malloc(sizeof(t_stk) * aio->res.map_x);
	aio->ray.i = 0;
	while (aio->ray.i < aio->res.map_x)
	{
		ft_ray(aio);
		ft_dir(aio);
		ft_ver(aio);
		ft_hor(aio);
		ft_stock(aio);
		if (aio->mapmod.on_off != 1)
			ft_column(aio, ft_size(aio));
		if (aio->ray.i == 0)
		{
			aio->mapmod.first_hit_x = aio->hit.x;
			aio->mapmod.first_hit_y = aio->hit.y;
		}
		aio->ray.i++;
	}
	aio->mapmod.last_hit_x = aio->hit.x;
	aio->mapmod.last_hit_y = aio->hit.y;
	mlx_do_sync(aio->mlx.ptr);
	ft_sprite(aio);
	//ft_hud(s);
}

unsigned int	ft_pixel(t_aio *aio, double i)
{
	int	index;

	if (floor(aio->hit.y) == aio->hit.y || floor(aio->hit.y) + 0.5 == aio->hit.y)
		index = 64 * floor(64 * i) + 64 * (aio->hit.x - floor(aio->hit.x));
	else if (floor(aio->hit.x) == aio->hit.x || floor(aio->hit.x) + 0.5 == aio->hit.x)
		index = 64 * floor(64 * i) + 64 * (aio->hit.y - floor(aio->hit.y));
	//if (aio->hit.c == '1')
	//	return (aio->tex.n[index]);
	//else if (aio->hit.c == '2')
	//	return (aio->tex.s[index]);
	//else if (aio->hit.c == '3')
	//	return (aio->tex.e[index]);
	//else if (aio->hit.c == '4' || aio->hit.c == '6')
	//	return (aio->tex.w[index]);
	//else if (aio->hit.c == '5')
	//	return (aio->tex.x[index]);
	//else if (aio->hit.c == 'D')
		//return (aio->tex.d[index]);
	if (floor(aio->hit.y) == aio->hit.y)
	{
		if (aio->ray.w == 1)
			return (aio->tex.so[index]);
		else if (aio->ray.w == 0)
			return (aio->tex.no[index]);
	}
	else if (floor(aio->hit.x) == aio->hit.x)
	{
		if (aio->ray.v == 1)
			return (aio->tex.ea[index]);
		else if (aio->ray.v == 0)
			return (aio->tex.we[index]);
	}
	return (GREEN);
}

void			  ft_column(t_aio *aio, int size)
{
	unsigned int	color;
	int				start;
	int				count;

	int x_con = aio->ray.i;
	int y_con = 0;

	start = aio->res.map_x * (aio->res.map_y - size) / 2;
	if (size > aio->res.map_y)
		count = (size - aio->res.map_y) / 2;
	else
		count = 0;
	color = aio->tex.ce;
	while (aio->ray.i < aio->res.map_x * aio->res.map_y)
	{
		if (aio->ray.i >= start && count < size)
		{
			color = ft_pixel(aio, (double)count / size);
			count++;
		}
		else if (count == size)
			color = aio->tex.fl;
		if (color != 0xFF000000)
		{
//!!!!!valid!!!!!
			//char    *dst;
			//dst = (char *)(aio->img.adr + (y_con * aio->img.line_length + x_con * (aio->img.bits_per_pixel / 8)) / 4);
			//*(unsigned int*)dst = mlx_get_color_value(aio->mlx.ptr, color);
//!!!!!NOT!!!!!
			//aio->img.adr[aio->ray.i] = mlx_get_color_value(aio->mlx.ptr, color);

//!!!!!valid!!!!!
			aio->img.adr[(y_con * aio->img.line_length + x_con * (aio->img.bits_per_pixel / 8)) / 4] = mlx_get_color_value(aio->mlx.ptr, color);
//ft_printf("\n%d --- %d === %d\n", (y_con * aio->img.line_length + x_con * (aio->img.bits_per_pixel / 8)) / 4, aio->ray.i,  (y_con * aio->img.line_length + x_con * (aio->img.bits_per_pixel / 8)) / 4 - aio->ray.i);
		}
		aio->ray.i += aio->res.map_x;
		y_con++;
	}
	aio->ray.i -= aio->res.map_x * aio->res.map_y;
}

//unsigned int	ft_shadow(t_aio *aio, unsigned int col)
//{
//	double	shadow;
//	int		r;
//	int		g;
//	int		b;

//	if (SHADOW == 0)
//		return (col);
//	shadow = 1 - hypot(aio->plr.pos_x - aio->hit.x, aio->plr.pos_y - aio->hit.y) / SHADOW;
//	if (shadow < 0)
//		shadow = 0;
//	r = (col / (256 * 256) % 256) * shadow;
//	g = (col / 256 % 256) * shadow;
//	b = (col % 256) * shadow;
//	col = r * 256 * 256 + g * 256 + b;
//	return (col);
//}


void	ft_ray(t_aio *aio)
{
	double	angle;
	double	dist;

	angle = ((double)aio->ray.i - (aio->res.map_x / 2)) * ANG / (aio->res.map_x / 2);
	aio->ray.x = aio->plr.dir_x * cos(angle) - aio->plr.dir_y * sin(angle);
	aio->ray.y = aio->plr.dir_y * cos(angle) + aio->plr.dir_x * sin(angle);
	dist = hypot(aio->ray.x, aio->ray.y);
	aio->ray.x /= dist;
	aio->ray.y /= dist;
}

void	ft_dir(t_aio *aio)
{
	if (aio->ray.x >= 0)
		aio->ray.v = 1;
	else
		aio->ray.v = 0;
	if (aio->ray.y >= 0)
		aio->ray.w = 1;
	else
		aio->ray.w = 0;
}

void	ft_ver(t_aio *aio)
{
	double	x;
	double	y;
	char	c;

	x = floor(aio->plr.pos_x) + aio->ray.v;
	y = aio->plr.pos_y + (x - aio->plr.pos_x) * (aio->ray.y / aio->ray.x);
	while ((int)floor(y) > 0 && (int)floor(y) < aio->map.height)
	{
		c = aio->map.map[(int)floor(y)][(int)floor(x - 1 + aio->ray.v)];
		if (ft_is(WALL, c))
		{
			aio->hit.x = x;
			aio->hit.y = y;
			aio->hit.d = hypot(x - aio->plr.pos_x, y - aio->plr.pos_y);
			aio->hit.c = c;
			//ft_is(DOOR, c) ? ft_verdoor(s, x, y) : 0;
			return ;
		}
		x += (2 * aio->ray.v - 1);
		y += (2 * aio->ray.v - 1) * aio->ray.y / aio->ray.x;
	}
	aio->hit.x = aio->plr.pos_x;
	aio->hit.y = aio->plr.pos_y;
	aio->hit.d = 1000000000;
	aio->hit.c = 0;
}

void	ft_hor(t_aio *aio)
{
	double	y;
	double	x;
	char	c;

	y = floor(aio->plr.pos_y) + aio->ray.w;
	x = aio->plr.pos_x + (y - aio->plr.pos_y) * (aio->ray.x / aio->ray.y);
	while ((int)floor(x) > 0 && (int)floor(x) < aio->map.width)
	{
		c = aio->map.map[(int)floor(y - 1 + aio->ray.w)][(int)floor(x)];
		if (ft_is(WALL, c))
		{
			if (aio->hit.d > hypot(x - aio->plr.pos_x, y - aio->plr.pos_y) && ft_is(WALL, c))
			{
				aio->hit.x = x;
				aio->hit.y = y;
				aio->hit.d = hypot(x - aio->plr.pos_x, y - aio->plr.pos_y);
				aio->hit.c = c;
			}
			//else if (aio->hit.d > hypot(x - aio->plr.pos_x, y - aio->plr.pos_y))
			//	ft_hordoor(s, x, y);
			return ;
		}
		y += (2 * aio->ray.w - 1);
		x += (2 * aio->ray.w - 1) * aio->ray.x / aio->ray.y;
	}
}


void			ft_stock(t_aio *aio)
{
 	aio->stk[aio->ray.i].x = aio->ray.x;
 	aio->stk[aio->ray.i].y = aio->ray.y;
 	aio->stk[aio->ray.i].d = aio->hit.d;
}

int				ft_size(t_aio *aio)
{
	double	correc;
	double	fisheye;

	fisheye = fabs((double)aio->ray.i / (aio->res.map_x / 2) - 1);
	fisheye *= 28 * M_PI / 180;
	correc = (double)aio->hit.d * cos(fisheye);
	return (round(aio->res.map_y / correc));
}
