#include "main_header_v2.h"

int		ft_atoi_i(char *line, int *i)
{
	int	num;

	num = 0;
	ft_spaceskip(line, i);
	while (line[*i] >= '0' && line[*i] <= '9')
	{
		num = num * 10 + (line[*i] - 48);
		(*i)++;
	}
	return (num);
}

int		ft_res(t_all *aio, char *line, int *i)
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
	ft_spaceskip(line, i);
	if (aio->res.map_x <= 0 || aio->res.map_y <= 0 || line[*i] != '\0')
		return (-4);
	return (0);
}

int		ft_colors(unsigned int *color, char *line, int *i)
{
	int	r;
	int	g;
	int	b;

	if (*color != NONE)
		return (-5);
	(*i)++;
	r = ft_atoi_i(line, i);
	(*i)++;
	g = ft_atoi_i(line, i);
	(*i)++;
	b = ft_atoi_i(line, i);
	ft_spaceskip(line, i);
	if (line[*i] != '\0' || r > 255 || g > 255 || b > 255)
		return (-6);
	*color = r * 256 * 256 + g * 256 + b;
	return (0);
}

void	ft_pos(t_all *aio)
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
				aio->map.err_player++;
			}
		}
		j = -1;
	}
}

//int		ft_slist(t_all *s)
//{
//	int		i;
//	int		j;
//	int		k;

//	if (s->spr != NULL)
//		free(s->spr);
//	if (!(s->spr = malloc(sizeof(t_spr) * s->map.spr)))
//		return (-1);
//	i = 0;
//	j = 0;
//	while (j < s->map.y)
//	{
//		k = 0;
//		while (k < s->map.x)
//		{
//			if (s->map.tab[j][k] == '2')
//			{
//				s->spr[i].y = (double)j + 0.5;
//				s->spr[i++].x = (double)k + 0.5;
//			}
//			k++;
//		}
//		j++;
//	}
//	return (1);
//}

//int		ft_xpm(t_all *aio, unsigned int **adr, char *file)
//{
//	int		fd;
//	void	*img;
//	int		tab[5];

//	if (ft_namecheck(file, "xpm") == 0)
//		return (-1);
//	if ((fd = open(file, O_RDONLY)) == -1)
//		return (-1);
//	close(fd);
//	img = mlx_xpm_file_to_image(aio->mlx.ptr, file, &tab[0], &tab[1]);
//	if (img == NULL || tab[0] != 64 || tab[1] != 64)
//		return (-1);
//	*adr = (unsigned int *)mlx_get_data_addr(img, &tab[2], &tab[3], &tab[4]);
//	free(img);
//	return (0);
//}

int		ft_texture(t_all *aio, unsigned int **adr, char *line, int *i, char **texture)
{
	int		j;

	if (*adr != NULL)
		return (-7);
	(*i) += 2;
	ft_spaceskip(line, i);
	//j = *i;
	//while (line[*i] != ' ' && line[*i] != '\0')
	//	(*i)++;
	//if (!(file = malloc(sizeof(char) * (*i - j + 1))))
	//	return (-8);
	//*i = j;
	//j = 0;
	//while (line[*i] != ' ' && line[*i] != '\0')
	//	file[j++] = line[(*i)++];
	//file[j] = '\0';
	*texture = ft_strdup_gc(&line[*i]);
	//while (line[*i] != ' ' && line[*i] != '\0')
	//	(*i)++;
	(*i) += ft_strlen(*texture);
	j = ft_xpm(aio, adr, *texture);
	//free(file);
	return (j == -1 ? -9 : 0);
}


//int		ft_texture(t_all *aio, unsigned int **adr, char *line, int *i, char **texture)
//{
//	int		j;

//	if (*adr != NULL)
//		return (-7);
//	(*i) += 2;
//	printf("HERE 1\n");
//	ft_spaceskip(line, i);
//	j = *i;
//	while (line[*i] != ' ' && line[*i] != '\0')
//		(*i)++;
//	printf("HERE 2\n");
//	if (!(*texture = malloc(sizeof(char) * (*i - j + 1))))
//		return (-8);
//	printf("HERE 3\n");
//	*i = j;
//	j = 0;
//	printf("HERE 4\n");
//	while (line[*i] != ' ' && line[*i] != '\0')
//		*texture[j++] = line[(*i)++];
//	printf("HERE 5\n");
//	*texture[j] = '\0';
//	printf("HERE F\n");
//	j = ft_xpm(aio, adr, *texture);
//	return (j == -1 ? -9 : 0);
//}


//int		ft_slablen(t_all *aio, char *line)
//{
//	int	i;
//	int	count;

