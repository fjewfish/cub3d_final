#ifndef MAIN_HEADER_V2_H
# define MAIN_HEADER_V2_H

#include "libft/libft.h"
#include "mlx/mlx.h"
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>

# define BLUE 0x000000FF
# define PURPLE 0x00FF00FF
# define WHITE 0x00FFFFFF
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLACK 0x00000000

# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# define SPEED 7
# define TURN 0.05

# define ANG 0.57595865315


# define WALL 1
# define ITEM 2
# define POS 3

# define DARKNESS 40

//MAlLOC_GC
# define M_ADD 1
# define M_REMOVE 0
typedef char		t_bool;

typedef struct	s_parse_error
{
	int			map_trigger;
	int			map_empty_line;
	int			settings;
	int			player;
}				t_parse_error;

typedef struct	s_mapmod
{
	int			on_off;
	double		first_hit_x;
	double		first_hit_y;
	double		last_hit_x;
	double		last_hit_y;
}				t_mapmod;

typedef struct	s_mlx
{
	void			*ptr;
}				t_mlx;

typedef struct	s_win
{
	void			*ptr;
}				t_win;

typedef struct	s_img
{
	void			*ptr;
	unsigned int	*adr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}				t_img;

typedef struct	s_map
{
	int			cut_after;
	int			cut_left;
	int			cut_right;
	char		**map;
	int			width;
	int			height;
	int			sprite_count;
	t_list		*list;
}				t_map;

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

typedef struct	s_aio
{
	t_parse_error	parse_error;
	t_mapmod		mapmod;
	t_mlx			mlx;
	t_win			win;
	t_img			img;
	t_tex			tex;
	t_res			res;
	t_map			map;
	t_player		plr;
	t_ray			ray;
	t_hit			hit;
	t_key			key;
}				t_aio;

//	A_MAIN
int			ft_cub(char *cub, int screenshot);
//	B_INITIALIZATION
void		ft_initialization(t_aio *aio);
void		ft_initialization_2(t_aio *aio);
void		ft_initialization_3(t_aio *aio);




//	CHEKER
int		ft_savecheck(char *arg, char *save);
int		ft_namecheck(char *arg, char *ext);
//	PARSE
int		ft_parse(t_aio *aio, char *cub);
//	ERROR
int		ft_error_number(int err);
int		ft_close(t_aio *aio, int win);
//	USEFUL_FUN
int		ft_spaceskip(char *line, int *i);
//	BMP_SAVE
int		ft_bmp_save(t_aio *aio);
//PUT_IMAGE
int		ft_draw(t_aio *s);
void	ft_screen(t_aio *s);
void	ft_ray(t_aio *s);
void	ft_dir(t_aio *s);
void	ft_ver(t_aio *s);
void	ft_hor(t_aio *s);
void			ft_stock(t_aio *aio);
void			ft_column(t_aio *aio, int size);
int				ft_size(t_aio *aio);
unsigned int	ft_pixel(t_aio *aio, double i);
int		ft_is(int n, char c);
//
int		ft_parcheck(t_aio *s);
int		ft_mapcheck(t_aio *aio);
void	ft_print_parse(t_aio *aio);
int		ft_map(t_aio *aio, char *line, int *i);
int		ft_xpm(t_aio *s, unsigned int **adr, char *file);
int		ft_make_map_list(t_aio *aio, char *line, int *i);
//KEY
int		ft_press(int key, void *arg);
int		ft_set(t_aio *s, int key, int set);
int		ft_release(int key, void *arg);
int		ft_key(t_aio *aio);
unsigned int	ft_shadow(t_aio *aio, unsigned int col);
//MAP
void	ft_map_mode(t_aio *aio);
void	ft_map_mini(t_aio *aio);



void	ft_pos(t_aio *aio);


//	M_MALLOC_GC
void		*malloc_gc(size_t sizemem);
void		*calloc_gc(size_t nmemb, size_t size);
void		free_gc(void *ptr);
static int	pointer_compare(void *ptr1, void *ptr2);
static void	pointer_free(void *ptr);
void		memory_manager(void *ptr, t_bool action);
static void	delete(t_list *lst, void (*del)(void *));
void		ft_lstdelel(t_list **lst, void *content, int (*cmp)(void *, void *),
						void (*del)(void *));
char		*ft_strdup_gc(char *s1);

#endif
