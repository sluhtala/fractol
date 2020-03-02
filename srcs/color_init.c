#include "fractol.h"

t_color	color_init(t_data *data, int hex)
{
	t_color col;

	if (data->bits_pix != 32)
		hex = mlx_get_color_value(data->mlx_ptr, hex);
	col.a = 0;
	col.r = hex >> 16 & 0xff;
	col.g = hex >> 8 & 0xff;
	col.b = hex & 0xff;
	return (col);
}