//	i = 0;
//	count = 0;
//	while (line[i] != '\0')
//	{
//		if (line[i] == '0' || line[i] == '1' || line[i] == '2')
//			count++;
//		else if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W')
//			count++;
//		else if (line[i] == 'E')
//			count++;
//		i++;
//	}
//	if (aio->map.width != 0 && aio->map.width  != count)
//		return (-1);
//	return (count);
//}

//char	*ft_slab(t_all *aio, char *line, int *i)
//{
//	char	*slab;
//	int		j;

//	if (!(slab = malloc_gc(sizeof(char) * (ft_slablen(aio, line) + 1))))
//		return (NULL);
//	j = 0;
//	while (line[*i] != '\0')
//	{
//		if ((line[*i] == '0' || line[*i] == '1' || line[*i] == 'N')
//			|| (line[*i] == 'E' || line[*i] == 'S' || line[*i] == 'W'))
//			slab[j++] = line[*i];
//		else if (line[*i] == '2')
//		{
//			slab[j++] = line[*i];
//			aio->map.sprite_count++;
//		}
//		else if (line[*i] != ' ')
//		{
//			//free(slab);
//			return (NULL);
//		}
//		(*i)++;
//	}
//	slab[j] = '\0';
//	return (slab);
//}

//int		ft_map(t_all *aio, char *line, int *i)
//{
//	char	**tmp;
//	int		j;

//	aio->map.err_map = 1;
//	if (!(tmp = malloc_gc(sizeof(char *) * (aio->map.height + 2))))
//		return (-11);
//	j = -1;
//	while (++j < aio->map.height)
//		tmp[j] = aio->map.map[j];
//	if ((tmp[aio->map.height] = ft_slab(aio, line, i)) == NULL)
//	{
//		free(tmp);
//		return (-12);
//	}
//	tmp[aio->map.height + 1] = NULL;
//	if (aio->map.height > 0)
//		free(aio->map.map);
//	aio->map.map = tmp;
//	aio->map.map++;
//	if ((aio->map.width = ft_slablen(aio, line)) == -1)
//		return (-13);
//	return (0);
//}
//int		ft_map(t_all *aio, char *line, int *i)
//{
//	aio->map.err_map = 1;
//	if (!aio->map.list)
//		aio->map.list = ft_lstnew(line);
//	else
//		ft_lstadd_back(&aio->map.list, ft_lstnew(line));
//	while (line[*i])
//	(*i)++;
//	return(0);
//}

int		ft_line(t_all *aio, char *line)
{
	int		i;

	i = 0;
	ft_spaceskip(line, &i);
	if ((line[i] == '1' || aio->map.err_map == 1) && line[i] != '\0')
		aio->map.err_parse = ft_map(aio, line, &i);
		//aio->map.err_parse = ft_make_map_list(aio, line, &i);
	else if (line[i] == 'R' && line[i + 1] == ' ')
		aio->map.err_parse = ft_res(aio, line, &i);
	else if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		aio->map.err_parse = ft_texture(aio, &aio->tex.no, line, &i, &aio->tex.north);
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		aio->map.err_parse = ft_texture(aio, &aio->tex.so, line, &i, &aio->tex.south);
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		aio->map.err_parse = ft_texture(aio, &aio->tex.we, line, &i, &aio->tex.west);
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		aio->map.err_parse = ft_texture(aio, &aio->tex.ea, line, &i, &aio->tex.east);
	else if (line[i] == 'S' && line[i + 1] == ' ')
		aio->map.err_parse = ft_texture(aio, &aio->tex.sp, line, &i, &aio->tex.sprite);

	else if (line[i] == 'F' && line[i + 1] == ' ')
		aio->map.err_parse = ft_colors(&aio->tex.fl, line, &i);
	else if (line[i] == 'C' && line[i + 1] == ' ')
		aio->map.err_parse = ft_colors(&aio->tex.ce, line, &i);

	if (ft_spaceskip(line, &i) && aio->map.err_parse == 0 && line[i] != '\0')
		return (ft_strerror(-10));
	return (aio->map.err_parse < 0 ? ft_strerror(aio->map.err_parse) : 0);
}

int		ft_parse(t_all *aio, char *cub)
{
	char	*line;
	int		fd;
	int		ret;

	ret = 1;
	fd = open(cub, O_RDONLY);
	if (fd == -1)
		return (ft_strerror(-1));
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
	if (ft_line(aio, line) == -1)
			ret = -1;
		free(line);
	}
	close(fd);
	//aio->map.map = (char **)malloc_gc(sizeof(char **) * ft_lstsize(aio->map.list));
	if (ret == -1 || ret == -3)
		return (ft_strerror(ret + 1));
	ft_pos(aio);
	//aio->spr = NULL;
	//ft_slist(s);
	return (ft_parcheck(aio));
}

