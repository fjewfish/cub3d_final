#include "main_header_v2.h"

int		ft_cub(char *cub, int bmp)
{
	t_all *aio;

	if (!(aio = (t_all *)malloc_gc(sizeof(t_all))))
		return(ft_strerror(-8));
	ft_initialization(aio);
	aio->mlx.ptr = mlx_init();
	aio->res.display_x = 10000;
	aio->res.display_y = 10000;
	//mlx_get_screen_size(aio->mlx.ptr, &aio->res.display_x, &aio->res.display_y);
	ft_printf("YOUR DISPLAY RES = %dx%d\n",  aio->res.display_x, aio->res.display_y);
	if (ft_parse(aio, cub) == -1)
		return (ft_close(aio, 0));
//ft_print_parse(aio);
	if (bmp == 1)
		return (ft_bmp_save(aio));
	aio->win.ptr = mlx_new_window(aio->mlx.ptr, aio->res.map_x, aio->res.map_y, "cub3D");

//	//mlx_pixel_put(aio->mlx.ptr, aio->win.ptr, aio->res.map_x-5, aio->res.map_y-5, RED);
//	aio->img.ptr = mlx_new_image(aio->mlx.ptr, aio->res.map_x, aio->res.map_y);
//	aio->img.adr = (unsigned int *)mlx_get_data_addr(aio->img.ptr, &aio->img.bits_per_pixel, &aio->img.line_length, &aio->img.endian);
//	int d = aio->res.map_x * aio->res.map_y - 1;
//	int i = 0;
//	while (i < 100)
//	{
//	aio->img.adr[d] = RED;
//	d--;
//	i++;
//	}
//	mlx_put_image_to_window(aio->mlx.ptr, aio->win.ptr, aio->img.ptr, 0, 0);
//mlx_pixel_put(aio->mlx.ptr, aio->win.ptr, aio->res.map_x-50, aio->res.map_y-50, YELLOW);

	ft_draw(aio);
	mlx_hook(aio->win.ptr, 2, 0, ft_press, aio);
	mlx_hook(aio->win.ptr, 3, 0, ft_release, aio);



	////mlx_hook(aio->win.ptr, 6, 0, ft_mouse, &s);



	mlx_hook(aio->win.ptr, 17, 0, ft_close, aio);
	mlx_loop_hook(aio->mlx.ptr, ft_key, aio);
	mlx_loop(aio->mlx.ptr);
	return (1);
}

int		main(int ac, char **av)
{
	if (ac == 3 && ft_namecheck(av[1], "cub") && ft_savecheck(av[2], "--save"))
		ft_cub(av[1], 1);
	else if (ac == 2 && ft_namecheck(av[1], "cub"))
		ft_cub(av[1], 0);
	else
		write(2, "Error : Invalid arguments\n", 26);
	return (0);
}
