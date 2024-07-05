#include "map.h"

mlx_t	*init_mlx(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", false);
	if (!mlx)
		return (NULL);
	return (mlx);
}

mlx_image_t	*init_image(mlx_t *mlx)
{
	mlx_image_t	*mlx_image;

	mlx_image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!mlx_image)
	{
		mlx_close_window(mlx);
		return (NULL);
	}
	return (mlx_image);
}

int	init_window(mlx_t *mlx, mlx_image_t *mlx_image)
{
	if (mlx_image_to_window(mlx, mlx_image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		return (-1);
	}
	return (0);
}
