#ifndef MAP_H
# define MAP_H

# include <MLX42/MLX42.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 1024
# define HEIGHT 512
# define SIZE 8
# define CELL 64
# define DR 0.0174533

# ifndef PI
#  define PI 3.14159
# endif

typedef struct s_player
{
	int			px;
	int			py;
	double		dirx;
	double		diry;
	double		dx;
	double		dy;
	double		pa;
}				t_player;

typedef struct s_map
{
	uint32_t	width;
	uint32_t	height;
	mlx_t		*mlx;
	mlx_image_t	*mlx_image;
	mlx_image_t	*pmlx_image;
	char		**frame;
	t_player	*player;
}				t_map;

typedef struct s_coordinate
{
	int			x;
	int			y;
	uint32_t	color;
}				t_coordinate;

typedef struct s_bres
{
	int			dx;
	int			dy;
	int			abs_dx;
	int			abs_dy;
	int			p;
}				t_bres;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strchr(const char *s, int c);
void			*ft_calloc(size_t nmemb, size_t size);
int				ft_count_len(char *next_line);
char			*ft_get_line(char *next_line);
char			*ft_create_next_line(char *next_line);
char			*ft_read_file(char *buffer, char *next_line, int fd);
char			*get_next_line(int fd);

mlx_t			*init_mlx(void);
mlx_image_t		*init_image(mlx_t *mlx);
int				init_window(mlx_t *mlx, mlx_image_t *mlx_image);

void			randomize_map(t_map *map);

void			bresenham(t_coordinate *point_1, t_coordinate *point_2,
					mlx_image_t *mlx_image);
void			slope_bigger_equal_1(t_bres *aux, t_coordinate *point,
					mlx_image_t *mlx_image);
void			slope_lower_1(t_bres *aux, t_coordinate *point,
					mlx_image_t *mlx_image);
void			check_delta_to_move_variable(int d, int *variable);
void			put_valid_pixel(mlx_image_t *mlx_image, int x, int y,
					uint32_t color);

void			fill_cell(t_coordinate *point_1, t_coordinate *point_2,
					mlx_image_t *mlx_image);

void			randomize_player(t_map *map);

void			ft_hook(void *param);
// void			move(t_map *map);

#endif