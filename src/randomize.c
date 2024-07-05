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
	t_coordinate point_5;
	t_coordinate point_6;

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


	/* HORIZONTAL LINES */
	double aTan, ra, rx, ry, xo, yo; 
	int dof, mx, my;
	ra = map->player->pa;
	aTan = (-1)/tan(ra);
	rx = 0;
	ry = 0;

	if(ra == 0 || ra == PI)
	{
		rx = map->player->px;
		ry = map->player->py;
	}
	else if(ra > PI) //looking up
	{
		ry = (((int) map->player->py >> 6) << 6) - 0.0001;
		rx = (map->player->py-ry)*aTan + map->player->px;
		yo = -64;
		xo = (-yo)*aTan;
	}
	else if(ra < PI) //looking down
	{
		ry = (((int) map->player->py >> 6) << 6) + 64;
		rx = (map->player->py-ry)*aTan + map->player->px;
		yo = 64;
		xo = (-yo)*aTan;
	}

	dof = 0;
	while(dof < 8)
	{
		mx = abs((int)(rx)>>6);
		my = abs((int)(ry)>>6);
		if(mx < SIZE && my < SIZE && map->frame[mx][my] == 1)
			dof = 8;
		else
		{
			rx += xo;
			ry += yo;
			dof += 1;
		}
	}
	
	point_5.x = map->player->px;
	point_5.y = map->player->py;
	point_5.color = 0xFF0000FF;
	point_6.x = rx;
	point_6.y = ry;
	point_6.color = 0xFF0000FF;

	bresenham(&point_5, &point_6, map->pmlx_image);
}