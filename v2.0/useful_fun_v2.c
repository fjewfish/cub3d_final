#include "main_header_v2.h"
#include <stdio.h>

int		ft_spaceskip(char *line, int *i)
{
	while ((line[*i] == ' ' || line[*i] == '\t' || line[*i] == '\n')
	|| (line[*i] == '\r' || line[*i] == '\v' || line[*i] == '\f'))
		(*i)++;
	return (1);
}

void	ft_print_parse(t_aio *aio)
{
	 ft_printf("MAP w=%d h=%d\n", aio->map.width, aio->map.height);
	 ft_printf("res=%dx%d\ntex\n%s\n%s\n%s\n%s\n%s\n", aio->res.map_x, aio->res.map_y, aio->tex.east, aio->tex.north, aio->tex.south, aio->tex.sprite, aio->tex.west);
	 ft_printf("PLAYER\n pos_x=%f pos_y=%f dir_x%f dir_y%f      dir_a%f\n", aio->plr.pos_x, aio->plr.pos_y, aio->plr.dir_x, aio->plr.dir_y, aio->plr.dir_a);
	 ft_printf("RAY x=%f y=%f i=%d v=%f w=%f\n", aio->ray.x, aio->ray.y, aio->ray.i,aio->ray.v,aio->ray.w);
	 ft_printf("HIT x=%f y=%f c=%c d=%f\n", aio->hit.x, aio->hit.y, aio->hit.c, aio->hit.d);
	ft_printf("ERRORS:\naio->parse_error.settings -- %d\naio->parse_error.map_trigger -- %d\n", aio->parse_error.settings, aio->parse_error.map_trigger);
	t_list *tmp;
ft_printf("LIST\n");
	tmp = aio->map.list;
	while (tmp->next)
	{
		ft_printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
ft_printf("MAP.MAP\n");
	int i;

	i = 0;
	while(aio->map.map[i])
	{
		ft_printf("%s\n", aio->map.map[i]);
		i++;
	}
ft_printf("SPRITE\n Count = %d\n", aio->map.sprite_count);
i = 0;
while (i < aio->map.sprite_count)
{
	printf("(%f,%f)   ", aio->spr[i].x, aio->spr[i].y);
	i++;
}
ft_printf("\n");
ft_printf("IMG\n");
ft_printf("dst = (char *)(aio->img.adr + (y_con * aio->img.line_length + x_con * (aio->img.bits_per_pixel / 8)) / 4);\n*(unsigned int*)dst = mlx_get_color_value(aio->mlx.ptr, color);\n");
ft_printf("adr = %d\nbits_per_pixel = %d\nline_length = %d\nendian = %d\n", (int)aio->img.adr, (int)aio->img.bits_per_pixel, (int)aio->img.line_length, (int)aio->img.endian);
ft_printf("COEF = %d\n", aio->img.coef_dylib);
}
