/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a1_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 14:25:31 by fjewfish          #+#    #+#             */
/*   Updated: 2020/10/19 19:33:40 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header_v2.h"

int			main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc < 2 && argc > 3)
	{
		ft_putstr_fd("WTF? Wrong number of arguments\n", 2);
		return (0);
	}
	while (argv[1][i] != '\0')
		i++;
	if (i > 4 && ft_strcmp(&argv[1][i - 4], ".cub") != 0)
		ft_putstr_fd("WTF? PS change to *.cub\n", 2);
	else if (i <= 4)
		ft_putstr_fd("WTF? PS change to *.cub\n", 2);
	else if (argc == 2)
		ft_cub(argv[1], 0);
	else if (argc == 3)
	{
		if (ft_strcmp(argv[2], "--save") == 0)
			ft_cub(argv[1], 1);
		else
			ft_putstr_fd("WTF? Try --save\n", 2);
	}
	return (0);
}

int			ft_cub(char *cub, int screenshot)
{
	t_aio *aio;

	if (!(aio = (t_aio *)malloc_gc(sizeof(t_aio))))
		return (ft_error_number(8));
	ft_initialization(aio);
	aio->mlx.ptr = mlx_init();
	mlx_get_screen_size(aio->mlx.ptr, &aio->res.display_x, &aio->res.display_y);
	ft_printf("YOUR DISPLAY RES = %dx%d\n", aio->res.display_x,
				aio->res.display_y);
	if (ft_parse(aio, cub) == -1)
		return (ft_close(aio, 0));
	if (screenshot == 1)
		return (ft_bmp_save(aio));
	aio->win.ptr = mlx_new_window(aio->mlx.ptr, aio->res.map_x,
									aio->res.map_y, "cub3D");
	ft_draw(aio);
ft_print_parse(aio);
	mlx_hook(aio->win.ptr, 2, 0, ft_press, aio);
	mlx_hook(aio->win.ptr, 3, 0, ft_release, aio);
	mlx_hook(aio->win.ptr, 17, 0, ft_close, aio);
	mlx_loop_hook(aio->mlx.ptr, ft_key, aio);
	mlx_do_sync(aio->mlx.ptr);
ft_print_parse(aio);
	mlx_loop(aio->mlx.ptr);
	return (1);
}
