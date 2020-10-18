/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c1_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 12:58:17 by fjewfish          #+#    #+#             */
/*   Updated: 2020/10/18 17:16:43 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header_v2.h"
#include "stdio.h"
int		ft_rnswesfc(t_aio *aio, char *line);
int		ft_skip_spases(char *line, int *i);
int		ft_atoi_i(char *line, int *i);
int		ft_resolution(t_aio *aio, char *line, int *i);
int		ft_texture(t_aio *aio, unsigned int **adr, char *line, int *i, char **texture);
int		ft_rgb(unsigned int *color, char *line, int *i);
int		ft_makemap_list(t_aio *aio, char *line);
int		ft_map_parse(t_aio *aio);
int		ft_write_and_cut(t_aio *aio, int *cut_left, int *cut_right);
int		ft_skip_only_space_zero_left(char *line);
int		ft_skip_only_space_zero_right(char *line);
int		ft_skip_only_space_zero_up(char *line);
void	ft_position(t_aio *aio);
int		ft_parse_errors(t_aio *aio);
int		ft_walls(t_aio *aio);
int		ft_step_y_x(t_aio *aio, t_robot_checker *robot, int first, int second);
int		ft_step_x_y(t_aio *aio, t_robot_checker *robot, int first, int second);

int		ft_skip_spases(char *line, int *i)
{
	while ((line[*i] == ' ' || line[*i] == '\t')
	|| (line[*i] == '\r' || line[*i] == '\v' || line[*i] == '\f'))
		(*i)++;
	return (1);
}

int		ft_atoi_i(char *line, int *i)
{
	int	num;

	num = 0;
	ft_skip_spases(line, i);
	while (line[*i] >= '0' && line[*i] <= '9')
	{
		num = num * 10 + (line[*i] - 48);
		(*i)++;
	}
	return (num);
}
/* ************************************************************************** */
int		ft_parse(t_aio *aio, char *cub)
{
	char	*line;
	int		fd;
	int		err;
	int		i;
	err = 1;
	i = 0;
	fd = open(cub, O_RDONLY);
	if (fd == -1)
		return (ft_error_number(-1)); //Error : Couldn't open file (FD)
	while (err == 1)
	{
		err = get_next_line(fd, &line);
		if (err == 1 && aio->parse_error.map_trigger == 0)
			err = ft_rnswesfc(aio, line);//Error : Couldn't parse file (GNL)
		if (err == 1 && aio->parse_error.map_trigger == 1)
		{
			if (ft_skip_only_space_zero_up(line) && aio->parse_error.map_empty_line == 0)
				aio->parse_error.map_empty_line = 1;
			if (aio->parse_error.map_empty_line == 1 && ft_skip_only_space_zero_up(line))
				ft_makemap_list(aio, line);
			else if (aio->parse_error.map_empty_line == 1)
				aio->parse_error.map_trigger = -1;
		}
		if (aio->parse_error.map_trigger == -1 && ft_skip_only_space_zero_up(line))
			return(ft_error_number(-12));
			//err = -12;
			// free(line);
	}
	close(fd);
	ft_lstadd_back(&aio->map.list, ft_lstnew((void *)line));
	err = ft_map_parse(aio);
	// if (err < 0)
	// 	return (ft_error_number(err));//?????
	ft_position(aio);
	//aio->spr = NULL;
	//ft_slist(s);
//ft_print_parse(aio);
	return (ft_parse_errors(aio));
}

