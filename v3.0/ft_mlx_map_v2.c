#include "main_header_v2.h"
void            my_mlx_pixel_put(t_all *aio, int x, int y, int color, int scale);
void            my_mlx_pixel_put_double(t_img *data, double x, double y, int color, int scale);

void	ft_map_mode(t_all *aio)
{
	int max_x;
	int max_y;
	int scale;
	char    *dst;

	aio->img.ptr = mlx_new_image(aio->mlx.ptr, aio->res.map_x, aio->res.map_y);
	aio->img.adr = (unsigned int *)mlx_get_data_addr(aio->img.ptr, &aio->img.bits_per_pixel, &aio->img.line_length, &aio->img.endian);
//ft_print_parse(aio);
//int a = 0;
//while(aio->img.adr[a])
//	a++;
//ft_printf("%d\n", a);
	max_x = aio->res.map_x / aio->map.width;
	max_y = aio->res.map_y / aio->map.height;
	if (max_x <= max_y)
		scale = max_x;
	else
		scale = max_y;
	int i = 0;
	int j = 0;
//ft_printf("scale = %d, one_cub = %d, line_length = %d, data->bits_per_pixel = %d\n", scale, scale, aio->img.line_length, aio->img.bits_per_pixel);

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
	//my_mlx_pixel_put(&aio->img, (int)aio->plr.pos_x, (int)aio->plr.pos_y, GREEN, scale);
	//my_mlx_pixel_put(&aio->img, (int)aio->hit.x, (int)aio->hit.y, YELLOW, scale);
	//my_mlx_pixel_put(&aio->img, (int)aio->stk[1].x, (int)aio->stk[1].y, YELLOW, scale);


	mlx_put_image_to_window(aio->mlx.ptr, aio->win.ptr, aio->img.ptr, 0, 0);
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
	//while (x < x_limit)
	//{
	//	aio->img.adr[x + y * aio->res.map_x] = color;
	//	x++;
	//}

	//aio->img.adr[aio->res.map_y * aio->res.map_x] = YELLOW;
	//x = x_save;
	//while (y < y_limit)
	//{
	//	aio->img.adr[x + y * aio->res.map_x] = color;
	//	y++;
	//}
	//int i = 0;
	//while (i<10)
	//{
	//	aio->img.adr[i * 720] = color;
	//	i++;
	//}
	//y = 0;
	//while (y < 96)
	//{
	//	aio->img.adr[y * 720*4] = color;
	//	y++;
	//}

	while (x < x_limit)
	{
		y = y_save;
		while (y < y_limit)
		{
			aio->img.adr[x + y * aio->res.map_x] = color;
			y++;
		}
		x++;
	}
 }
