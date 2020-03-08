
#include "fractol.h"

t_color	draw_mandelbrot(t_data *data, char *buf, int x, int y)
{
	int i;
	t_vec2 xy;
	t_vec2 ab[2];
	long double xtemp;
	double angle;

	xy = inverse_transform(xy, data, x, y);
	xy.x += data->frac_pos.x;
	xy.y += data->frac_pos.y;
	ab[0].x = 0;
	ab[0].y = 0;
	i = 0;
	angle = 0;
	while (ab[0].x <= 2 && ab[0].y <= 2 && i++ < data->max_iteration)
	{
		xtemp = ab[0].x * ab[0].x - ab[0].y * ab[0].y + xy.x;
		ab[0].y = 2.0 * ab[0].x * ab[0].y + xy.y;
		ab[0].x = xtemp;
		angle = atan2(ab[1].x - ab[0].x, ab[1].y - ab[0].y) * 180 / M_PI;
		ab[1].x = ab[0].x;
		ab[1].y = ab[0].y;	
	}
	return (set_frac_color(data, color_init(data, 0), angle, i, ab[0]));
}