int		ft_rnswesfc(t_aio *aio, char *line)
{
	int		i;

	i = 0;
	ft_skip_spases(line, &i);
	if (line[i] == 'R' && line[i + 1] == ' ')
		aio->parse_error.settings = ft_resolution(aio, line, &i);
	else if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		aio->parse_error.settings = ft_texture(aio, &aio->tex.no, line, &i, &aio->tex.north);
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		aio->parse_error.settings = ft_texture(aio, &aio->tex.so, line, &i, &aio->tex.south);
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		aio->parse_error.settings = ft_texture(aio, &aio->tex.we, line, &i, &aio->tex.west);
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		aio->parse_error.settings = ft_texture(aio, &aio->tex.ea, line, &i, &aio->tex.east);
	else if (line[i] == 'S' && line[i + 1] == ' ')
		aio->parse_error.settings = ft_texture(aio, &aio->tex.sp, line, &i, &aio->tex.sprite);

	else if (line[i] == 'F' && line[i + 1] == ' ')
		aio->parse_error.settings = ft_rgb(&aio->tex.fl, line, &i);
	else if (line[i] == 'C' && line[i + 1] == ' ')
		aio->parse_error.settings = ft_rgb(&aio->tex.ce, line, &i);
	else if(line[i] != '\0')
		aio->parse_error.map_trigger = 1;
	//ft_skip_spases(line, &i);
	if (aio->parse_error.settings == 0 && line[i] != '\0' && aio->parse_error.map_trigger != 1)
	{
		return (-10);
	}
	// return (aio->parse_error.settings);
	return (1); //?????
}

int		ft_resolution(t_aio *aio, char *line, int *i)
{
	if (aio->res.map_x != 0 || aio->res.map_y != 0)
		return (-3);
	(*i)++;
	aio->res.map_x = ft_atoi_i(line, i);
	aio->res.map_y = ft_atoi_i(line, i);
	if (aio->res.map_x > aio->res.display_x)
		aio->res.map_x = aio->res.display_x;
	if (aio->res.map_y > aio->res.display_y)
		aio->res.map_y = aio->res.display_y;
	ft_skip_spases(line, i);
	if (aio->res.map_x <= 0 || aio->res.map_y <= 0 || line[*i] != '\0')
		return (-4);
	return (0);
}
//////
int		ft_namecheck(char *arg, char *ext)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
		i++;
	if ((i > 4 && arg[i - 1] == ext[2] && arg[i - 2] == ext[1])
		&& (arg[i - 3] == ext[0] && arg[i - 4] == '.'))
		return (1);
	return (0);
}
//////
int		ft_texture(t_aio *aio, unsigned int **adr, char *line, int *i, char **texture)
{
	int		fd;
	void	*img;
	int		tab[5];
	if (*adr != NULL)
		return (-7);
	(*i) += 2;
	ft_skip_spases(line, i);
	*texture = ft_strdup_gc(&line[*i]);
	(*i) += ft_strlen(*texture);
	if (ft_namecheck(*texture, "xpm") == 0)
		return (-1);
	if ((fd = open(*texture, O_RDONLY)) == -1)
		return (-1);
	close(fd);
	img = mlx_xpm_file_to_image(aio->mlx.ptr, *texture, &tab[0], &tab[1]);
	if (img == NULL || tab[0] != 64 || tab[1] != 64)
		return (-1);
	*adr = (unsigned int *)mlx_get_data_addr(img, &tab[2], &tab[3], &tab[4]);
	free(img);
	return (0);
}

int		ft_rgb(unsigned int *color, char *line, int *i)
{
	int	r;
	int	g;
	int	b;
	if (*color != 0xFF000000)
		return (-5);
	(*i)++;
	r = ft_atoi_i(line, i);
	if (line[*i] != ',')
		return (-6);
	(*i)++;
	g = ft_atoi_i(line, i);
	if (line[*i] != ',')
		return (-6);
	(*i)++;
	b = ft_atoi_i(line, i);
	ft_skip_spases(line, i);
	if (line[*i] != '\0' || r > 255 || g > 255 || b > 255)
		return (-6);
	*color = r * 256 * 256 + g * 256 + b;
	return (0);
}

int		ft_makemap_list(t_aio *aio, char *line)
{
	int i;
	int left;
	int width;
	int len;
	i = 0;

	len = ft_strlen(line);
	left = ft_skip_only_space_zero_left(line);
	width = len - ft_skip_only_space_zero_right(line) - left;
//ft_printf("%s\n%d = len(%d) - right(%d) - left(%d)\n", line, width, len, ft_skip_only_space_zero_right(line), left);
	if (!aio->map.list)
	{
		aio->map.cut_left = left;
		aio->map.width = width;
		aio->map.list = ft_lstnew((void *)line);
		//if (len > aio->map.width)
		//	aio->map.width = len;
	}
	else
	{
		ft_lstadd_back(&aio->map.list, ft_lstnew((void *)line));
		//if (len > aio->map.width)
		//	aio->map.width = len;
	}
	if (left < aio->map.cut_left)
		aio->map.cut_left = left;
	if (width > aio->map.width)
		aio->map.width = width;
	return(0);
}

