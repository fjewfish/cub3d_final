/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corozco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 22:32:23 by corozco           #+#    #+#             */
/*   Updated: 2020/02/14 00:34:37 by corozco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include "libft.h"
# include <math.h>

# define MAX_DISPLAY_X 2560
# define MAX_DISPLAY_Y 1440
# define MIN_DISPLAY_X 400
# define MIN_DISPLAY_Y 200
# define TEXS 640
# define LIFE0 "textures/comun/life0.xpm"
# define LIFE1 "textures/comun/life1.xpm"
# define LIFE2 "textures/comun/life2.xpm"
# define LIFE3 "textures/comun/life3.xpm"
# define LIFE4 "textures/comun/life4.xpm"
# define LIFE5 "textures/comun/life5.xpm"
# define POISON "textures/comun/poison.xpm"
# define GAMEOVER "textures/comun/gameover.xpm"

typedef struct	s_tex
{
	char		*north;
	char		*south;
	char		*east;
	char		*west;
	char		*sprite;
	char		*sky;
	char		*floor;
	char		*hand1;
	char		*hand2;
	char		*hand3;
	int			resolu;
}				t_tex;

typedef struct	s_res
{
	int			r_x;
	int			r_y;
}				t_res;

typedef struct	s_map
{
	int			**map;
	int			mapwidth;
	int			mapheight;
	int			x;
	int			y;
	int			boolean;
	int			error;
}				t_map;

typedef	struct	s_spr
{
	double		x;
	double		y;
	int			texture;
	double		spritedist;
}				t_spr;

typedef struct	s_move
{
	int			up;
	int			down;
	int			left;
	int			right;
	int			qleft;
	int			eright;
}				t_move;

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
	int			a;
	int			b;
}				t_img;

typedef struct	s_tmp
{
	int			ret;
	int			i_tmp;
	int			cmp_map;
	char		*s_tmp;
}				t_tmp;

typedef struct	s_floor
{
	double		floorxwall;
	double		floorywall;
	double		distplayer;
	double		currentdist;
	double		weight;
	double		currentfloorx;
	double		currentfloory;
	int			floortexx;
	int			floortexy;
}				t_floor;

typedef struct	s_player
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		olddirx;
	double		oldplanex;
	int			mobile;
	int			life;
}				t_player;

typedef struct	s_raycast
{
	int			ln;
	double		camerax;
	double		raydirx;
	double		raydiry;
	int			mapx;
	int			mapy;
	double		deltadistx;
	double		deltadisty;
	int			stepx;
	int			stepy;
	double		sidedistx;
	double		sidedisty;
	int			side;
	double		perpwalldist;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			texnum;
	int			color;
	int			texx;
	double		wallx;
}				t_raycast;

/*
** sp + rt + move = movement
** zbuffer ... texy = sprites
*/

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_res		res;
	t_img		img;
	t_tex		tex;
	t_img		txt[20];
	double		sp;
	double		rt;
	t_move		move;
	double		*zbuffer;
	t_spr		*sprite;
	int			sprcount;
	int			cmp_sp;
	double		spritex;
	double		spritey;
	double		transformx;
	double		transformy;
	int			spritescreenx;
	int			spriteheight;
	int			spritewidth;
	int			drawstarty;
	int			drawendy;
	int			drawstartx;
	int			drawendx;
	int			uptoggler;
	int			downtoggler;
	int			lefttoggler;
	int			righttoggler;
	int			texy;
	t_map		map;
	t_tmp		tmps;
	t_player	pl;
	t_floor		flr;
	t_raycast	rtc;
}				t_data;

void			init(t_data *d);

/*
**	Error
*/

void			open_file_texture(t_data *d, int fd);
int				error_management(int ac, char **av);
void			ft_ms_error(int i, char *str, char *line);
void			free_coordinates(t_data *d, char *sms, int key);
void			free_map(t_data *d, int i, char *sms);

/*
**	parcing
*/

void			ft_init_map(char *av, t_data *d);
int				init_parser(int fd, t_data *d);
void			conv_map(t_data *d, char *line, int i, int y);
void			ft_verif(t_data *d, int **map, int x, int y);
int				is_xpm(char *av);

/*
** raycasting
*/

int				raycasting(t_data *d);
void			perform_dda(t_data *d, int hit);

/*
**	draw
*/

void			draw_sky(t_data *d);
void			draw_wall(t_data *d, int x, int y, int texy);
void			draw_floor(t_data *d, int x);

/*
**	move
*/

int				move(t_data *d);
void			ft_press(t_data *d);

/*
**	sprites
*/

void			sprites_casting(t_data *d, int i);

/*
**	bmp
*/

void			fill_bmp(char **data, t_data *d);
void			header_bmp(char **data, t_data *d);
void			export_bmp(char *filename, t_data *d);
char			*create_bmp_filename(char *file, int i, t_data *d);

#endif
