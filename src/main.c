#include "map.h"

int32_t	main(void)
{
	int			i;
	// int j;
	int			fd;
	t_map 		*map;
	mlx_t		*mlx;
	mlx_image_t	*mlx_image;

	map = malloc(sizeof(t_map));

	i = 0;
	fd = open("map.txt", O_RDWR);
	map->frame = malloc(SIZE * sizeof(char *));
	while (i < SIZE)
	{
		map->frame[i] = get_next_line(fd);
		// printf("map line: %s\n", map->frame[i]);
		i++;
	}

	map->player = malloc(sizeof(t_player));
    map->player->px = 314;
    map->player->py = 257;
	map->player->pa = (1.92);
	map->player->dx = cos(map->player->pa) * 5;
    map->player->dy = sin(map->player->pa) * 5;

	mlx = init_mlx();
	if (mlx == NULL)
		printf("mlx error\n");
	mlx_image = init_image(mlx);
	if (mlx_image == NULL)
		printf("mlx image error\n");

	map->mlx = mlx;
	map->mlx_image = mlx_image;
	
	/* Load texture */
	mlx_texture_t *wall;
	mlx_image_t *wall_image;
	
    wall = mlx_load_png("textures/1wall.png");
	map->texture = wall;
	// wall_image = mlx_texture_to_image(mlx, wall);
	/* ------------ */

	randomize_map(map);
	if (init_window(mlx, mlx_image) == -1)
		printf("window error\n");

	mlx_loop_hook(mlx, ft_hook, map);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