int		ft_map_parse(t_aio *aio)
{
	int cut_left;
	int cut_right;
	aio->map.height = ft_lstsize(aio->map.list) - 1;
	if (!(aio->map.map = (char **)malloc_gc(aio->map.height * sizeof(char *) + 1)))
		return(-11);
	aio->map.map[aio->map.height] = NULL;
	return (ft_write_and_cut(aio, &cut_left, &cut_right));
}

int		ft_write_and_cut(t_aio *aio, int *cut_left, int *cut_right)
{
	int i;
	int j;
	int k;
	int len;
	t_list *tmp;

	tmp = aio->map.list;
	i = 0;
	while (i < aio->map.height)
	{
		k = 0;
		j = aio->map.cut_left;
		aio->map.map[i] = (char *)malloc_gc(sizeof(char) * aio->map.width);
		aio->map.map[i][aio->map.width] = 0;
		while (((char *)tmp->content)[j] && j < aio->map.width + aio->map.cut_left)
		{
			if (((char *)tmp->content)[j] != '0' && ((char *)tmp->content)[j] != '1' && ((char *)tmp->content)[j] != '2' &&
				((char *)tmp->content)[j] != 'N' && ((char *)tmp->content)[j] != 'S' && ((char *)tmp->content)[j] != 'W' &&
				((char *)tmp->content)[j] != 'E' && ((char *)tmp->content)[j] != ' ')
				return (-12);
			else if (((char *)tmp->content)[j] == ' ')
				aio->map.map[i][k] = '0';
			else
				aio->map.map[i][k] = (((char *)tmp->content)[j]);
			if (((char *)tmp->content)[j] == 'E')
				aio->map.sprite_count++;
			k++;
			j++;
		}
		while (k < aio->map.width)
		{
			aio->map.map[i][k] = '0';
			k++;
		}
		tmp = tmp->next;
		i++;
	}
	return (1);
}

int		ft_skip_only_space_zero_up(char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ' || line[i] == '0')
		i++;
	if (line[i] == '\0')
		return (0);
	return(1);
}


int		ft_skip_only_space_zero_left(char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ' || line[i] == '0')
		i++;
	return (i);
}

int		ft_skip_only_space_zero_right(char *line)
{
	int i;
	int len;

	len = ft_strlen(line);
	i = len - 1;
	while (line[i] == ' ' || line[i] == '0')
		i--;
	return (len - i - 1);
}

void	ft_position(t_aio *aio)
{
	char	c;
	int		i;
	int		j;

	i = -1;
	j = -1;
	int d = 0;
	while (++i < aio->map.height)
	{
		while (++j < aio->map.width)
		{
			c = aio->map.map[i][j];
			if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
			{
				aio->plr.pos_y = (double)i + 0.5;
				aio->plr.pos_x = (double)j + 0.5;
				aio->plr.dir_x = (c == 'E' || c == 'W') ? 1 : 0;
				aio->plr.dir_x *= (c == 'W') ? -1 : 1;
				aio->plr.dir_y = (c == 'S' || c == 'N') ? 1 : 0;
				aio->plr.dir_y *= (c == 'N') ? -1 : 1;
				aio->parse_error.player++;
			}
		}
		j = -1;
	}
}



