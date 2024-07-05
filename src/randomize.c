#include "map.h"

void	randomize_map(t_map *map)
{
	int i;
	int j;
	t_coordinate point_1;
	t_coordinate point_2;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			point_1.x = CELL * j;
			point_1.y = CELL * i;
			point_2.x = (CELL * j) + (CELL - 1);
			point_2.y = (CELL * i) + (CELL - 1);
			if (map->frame[i][j] == '1')
            {
				point_1.color = 0xffffffff;
				point_2.color = 0xffffffff;
            }
			else
            {
				point_1.color = 0x00000000;
				point_2.color = 0x00000000;
            }
			fill_cell(&point_1, &point_2, map->mlx_image);
            j++;
		}
        i++;
	}
}

void	randomize_player(t_map *map)
{
	t_coordinate point_1;
	t_coordinate point_2;
	t_coordinate point_3;
	t_coordinate point_4;

	point_1.x = map->player->px - 5;
	point_1.y = map->player->py - 5;
	point_1.color = 0xFFFF00FF;
	point_2.x = map->player->px + 5;
	point_2.y = map->player->py + 5;
	point_2.color = 0xFFFF00FF;

	fill_cell(&point_1, &point_2, map->pmlx_image);
	
	// printf("angle player: %f\n", map->player->pa);

	map->player->dirx = (20 * cos(map->player->pa)) + map->player->px;
	map->player->diry = (20 * sin(map->player->pa)) + map->player->py;

	point_3.x = map->player->px;
	point_3.y = map->player->py;
	point_3.color = 0xFFFF00FF;
	point_4.x = map->player->dirx;
	point_4.y = map->player->diry;
	point_4.color = 0xFFFF00FF;

	bresenham(&point_3, &point_4, map->pmlx_image);
}