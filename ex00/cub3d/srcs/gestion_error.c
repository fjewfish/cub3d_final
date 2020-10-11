/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corozco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:55:48 by corozco           #+#    #+#             */
/*   Updated: 2020/02/11 19:36:18 by corozco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_ms_error(int i, char *str, char *line)
{
	ft_printf("Error\n");
	if (str)
		ft_putendl_fd(str, 2);
	if (line)
		free(line);
	else
	{
		(i == 1) ? ft_putendl_fd("  -Map not found", 2) : 0;
		(i == -1) ? ft_putendl_fd("  -Wrong command", 2) : 0;
		(i == -2) ? ft_putendl_fd("  -Wrong format", 2) : 0;
		(i > 3) ? ft_putendl_fd("  -Many arguments", 2) : 0;
	}
	exit(1);
}

void			free_coordinates(t_data *d, char *sms, int key)
{
	if (d->tex.north)
		free(d->tex.north);
	if (d->tex.south)
		free(d->tex.south);
	if (d->tex.west)
		free(d->tex.west);
	if (d->tex.east)
		free(d->tex.east);
	if (d->tex.sprite)
		free(d->tex.sprite);
	if (d->tex.floor)
		free(d->tex.floor);
	if (d->tex.sky)
		free(d->tex.sky);
	if (d->tex.hand1)
		free(d->tex.hand1);
	if (d->tex.hand2)
		free(d->tex.hand2);
	if (d->tex.hand3)
		free(d->tex.hand3);
	ft_ms_error(0, sms, (void *)0);
	if (key == 1)
		free(d->map.map);
	exit(1);
}

void			free_map(t_data *d, int i, char *sms)
{
	while (i >= 0)
		free(d->map.map[i--]);
	free_coordinates(d, sms, 1);
}
