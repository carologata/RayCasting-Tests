#include "map.h"

uint32_t	texture_to_rgb(mlx_texture_t *texture, int x, int y)
{
	uint8_t	*rgb;

    /* c = T[(int)(ty*32) + (int)tx] */
	rgb = &texture->pixels[(y * texture->width + x) * texture->bytes_per_pixel];
	return (rgb[0] << 24 | rgb[1] << 16 | rgb[2] << 8 | rgb[3]);
}
