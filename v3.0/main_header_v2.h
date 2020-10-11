#ifndef MAIN_HEADER_V2_H
# define MAIN_HEADER_V2_H

#include "libft/libft.h"
#include "mlx/mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>

# define NONE 0xFF000000
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define MAGENTA 0x00FF00FF
# define YELLOW 0x00FFFF00
# define CYAN 0x0000FFFF

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# define SPEED 10
# define TURN 0.05

# define ANG 0.57595865315


# define WALL 1
# define POS 2
# define SPRITE 3
# define DECOR 4
# define PICK 5
# define DOOR 6
# define ENEMY 7

# define SHADOW 35

//MAlLOC_GC
# define M_ADD 1
# define M_REMOVE 0
typedef char		t_bool;

typedef struct	s_mlx
{
	void			*ptr;
	// int				pid;
}				t_mlx;

typedef struct	s_win
{
	void			*ptr;
	// int				x;
	// int				y;
	// int				m;
}				t_win;

typedef struct	s_img
{
	void			*ptr;
	unsigned int	*adr;
	int				bits_per_pixel;
	int				line_length;
	//int				end;
	int				endian;
	// int				fsh;
}				t_img;

typedef struct	s_tex
{
	char		*north;
	char		*south;
	char		*east;
	char		*west;
	char		*sprite;
	unsigned int	*no;
	unsigned int	*so;
	unsigned int	*ea;
	unsigned int	*we;
	unsigned int	*sp;
	unsigned int	ce;
	unsigned int	fl;
}				t_tex;

typedef struct	s_res
{
	int			map_x;
	int			map_y;
	int			display_x;
	int			display_y;
}				t_res;

typedef struct	s_map
{
	char			**map;
	int			width;
	int			height;
	//int			x;
	//int			y;
	int			sprite_count;
	int			err_map;
	int			err_parse;
	int			err_player;
	t_list		*list;
}				t_map;

typedef struct	s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		dir_a;
}				t_player;

typedef struct	s_ray
{
	double			x;
	double			y;
	int				i;
	double			v;
	double			w;
}				t_ray;

typedef struct	s_stk
{
	double			x;
	double			y;
	double			d;
}				t_stk;

typedef struct	s_hit
{
	double			x;
	double			y;
	double			d;
	char			c;
}				t_hit;

typedef struct	s_key
{
	int				e;
	int				w;
	int				a;
	int				s;
	int				d;
	int				l;
	int				r;
	int				h;
	int				x;
}				t_key;

typedef struct	s_all
{
	t_mlx			mlx;
	t_win			win;
	t_img			img;
	t_tex			tex;
	t_res			res;
	t_map			map;
	t_player		plr;
	t_ray			ray;
	t_stk			*stk;
	t_hit			hit;
	t_key			key;
}				t_all;

//	MALLOC_GC
static void	delete(t_list *lst, void (*del)(void *));
void		ft_lstdelel(t_list **lst, void *content, int (*cmp)(void *, void *),
						void (*del)(void *));
void	*malloc_gc(size_t sizemem);
void	*calloc_gc(size_t nmemb, size_t size);
void	free_gc(void *ptr);
static int		pointer_compare(void *ptr1, void *ptr2);
static void		pointer_free(void *ptr);
void			memory_manager(void *ptr, t_bool action);
char	*ft_strdup_gc(char *s1);
//	CHEKER
int		ft_savecheck(char *arg, char *save);
int		ft_namecheck(char *arg, char *ext);
//	MAIN_CUB
int		ft_cub(char *cub, int bmp);
//	INITIALIZATION
void		ft_initialization(t_all *aio);
//	PARSE
int		ft_parse(t_all *aio, char *cub);
//	ERROR
int		ft_strerror(int err);
int		ft_close(t_all *aio, int win);
//	USEFUL_FUN
int		ft_spaceskip(char *line, int *i);
//	BMP_SAVE
int		ft_bmp_save(t_all *aio);









//PUT_IMAGE
int		ft_draw(t_all *s);
void	ft_screen(t_all *s);
void	ft_ray(t_all *s);
void	ft_dir(t_all *s);
void	ft_ver(t_all *s);
void	ft_hor(t_all *s);
//int		ft_draw(t_all *aio);
//void	ft_screen(t_all *aio);
//void	ft_ray(t_all *aio);
//void	ft_dir(t_all *aio);
//void	ft_ver(t_all *aio);
//void	ft_hor(t_all *aio);
void			ft_stock(t_all *aio);
void			ft_column(t_all *aio, int size);
int				ft_size(t_all *aio);
unsigned int	ft_pixel(t_all *aio, double i);
int		ft_is(int n, char c);






int		ft_parcheck(t_all *s);
int		ft_mapcheck(t_all *aio);
void	ft_print_parse(t_all *aio);
int		ft_map(t_all *aio, char *line, int *i);
int		ft_xpm(t_all *s, unsigned int **adr, char *file);
int		ft_make_map_list(t_all *aio, char *line, int *i);






//KEY
int		ft_press(int key, void *arg);
int		ft_set(t_all *s, int key, int set);
int		ft_release(int key, void *arg);
int		ft_key(t_all *aio);
unsigned int	ft_shadow(t_all *aio, unsigned int col);






//MAP
void	ft_map_mode(t_all *aio);
#endif
