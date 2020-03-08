
#include "fractol.h"

t_color	draw_julia(t_data *data, char *buf, int x, int y)
{
	int				i;
	static t_vec2	xy;
	t_vec2			ab[2];
	long double		xtemp;
	double			angle;

	i = 0;
	ab[0] = inverse_transform(ab[0], data, x, y);
	ab[0].x += data->frac_pos.x;
	ab[0].y += data->frac_pos.y;
	if (data->opt.screen_lock == 1)
	{
		xy.x = data->mouse.track_x * 1 / data->win_width - 0.5;
		xy.y = data->mouse.track_y * 2 / data->win_height - 1;
	}
	angle = 0;
	while (ab[0].x * ab[0].x + ab[0].y * ab[0].y < 4 && i++ < data->max_iteration)
	{
		xtemp = ab[0].x * ab[0].x - ab[0].y * ab[0].y + xy.x;
		ab[0].y = 2.0 * ab[0].x * ab[0].y + xy.y;
		ab[0].x = xtemp;;
	}
	angle = 340;
	return (set_frac_color(data, color_init(data, 0), angle, i, ab[0]));
}

/*
R = escape radius  # choose R > 0 such that R**2 - R >= sqrt(cx**2 + cy**2)

for each pixel (x, y) on the screen, do:   
{
    zx = scaled x coordinate of pixel # (scale to be between -R and R)
       # zx represents the real part of z.
    zy = scaled y coordinate of pixel # (scale to be between -R and R)
       # zy represents the imaginary part of z.

    iteration = 0
    max_iteration = 1000
  
    while (zx * zx + zy * zy < R**2  AND  iteration < max_iteration) 
    {
        xtemp = zx * zx - zy * zy
        zy = 2 * zx * zy  + cy 
        zx = xtemp + cx
    
        iteration = iteration + 1 
    }
  
    if (iteration == max_iteration)
        return black;
    else
        return iteration;
}
*/