int		ft_parcheck(t_all *aio)
{
	if (aio->res.map_x <= 0 || aio->res.map_y <= 0)
		return (ft_strerror(-14));
	else if ((aio->tex.no == NULL || aio->tex.so == NULL || aio->tex.we == NULL)
			|| (aio->tex.ea == NULL || aio->tex.sp == NULL))
		return (ft_strerror(-15));
	else if (aio->tex.ce == NONE || aio->tex.fl == NONE)
		return (ft_strerror(-16));
	else if (aio->map.err_player == 0)
		return (ft_strerror(-17));
	else if (aio->map.err_player > 1)
		return (ft_strerror(-18));
	else if (ft_mapcheck(aio) == -1)
		return (ft_strerror(-19));
	return (1);
}

int		ft_mapcheck(t_all *aio)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < aio->map.height)
	{
		j = 0;
		while (j < aio->map.width)
		{
			if (aio->map.map[i][j] != '1' && i == 0)
				return (-1);
			else if (aio->map.map[i][j] != '1' && i == aio->map.height - 1)
				return (-1);
			else if (aio->map.map[i][j] != '1' && j == 0)
				return (-1);
			else if (aio->map.map[i][j] != '1' && j == aio->map.width - 1)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}










//////////////////////////////////////////////////

int		ft_xpm(t_all *s, unsigned int **adr, char *file)
{
	int		fd;
	void	*img;
	int		tab[5];

	if (ft_namecheck(file, "xpm") == 0)
		return (-1);
	if ((fd = open(file, O_RDONLY)) == -1)
		return (-1);
	close(fd);
	img = mlx_xpm_file_to_image(s->mlx.ptr, file, &tab[0], &tab[1]);
	if (img == NULL || tab[0] != 64 || tab[1] != 64)
		return (-1);
	*adr = (unsigned int *)mlx_get_data_addr(img, &tab[2], &tab[3], &tab[4]);
	free(img);
	return (0);
}

//int		ft_texture(t_all *s, unsigned int **adr, char *line, int *i)
//{
//	char	*file;
//	int		j;

//	if (*adr != NULL)
//		return (-7);
//	(*i) += 2;
//	ft_spaceskip(line, i);
//	j = *i;
//	while (line[*i] != ' ' && line[*i] != '\0')
//		(*i)++;
//	if (!(file = malloc(sizeof(char) * (*i - j + 1))))
//		return (-8);
//	*i = j;
//	j = 0;
//	while (line[*i] != ' ' && line[*i] != '\0')
//		file[j++] = line[(*i)++];
//	file[j] = '\0';
//	j = ft_xpm(s, adr, file);
//	free(file);
//	return (j == -1 ? -9 : 0);
//}

int		ft_slablen(t_all *s, char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == '2')
			count++;
		else if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W')
			count++;
		else if (line[i] == 'E')
			count++;
		i++;
	}
	if (s->map.width != 0 && s->map.width != count)
		return (-1);
	return (count);
}

char	*ft_slab(t_all *s, char *line, int *i)
{
	char	*slab;
	int		j;

	if (!(slab = malloc(sizeof(char) * (ft_slablen(s, line) + 1))))
		return (NULL);
	j = 0;
	while (line[*i] != '\0')
	{
		if ((line[*i] == '0' || line[*i] == '1' || line[*i] == 'N')
			|| (line[*i] == 'E' || line[*i] == 'S' || line[*i] == 'W'))
			slab[j++] = line[*i];
		else if (line[*i] == '2')
		{
			slab[j++] = line[*i];
			s->map.sprite_count++;
		}
		else if (line[*i] != ' ')
		{
			free(slab);
			return (NULL);
		}
		(*i)++;
	}
	slab[j] = '\0';
	return (slab);
}

int		ft_map(t_all *aio, char *line, int *i)
{
	char	**tmp;
	int		j;

	aio->map.err_map = 1;
	if (!(tmp = malloc(sizeof(char *) * (aio->map.height + 2))))
		return (-11);
	j = -1;
	while (++j < aio->map.height)
		tmp[j] = aio->map.map[j];
	if ((tmp[aio->map.height] = ft_slab(aio, line, i)) == NULL)
	{
		free(tmp);
		return (-12);
	}
	tmp[aio->map.height + 1] = NULL;
	if (aio->map.height > 0)
		free(aio->map.map);
	aio->map.map = tmp;
	aio->map.height++;
	if ((aio->map.width = ft_slablen(aio, line)) == -1)
		return (-13);
	return (0);
}
