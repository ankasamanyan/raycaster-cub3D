

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <stdint.h>
# include <math.h>
# include "../libs/mlx/mlx.h"
# include "../libs/libft/includes/libft.h"
# include "../includes/engine.h"

# define SCREEN_WIDTH 2000
# define SCREEN_HEIGHT 1000
# define TILE 100

# define BUFFERSIZE 20

# define KEY_PRESS 2
# define RED_CROSS 17
# define MOUSE_MOVE 6
# define MOUSE_DOWN 4

# if __linux__

#  define ESC 65307
#  define ZOOM_IN 105
#  define ZOOM_OUT 111
#  define ARROW_UP 65362
#  define ARROW_DWN 65364
#  define ARROW_LEFT 65361
#  define ARROW_RIGHT 65363
#  define SCROLL_DOWN 4
#  define SCROLL_UP 5
#  define LEFT_CLICK 1
#  define RIGHT_CLICK 3
#  define MIDDLE_CLICK 2
#  define PLUS 112
#  define MINUS 109

# elif __APPLE__

#  define ESC 53
#  define ZOOM_IN 34
#  define ZOOM_OUT 31
#  define ARROW_UP 126
#  define ARROW_DWN 125
#  define ARROW_LEFT 123
#  define SCROLL_DOWN 5
#  define SCROLL_UP 4
#  define LEFT_CLICK 1
#  define RIGHT_CLICK 2
#  define MIDDLE_CLICK 3
#  define ARROW_RIGHT 124
#  define W_KEY 13
#  define A_KEY 0
#  define S_KEY 1
#  define D_KEY 2


# endif

typedef enum errno
{
	ARGS,
	READ_FAIL,
	COLOUR,
	NO_CUB,
	INV_CHAR,
	INV_EXT,
	INV_MAP,
	TEXTURE,
	PLAYERS,
	NOPLAYER
}	t_errno;

typedef union s_colour
{
	uint32_t	colour;
	uint8_t		abgr[4];
	struct
	{
		uint8_t	a;
		uint8_t	b;
		uint8_t	g;
		uint8_t	r;
	};
}	t_colour;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_player
{
	t_vector	dir;
	t_vector	pos;
}	t_player;

typedef struct s_texture
{
	void	*img;
	int32_t	width;
	int32_t	height;
}	t_texture;

typedef struct s_legenda
{
	t_texture	*north;
	t_texture	*south;
	t_texture	*west;
	t_texture	*east;
	t_colour	*floor;
	t_colour	*ceiling;
}	t_legenda;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		**map;
	t_player	player;
	int32_t		map_width;
	int32_t		map_height;
	t_legenda	legenda;
	t_img		img;
	t_colour	colour;
	t_vector	vector;
	t_vector 	wall;
}	t_data;

/* general functions */
void	init(t_data *data);
void	free_data(t_data *data);
void	errno(int8_t nbr, char *msg, t_data *data);

/* mlx */
void	key_hooks(t_data *data);
int		key_handler(int keycode, t_data *data);
int		x_close(t_data *data);

/* parsing */
char	*read_file(int32_t fd);
void	error_check(t_data *data, int32_t argc, char **argv);
void	extract_map(t_data *data, char *file);
void	extract_colour(t_data *data, char *colour_str, t_colour *colour);
void	element_check(t_data *data, char **file);
char	*skip_spaces(char **file);
bool	is_space_or_1(char c);
bool	is_valid_char(char c);
bool	is_player(t_data *data, t_player *player, int32_t x, int32_t y);
void	fill_str(char *str, size_t start, size_t end, char c);
int32_t	count_newlines_end(char *file);
int32_t	count_newlines_start(char *file);

/* graphics */
int32_t	rgb_to_int(int32_t r, int32_t g, int32_t b, int32_t a);
int32_t	add_channel(int32_t colour, int32_t channel, int8_t bitshift);
void	print_bits(int32_t nbr);

#endif
