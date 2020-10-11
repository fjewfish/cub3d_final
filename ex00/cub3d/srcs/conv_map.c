/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corozco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 16:29:54 by corozco           #+#    #+#             */
/*   Updated: 2020/02/11 19:27:20 by corozco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		check_map(char c, t_data *d)
{
	if (c == '0' || c == '1' || c == '2' || c == 'N'
			|| c == 'S' || c == 'E' || c == 'W' || c == '3')
	{
		if (c == '2' || c == '3')
			d->sprcount++;
		return (1);
	}
	return (0);
}

void			conv_map(t_data *d, char *line, int i, int y)
{
	char		str[y];

	str[y] = '\0';
	y = 0;
	while (line[i])
	{
		if (check_map(line[i], d))
			str[y++] = line[i];
		i++;
	}
	i = -1;
	ft_bzero(line, ft_strlen(line));
	while (str[++i])
	{
		line[i] = str[i];
		if (line[i] == 'N' || line[i] == 'S'
				|| line[i] == 'W' || line[i] == 'E')
			d->map.boolean++;
	}
}

static void		orientation(t_data *d, int ori)
{
	if (ori == 30 || ori == 35)
	{
		d->pl.dirx = 0;
		d->pl.diry = (ori == 30) ? -1 : 1;
		d->pl.planex = (ori == 30) ? -0.66 : 0.66;
		d->pl.planey = 0;
	}
	if (ori == 39 || ori == 21)
	{
		d->pl.dirx = (ori == 39) ? -1 : 1;
		d->pl.diry = 0;
		d->pl.planex = 0;
		d->pl.planey = (ori == 39) ? 0.66 : -0.66;
	}
}

/*
**	N = 30, S = 35, W = 39, E = 21,
*/

void			player_pos(t_data *d, int *map, int x, int y)
{
	int			j;

	j = -1;
	while (++j < y)
	{
		if (map[j] == 30 || map[j] == 35 || map[j] == 39 || map[j] == 21)
		{
			d->pl.posx = j + 0.5;
			d->pl.posy = x + 0.5;
			orientation(d, map[j]);
			map[j] = 0;
		}
		if (map[j] == 2 || map[j] == 3)
		{
			d->sprite[d->cmp_sp].x = j + 0.5;
			d->sprite[d->cmp_sp].y = x + 0.5;
			d->sprite[d->cmp_sp].texture = map[j] == 2 ? 5 : 17;
			d->cmp_sp++;
		}
	}
}

void			ft_verif(t_data *d, int **map, int x, int y)
{
	while (x < y)
	{
		if (map[0][x++] != 1)
			free_map(d, d->map.y - 1, "  -Walls missing");
	}
	x = -1;
	while (++x < d->tmps.cmp_map)
	{
		if (map[x][0] != 1 || map[x][y - 1] != 1)
			free_map(d, d->map.y - 1, "  -Walls missing");
		player_pos(d, map[x], x, y);
	}
	x = 0;
	while (x < y)
		if (map[d->tmps.cmp_map - 1][x++] != 1)
			free_map(d, d->map.y - 1, "  -Walls missing");
}