int		ft_parse_errors(t_aio *aio)
{
	int i;
	int j;

	i = 0;
	 if (aio->res.map_x <= 0 || aio->res.map_y <= 0)
	 	return (ft_error_number(-14));
	 else if ((aio->tex.no == NULL || aio->tex.so == NULL || aio->tex.we == NULL)
	 		|| (aio->tex.ea == NULL || aio->tex.sp == NULL))
	 	return (ft_error_number(-15));
	 else if (aio->tex.ce == 0xFF000000 || aio->tex.fl == 0xFF000000)
	 	return (ft_error_number(-16));
	 else if (aio->parse_error.player == 0)
	 	return (ft_error_number(-17));
	 else if (aio->parse_error.player > 1)
	 	return (ft_error_number(-18));
	 else if (ft_walls(aio) == -1)
	{
		ft_print_parse(aio);
	 	return (ft_error_number(-19));
	}
	while (aio->map.map[i])
	{
		j = 0;
		while (aio->map.map[i][j])
		{
			if (aio->map.map[i][j] == '8' || aio->map.map[i][j] == '9')
				aio->map.map[i][j] = '1';
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_walls(t_aio *aio)
{
	int i;
	t_robot_checker robot;

	i = 0;
	robot.x = -1;
	robot.y = 0;
	robot.start_y = 0;
//ft_printf("HEERE!\n");
	while (i < aio->map.width && robot.x == -1)
	{
		//ft_printf("HEERE! %d\n", i);
		//ft_printf("HEERE! %c\n", aio->map.map[0][0]);
		if (aio->map.map[0][i] == '1')
		{
			//aio->map.map[0][i] = '8';
			robot.x = i;
			robot.start_x = i;
		}
		i++;
	}
//ft_printf("HEERE!\n");
	i = 0;
	while (i >= 0)
	{
		ft_printf("robot(%d,%d)\n", robot.x, robot.y);
		//ft_print_parse(aio);
		if (ft_step_y_x(aio, &robot, -1, 1) == 1)
			i++;
		else if (ft_step_x_y(aio, &robot, 1, 1) == 1)
			i++;
		else if (ft_step_y_x(aio, &robot, 1, -1) == 1)
			i++;
		else if (ft_step_x_y(aio, &robot, -1, -1) == 1)
			i++;
		else
			return (-1);
	}
	return (0);
}

int		ft_step_y_x(t_aio *aio, t_robot_checker *robot, int first, int second)
{
	if (robot->y + first >= 0 && robot->y + first < aio->map.height)
	{
		if(aio->map.map[robot->y + first][robot->x] == '1')
		{
			aio->map.map[robot->y][robot->x] = '8';
			robot->y += first;
			return(1);
		}
		else if(aio->map.map[robot->y + first][robot->x] == '8')
		{
			aio->map.map[robot->y][robot->x] = '9';
			robot->y += first;
			aio->map.map[robot->y][robot->x] = '9';
			return(1);
		}
	}
	if (robot->x + second >= 0 && robot->x + second < aio->map.width)
	{
		if(aio->map.map[robot->y][robot->x + second] == '1')
		{
			aio->map.map[robot->y][robot->x] = '8';
			robot->x += second;
			return(1);
		}
		else if(aio->map.map[robot->y][robot->x + second] == '8')
		{
			robot->x += second;
			aio->map.map[robot->y][robot->x] = '9';
			return(1);
		}
	}
	return (0);
}

int		ft_step_x_y(t_aio *aio, t_robot_checker *robot, int first, int second)
{
	if (robot->x + first >= 0 && robot->x + first < aio->map.width)
	{
		if(aio->map.map[robot->y][robot->x + first] == '1')
		{
			robot->x += first;
			aio->map.map[robot->y][robot->x] = '8';
			return(1);
		}
		else if(aio->map.map[robot->y][robot->x + first] == '8')
		{
			robot->x += first;
			aio->map.map[robot->y][robot->x] = '9';
			return(1);
		}
	}
	if (robot->y + second >= 0 && robot->y + second < aio->map.height)
	{
		if(aio->map.map[robot->y + second][robot->x] == '1')
		{
			robot->y += second;
			aio->map.map[robot->y][robot->x] = '8';
			return(1);
		}
		else if(aio->map.map[robot->y + second][robot->x] == '8')
		{
			robot->y += second;
			aio->map.map[robot->y][robot->x] = '9';
			return(1);
		}
	}
	return (0);
}
	// while (i < aio->map.height)
	// {
	// 	j = 0;
	// 	while (j < aio->map.width)
	// 	{
	// 		if (aio->map.map[i][j] != '1' && i == 0)
	// 			return (-1);
	// 		else if (aio->map.map[i][j] != '1' && i == aio->map.height - 1)
	// 			return (-1);
	// 		else if (aio->map.map[i][j] != '1' && j == 0)
	// 			return (-1);
	// 		else if (aio->map.map[i][j] != '1' && j == aio->map.width - 1)
	// 			return (-1);
	// 		j++;
	// 	}
	// 	i++;
	// }
