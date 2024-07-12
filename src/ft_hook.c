#include "map.h"

/* void	move(t_map *map)
{
	if (mlx_is_key_down(map->mlx, MLX_KEY_A))
	{
		map->player->pa -= 0.2;
		printf("angle key: %f\n", map->player->pa);
		if(map->player->pa < 0)
			map->player->pa += 2*PI;
		map->player->dx = cos(map->player->pa) * 5;
		map->player->dy = sin(map->player->pa) * 5;
	}
    if (mlx_is_key_down(map->mlx, MLX_KEY_D))
	{
		map->player->pa += 0.2;
		if(map->player->pa > 2*PI)
			map->player->pa -= 2*PI;
		map->player->dx = cos(map->player->pa) * 5;
		map->player->dy = sin(map->player->pa) * 5;
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_W))
	{
		map->player->px += map->player->dx;
		map->player->py += map->player->dy;
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_S))
	{
		map->player->px -= map->player->dx;
		map->player->py -= map->player->dy;
	}
} */

void	ft_hook(void *param)
{
	t_map	*map;

	map = param;
	
	if (mlx_is_key_down(map->mlx, MLX_KEY_A))
	{
		map->player->pa -= 0.05;
		if(map->player->pa < 0)
			map->player->pa += 2*PI;
		map->player->dx = cos(map->player->pa) * 5;
		map->player->dy = sin(map->player->pa) * 5;
	}
    if (mlx_is_key_down(map->mlx, MLX_KEY_D))
	{
		map->player->pa += 0.05;
		if(map->player->pa > 2*PI)
			map->player->pa -= 2*PI;
		map->player->dx = cos(map->player->pa) * 5;
		map->player->dy = sin(map->player->pa) * 5;
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_W))
	{
		map->player->px += map->player->dx;
		map->player->py += map->player->dy;
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_S))
	{
		map->player->px -= map->player->dx;
		map->player->py -= map->player->dy;
	}
	mlx_delete_image(map->mlx, map->pmlx_image);
	map->pmlx_image = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(map->mlx, map->pmlx_image, 0, 0);
	randomize_player(map);
}
