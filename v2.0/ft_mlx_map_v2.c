
#include "main_header_v2.h"
void            my_mlx_pixel_put(t_all *aio, int x, int y, int color, int scale);
void            my_mlx_pixel_put_plr(t_all *aio, double x, double y, int color, int scale);
void            my_mlx_pixel_put_ray(t_all *aio, double x, double y, int color, int cale);

void	ft_map_mini(t_all *aio)
{
	int max_x;
	int max_y;
	int scale;
	char    *dst;
	max_x = aio->res.map_x / aio->map.width;
	max_y = aio->res.map_y / aio->map.height;
	if (max_x <= max_y)
		scale = max_x / 4;
	else
		scale = max_y / 4;
	int i = 0;
	int j = 0;

my_mlx_pixel_put_plr(aio, aio->plr.pos_x, aio->plr.pos_y, GREEN, scale);

	while (aio->map.map[i])
	{
		j = 0;
		while (aio->map.map[i][j])
		{
			if (aio->map.map[i][j] == '1')
			{
				my_mlx_pixel_put(aio, j, i, RED, scale);
			}
			j++;
		}
		i++;
	}
my_mlx_pixel_put_ray(aio, aio->plr.pos_x, aio->plr.pos_y, PURPLE, scale);
}

void	ft_map_mode(t_all *aio)
{
	int max_x;
	int max_y;
	int scale;
	char    *dst;

	aio->img.ptr = mlx_new_image(aio->mlx.ptr, aio->res.map_x, aio->res.map_y);
	aio->img.adr = (unsigned int *)mlx_get_data_addr(aio->img.ptr, &aio->img.bits_per_pixel, &aio->img.line_length, &aio->img.endian);

	max_x = aio->res.map_x / aio->map.width;
	max_y = aio->res.map_y / aio->map.height;
	if (max_x <= max_y)
		scale = max_x;
	else
		scale = max_y;
	int i = 0;
	int j = 0;

my_mlx_pixel_put_plr(aio, aio->plr.pos_x, aio->plr.pos_y, GREEN, scale);

	while (aio->map.map[i])
	{
		j = 0;
		while (aio->map.map[i][j])
		{
			if (aio->map.map[i][j] == '1')
			{
				my_mlx_pixel_put(aio, j, i, RED, scale);
			}
			else
			{
				mlx_string_put(aio->mlx.ptr, aio->win.ptr , j*scale, i*scale,
							WHITE, "?");
			}
			j++;
		}
		i++;
	}
my_mlx_pixel_put_ray(aio, aio->plr.pos_x, aio->plr.pos_y, PURPLE, scale);
mlx_put_image_to_window(aio->mlx.ptr, aio->win.ptr, aio->img.ptr, 0, 0);

/////////////////////
mlx_string_put(aio->mlx.ptr, aio->win.ptr , aio->res.map_x - 150, aio->res.map_y - 40,
							PURPLE, "FJEWFISH 42");
///////////////////

	aio->img.ptr = NULL;
	aio->img.adr = NULL;
	free(aio->img.ptr);
	free(aio->img.adr);
}


void            my_mlx_pixel_put(t_all *aio, int x, int y, int color, int scale)
 {
	int x_limit;
	int y_limit;
	int y_save;
	int x_save;
	x *= scale;
	y *= scale;
	x_limit = x + scale;
	y_limit = y + scale;
	y_save = y;
	x_save = x;
	while (x < x_limit)
	{
		y = y_save;
		while (y < y_limit)
		{
			char    *dst;
			dst = (char *)(aio->img.adr + (y * aio->img.line_length + x * (aio->img.bits_per_pixel / 8)) / 4);
			*(unsigned int*)dst = color;
			y++;
		}
		x++;
	}
 }

void            my_mlx_pixel_put_plr(t_all *aio, double x, double y, int color, int scale)
{
	//printf("x = %f, y = %f, scale = %d\n", x, y, scale);
	double x_limit;
	double y_limit;
	double y_save;
	double x_save;
	x = x * scale - scale/8;
	y = y * scale - scale/8;
	x_limit = x + scale/4;
	y_limit = y + scale/4;
	y_save = y;
	x_save = x;
	//printf("x = %f, y = %f\n", x, y);
	while (x < x_limit)
	{
		y = y_save;
		while (y < y_limit)
		{
			char    *dst;

			dst = (char *)(aio->img.adr + ((int)y * aio->img.line_length + (int)x * (aio->img.bits_per_pixel / 8)) / 4);
			*(unsigned int*)dst = color;
			y++;
		}
		x++;
	}
}

