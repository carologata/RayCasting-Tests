#include "map.h"

void	put_valid_pixel(mlx_image_t *mlx_image, int x, int y, uint32_t color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		mlx_put_pixel(mlx_image, x, y, color);
}

void	check_delta_to_move_variable(int d, int *variable)
{
	if (d < 0)
		*variable = *variable - 1;
	else
		*variable = *variable + 1;
}

void	slope_lower_1(t_bres *aux, t_coordinate *point, mlx_image_t *mlx_image)
{
	int			x;
	int			y;
	uint32_t	color;
	int			i;

	x = point->x;
	y = point->y;
	color = point->color;
	aux->p = 2 * aux->dy - aux->dx;
	i = 0;
	while (i < aux->abs_dx)
	{
		check_delta_to_move_variable(aux->dx, &x);
		if (aux->p < 0)
			aux->p = aux->p + 2 * aux->abs_dy;
		else
		{
			check_delta_to_move_variable(aux->dy, &y);
			aux->p = aux->p + (2 * aux->abs_dy - 2 * aux->abs_dx);
		}
		put_valid_pixel(mlx_image, x, y, color);
		i++;
	}
}

void	slope_bigger_equal_1(t_bres *aux, t_coordinate *point, mlx_image_t *mlx_image)
{
	int			x;
	int			y;
	uint32_t	color;
	int			i;

	x = point->x;
	y = point->y;
	color = point->color;
	aux->p = 2 * aux->dx - aux->dy;
	i = 0;
	while (i < aux->abs_dy)
	{
		check_delta_to_move_variable(aux->dy, &y);
		if (aux->p < 0)
			aux->p = aux->p + 2 * aux->abs_dx;
		else
		{
			check_delta_to_move_variable(aux->dx, &x);
			aux->p = aux->p + (2 * aux->abs_dx - 2 * aux->abs_dy);
		}
		put_valid_pixel(mlx_image, x, y, color);
		i++;
	}
}

void	bresenham(t_coordinate *point_1, t_coordinate *point_2, mlx_image_t *mlx_image)
{
	t_bres	aux;

	aux.dx = point_2->x - point_1->x;
	aux.dy = point_2->y - point_1->y;
	aux.abs_dx = abs(aux.dx);
	aux.abs_dy = abs(aux.dy);
	if (aux.abs_dx > aux.abs_dy)
		slope_lower_1(&aux, point_1, mlx_image);
	else
		slope_bigger_equal_1(&aux, point_1, mlx_image);
}