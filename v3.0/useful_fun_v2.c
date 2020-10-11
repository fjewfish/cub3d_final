#include "main_header_v2.h"

int		ft_spaceskip(char *line, int *i)
{
	while ((line[*i] == ' ' || line[*i] == '\t' || line[*i] == '\n')
	|| (line[*i] == '\r' || line[*i] == '\v' || line[*i] == '\f'))
		(*i)++;
	return (1);
}

void	ft_print_parse(t_all *aio)
{
	//int i;

	//i = 0;
	//while(aio->map.map[i])
	//{
	//	printf("%s\n", aio->map.map[i]);
	//	i++;
	//}
	printf("MAP w=%d h=%d\n", aio->map.width, aio->map.height);
	printf("res=%dx%d\ntex\n%s\n%s\n%s\n%s\n%s\n", aio->res.map_x, aio->res.map_y, aio->tex.east, aio->tex.north, aio->tex.south, aio->tex.sprite, aio->tex.west);
	printf("PLAYER\n pos_x=%f pos_y=%f dir_x%f dir_y%f\n", aio->plr.pos_x, aio->plr.pos_y, aio->plr.dir_x, aio->plr.dir_y);
	printf("RAY x=%f y=%f i=%d v=%f w=%f\n", aio->ray.x, aio->ray.y, aio->ray.i,aio->ray.v,aio->ray.w);
	printf("HIT x=%f y=%f c=%c d=%f\n", aio->hit.x, aio->hit.y, aio->hit.c, aio->hit.d);
}