//Алгоритм Брезенхэма
void		my_mlx_pixel_put_ray(t_all *aio, double x, double y, int color, int scale)
{
//LEFT//LEFT//LEFT//LEFT//LEFT//LEFT//LEFT//LEFT//LEFT//LEFT//LEFT//LEFT//LEFT//LEFT//LEFT//LEFT//LEFT//LEFT
	{
		int x0 = (int)(x * (double)scale);
		int y0 = (int)(y * (double)scale);
		int x1 = (int)(aio->hit.x * (double)scale);
		int y1 = (int)(aio->hit.y * (double)scale);
		int delta_x = abs(x1 - x0);
		int delta_y = abs(y1 - y0);

		int error = 0;
		int delta_err = delta_y + 1;

		int error2 = 0;
		int delta_err2 = delta_x + 1;


		int save_y = y0;

		int diry = y1 - y0;
		if (diry > 0)
			diry = 1;
		if (diry < 0)
			diry = -1;

		int diry2 = x1 - x0;
		if (diry2 > 0)
			diry2 = 1;
		if (diry2 < 0)
			diry2 = -1;

		int save_x = x0;
		if(delta_y <= delta_x)
		{
			while (save_x != x1)
			{
				char    *dst;
				dst = (char *)(aio->img.adr + (save_y * aio->img.line_length + save_x * (aio->img.bits_per_pixel / 8)) / 4);
				*(unsigned int*)dst = color;
				error += delta_err;
				if (error >= (delta_x + 1))
				{
					save_y += diry;
					error -= (delta_x +1);
				}
				save_x += diry2;
			}
		}
		else
		{
			while (save_y != y1)
			{
				char    *dst;
				dst = (char *)(aio->img.adr + (save_y * aio->img.line_length + save_x * (aio->img.bits_per_pixel / 8)) / 4);
				*(unsigned int*)dst = color;
				error2 += delta_err2;
				if (error2 >= (delta_y + 1))
				{
					save_x += diry2;
					error2 -= (delta_y +1);
				}
				save_y += diry;
			}
		}
	}

//RIGHT//RIGHT//RIGHT//RIGHT//RIGHT//RIGHT//RIGHT//RIGHT//RIGHT//RIGHT//RIGHT//RIGHT//RIGHT//RIGHT//RIGHT//RIGHT//RIGHT//RIGHT//RIGHT
	{
		int x0 = (int)(x * (double)scale);
		int y0 = (int)(y * (double)scale);
		int x1 = (int)(aio->mapmod.first_hit_x * (double)scale);
		int y1 = (int)(aio->mapmod.first_hit_y * (double)scale);
		int delta_x = abs(x1 - x0);
		int delta_y = abs(y1 - y0);

		int error = 0;
		int delta_err = delta_y + 1;

		int error2 = 0;
		int delta_err2 = delta_x + 1;


		int save_y = y0;

		int diry = y1 - y0;
		if (diry > 0)
			diry = 1;
		if (diry < 0)
			diry = -1;

		int diry2 = x1 - x0;
		if (diry2 > 0)
			diry2 = 1;
		if (diry2 < 0)
			diry2 = -1;

		int save_x = x0;
		if(delta_y <= delta_x)
		{
			while (save_x != x1)
			{
				char    *dst;
				dst = (char *)(aio->img.adr + (save_y * aio->img.line_length + save_x * (aio->img.bits_per_pixel / 8)) / 4);
				*(unsigned int*)dst = color;
				error += delta_err;
				if (error >= (delta_x + 1))
				{
					save_y += diry;
					error -= (delta_x +1);
				}
				save_x += diry2;
			}
		}
		else
		{
			while (save_y != y1)
			{
				char    *dst;
				dst = (char *)(aio->img.adr + (save_y * aio->img.line_length + save_x * (aio->img.bits_per_pixel / 8)) / 4);
				*(unsigned int*)dst = color;
				error2 += delta_err2;
				if (error2 >= (delta_y + 1))
				{
					save_x += diry2;
					error2 -= (delta_y +1);
				}
				save_y += diry;
			}
		}
	}
}

//function line(int x0, int x1, int y0, int y1)
//     int deltax := abs(x1 - x0)
//     int deltay := abs(y1 - y0)
//     int error := 0
//     int deltaerr := (deltay + 1)
//     int y := y0
//     int diry := y1 - y0
//     if diry > 0
//         diry = 1
//     if diry < 0
//         diry = -1
//     for x from x0 to x1
//         plot(x,y)
//         error := error + deltaerr
//         if error >= (deltax + 1)
//             y := y + diry
//             error := error - (deltax + 1)
