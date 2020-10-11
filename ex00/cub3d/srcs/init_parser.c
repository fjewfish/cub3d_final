/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corozco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 16:14:19 by corozco           #+#    #+#             */
/*   Updated: 2020/02/14 03:28:35 by corozco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>
#include <unistd.h>

static void		ft_resolution(char *str, t_data *d)
{
	d->tmps.i_tmp = 0;
	d->res.r_x = ft_atoi(&str[1]);
	while ((d->tex.resolu = 1) && str[++d->tmps.i_tmp])
		if (!ft_isdigit(str[d->tmps.i_tmp]) && !ft_isspace(str[d->tmps.i_tmp]))
			ft_ms_error(0, "  -Resolution", str);
	d->tmps.i_tmp = 1;
	while (ft_isspace(str[d->tmps.i_tmp]))
		++d->tmps.i_tmp;
	while (ft_isdigit(str[d->tmps.i_tmp]))
		++d->tmps.i_tmp;
	while (ft_isspace(str[d->tmps.i_tmp]))
		++d->tmps.i_tmp;
	if (str[d->tmps.i_tmp] == '\0')
		ft_ms_error(0, "  -Resolution", str);
	d->res.r_y = ft_atoi(&str[d->tmps.i_tmp]);
	if (d->res.r_x < MIN_DISPLAY_X || d->res.r_x > MAX_DISPLAY_X
	|| d->res.r_y < MIN_DISPLAY_Y || d->res.r_y > MAX_DISPLAY_Y)
	{
		d->res.r_x = (MAX_DISPLAY_X < d->res.r_x) ? MAX_DISPLAY_X : d->res.r_x;
		d->res.r_y = (MAX_DISPLAY_Y < d->res.r_y) ? MAX_DISPLAY_Y : d->res.r_y;
		d->res.r_x = (MIN_DISPLAY_X > d->res.r_x) ? MIN_DISPLAY_X : d->res.r_x;
		d->res.r_y = (MIN_DISPLAY_Y > d->res.r_y) ? MIN_DISPLAY_Y : d->res.r_y;
	}
	if (!(d->zbuffer = (double *)malloc(sizeof(double) * d->res.r_x)))
		ft_ms_error(0, " -Allocating memory (zbuffer)", str);
}

void			parser_map(t_data *d, char *line)
{
	int i;

	if ((d->map.x = ft_strlen_no_space(line)) < 4)
		free_coordinates(d, "  -Small map.", 1);
	if (d->map.error == 0)
		d->map.error = d->map.x;
	else
	{
		if (d->map.error == d->map.x)
			;
		else
			free_map(d, d->map.y - 1, "  -Map.");
	}
	conv_map(d, line, 0, d->map.x);
	if (!(d->map.map[d->map.y] = (int *)malloc(sizeof(int) * d->map.x)))
		free_map(d, d->map.y, " -Allocating memory.");
	i = -1;
	while (++i < d->map.x)
		d->map.map[d->map.y][i] = line[i] - 48;
	d->map.y += 1;
}

static void		center_perser2(t_data *d, char *line)
{
	if (line[0] == '1' && d->tex.north && d->tex.south && d->tex.west
			&& d->tex.east && d->tex.sprite && d->tex.floor
			&& d->tex.sky && d->tex.hand1 && d->tex.hand2 && d->tex.hand3)
	{
		if (is_xpm(d->tex.north) == 1 || is_xpm(d->tex.south) == 1
		|| is_xpm(d->tex.west) == 1 || is_xpm(d->tex.east) == 1
		|| is_xpm(d->tex.sprite) == 1 || is_xpm(d->tex.floor) == 1
		|| is_xpm(d->tex.sky) == 1 || is_xpm(d->tex.hand1) == 1
		|| is_xpm(d->tex.hand2) == 1 || is_xpm(d->tex.hand3) == 1
		|| is_xpm(LIFE0) == 1 || is_xpm(LIFE1) == 1
		|| is_xpm(LIFE2) == 1 || is_xpm(LIFE3) == 1
		|| is_xpm(LIFE4) == 1 || is_xpm(LIFE4) == 1
		|| is_xpm(POISON) == 1 || is_xpm(GAMEOVER))
			ft_ms_error(0, "  -Wrong format.", (void *)0);
		parser_map(d, line);
	}
	else
		ft_ms_error(0, "  -Missing texture/-Resolution.", (void *)0);
}

static void		center_parser(t_data *d, char *line)
{
	if (ft_strncmp(line, "R", 1) == 0 && d->tex.resolu == 0)
		ft_resolution(line, d);
	else if (ft_strncmp(line, "NO", 2) == 0 && !d->tex.north)
		d->tex.north = ft_strdup(&(line[3]));
	else if (ft_strncmp(line, "SO", 2) == 0 && !d->tex.south)
		d->tex.south = ft_strdup(&(line[3]));
	else if (ft_strncmp(line, "WE", 2) == 0 && !d->tex.west)
		d->tex.west = ft_strdup(&(line[3]));
	else if (ft_strncmp(line, "EA", 2) == 0 && !d->tex.east)
		d->tex.east = ft_strdup(&(line[3]));
	else if (ft_strncmp(line, "S", 1) == 0 && *(line + 1)
	!= 'O' && !d->tex.sprite)
		d->tex.sprite = ft_strdup(&(line[2]));
	else if (ft_strncmp(line, "F", 1) == 0 && !d->tex.floor)
		d->tex.floor = ft_strdup(&(line[2]));
	else if (ft_strncmp(line, "C", 1) == 0 && !d->tex.sky)
		d->tex.sky = ft_strdup(&(line[2]));
	else if (ft_strncmp(line, "I", 1) == 0 && !d->tex.hand1)
		d->tex.hand1 = ft_strdup(&(line[2]));
	else if (ft_strncmp(line, "O", 1) == 0 && !d->tex.hand2)
		d->tex.hand2 = ft_strdup(&(line[2]));
	else if (ft_strncmp(line, "P", 1) == 0 && !d->tex.hand3)
		d->tex.hand3 = ft_strdup(&(line[2]));
	else
		center_perser2(d, line);
}

int				init_parser(int fd, t_data *d)
{
	char		*line;

	while ((d->tmps.ret = ft_gnl(fd, &line)) > 0)
	{
		if (line[0] == 0)
		{
			free(line);
			continue ;
		}
		center_parser(d, line);
		free(line);
	}
	if (d->tmps.ret == -1)
		return (-1);
	if (line[0] != 0)
		center_parser(d, line);
	free(line);
	open_file_texture(d, 0);
	return (0);
}
