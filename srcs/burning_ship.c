
#include "fractol.h"

static long double ldabs(long double num)
{
	if (num < 0)
		return (num * -1);
	else
		return (num);
}

t_color	draw_burning_ship(t_data *data, char *buf, int x, int y)
{
	int i;
	t_vec2 xy;
	t_vec2 ab[2];
	long double xtemp;
	double angle;

	xy = inverse_transform(xy, data, x, y);
	xy.x += data->frac_pos.x;
	xy.y += data->frac_pos.y;
	ab[0].x = xy.x;
	ab[0].y = xy.y;
	i = 0;
	angle = 0;
	while (ab[0].x * ab[0].x + ab[0].y * ab[0].y < 4 && i++ < data->max_iteration)
	{
		xtemp = ab[0].x * ab[0].x - ab[0].y * ab[0].y + xy.x;
		ab[0].y = ldabs((2.0 * ab[0].x * ab[0].y + xy.y));
		ab[0].x = ldabs(xtemp);
		angle = atan2(ab[1].x - ab[0].x, ab[1].y - ab[0].y) * 180 / M_PI;
		ab[1].x = ab[0].x;
		ab[1].y = ab[0].y;	
	}
	return (set_frac_color(data, color_init(data, 0), angle, i, ab[0]));
}
