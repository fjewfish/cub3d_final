/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corozco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 22:29:43 by corozco           #+#    #+#             */
/*   Updated: 2020/02/14 00:35:29 by corozco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>
#include <string.h>

int				error_management(int ac, char **av)
{
	if (ft_strlen(av[1]) < 5)
		return (-2);
	if (ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".cub", 4))
		return (-2);
	if (ac == 3)
		if (ft_strncmp(av[2], "--save", 6) != 0)
			return (-1);
	return (0);
}

int				is_xpm(char *av)
{
	return (ft_strlen(av) < 5 || ft_strncmp(&av[ft_strlen(av) - 4], ".xpm", 4));
}

int				main(int ac, char **av)
{
	t_data		data;
	int			i;

	if (ac != 2 && ac != 3)
		ft_ms_error(ac, (void *)0, (void *)0);
	if ((data.tmps.i_tmp = error_management(ac, av)) != 0)
		ft_ms_error(data.tmps.i_tmp, (void *)0, (void *)0);
	ft_init_map(av[1], &data);
	init(&data);
	if (ac == 2)
	{
		mlx_loop_hook(data.mlx_ptr, raycasting, &data);
		ft_press(&data);
		system("afplay son/herr_mannelig.mp3 &");
		mlx_loop(data.mlx_ptr);
	}
	else
	{
		i = 0;
		raycasting(&data);
		while (av[1][i] != '.')
			i++;
		export_bmp(create_bmp_filename(av[1], i, &data), &data);
	}
	return (0);
}
