#include "map.h"

void fill_cell(t_coordinate *point_1, t_coordinate *point_2, mlx_image_t *mlx_image)
{
    int x;
    int y;
    uint32_t	color;

    x = point_1->x;
    y = point_1->y;
    color = point_1->color;

    while(y <= point_2->y)
    {
        x = point_1->x;
        while(x <= point_2->x)
        {
		    put_valid_pixel(mlx_image, x, y, color);
            x++;
        }
        y++;
    }
}