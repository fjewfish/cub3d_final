/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c2_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <fjewfish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 12:58:26 by fjewfish          #+#    #+#             */
/*   Updated: 2020/10/16 00:03:49 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header_v2.h"

void	ft_pos(t_aio *aio)
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

//int		ft_slist(t_aio *s)
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

//int		ft_xpm(t_aio *aio, unsigned int **adr, char *file)
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



//int		ft_texture(t_aio *aio, unsigned int **adr, char *line, int *i, char **texture)
//{
//	int		j;

//	if (*adr != NULL)
//		return (-7);
//	(*i) += 2;
//	printf("HERE 1\n");
//	ft_skip_spases(line, i);
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


//int		ft_slablen(t_aio *aio, char *line)
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

//char	*ft_slab(t_aio *aio, char *line, int *i)
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

//int		ft_map(t_aio *aio, char *line, int *i)
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


int		ft_parcheck(t_aio *aio)
{
	if (aio->res.map_x <= 0 || aio->res.map_y <= 0)
		return (ft_error_number(-14));
	else if ((aio->tex.no == NULL || aio->tex.so == NULL || aio->tex.we == NULL)
			|| (aio->tex.ea == NULL || aio->tex.sp == NULL))
		return (ft_error_number(-15));
	else if (aio->tex.ce == NONE || aio->tex.fl == NONE)
		return (ft_error_number(-16));
	else if (aio->map.err_player == 0)
		return (ft_error_number(-17));
	else if (aio->map.err_player > 1)
		return (ft_error_number(-18));
	else if (ft_mapcheck(aio) == -1)
		return (ft_error_number(-19));
	return (1);
}

int		ft_mapcheck(t_aio *aio)
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





