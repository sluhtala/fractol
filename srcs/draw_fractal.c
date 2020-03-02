#include "fractol.h"
#include <stdio.h>

static t_vec2 inverse_transform(t_vec2 xy, t_data *data, double x, double y)
{
	xy.x = (long double)x * 4 / (long double)data->win_width  - 2;
	xy.y = (long double)y * 2 / (long double)data->win_height - 1;
	//xy.x += data->frac_pos.x;
	//xy.y += data->frac_pos.y;

	xy.x /= data->scale; 
	xy.y /= data->scale;
	return (xy);
}

static t_color set_frac_color(t_data *data, t_color col, t_vec2 ab, int i)
{
	int iter;
	double d;
	float w;
	float h;

	w = 4 / data->win_width - 2;
	h = 2 / data->win_height - 1;
	d = sqrt(ab.x * ab.x + ab.y * ab.y);
	iter = data->max_iteration;
	col = color_init(data, 0xffffff - 0xffffff * i / iter);
	col.a = 255 - 255 * i / iter;
	//col.g = 255 - 255 * i / iter;
	if (ab.x < 2.0 && ab.y <= 2.0)
	{
		col = color_init(data, 0);
		col.r =  255 - 255 * d ;
		col.g =  20;
		col.b =  20 ;
	}
	return (col);
}

static void	draw_mandelbrot(t_data *data, char *buf)
{
	int x;
	int y;
	int i;
	int iter;
	t_vec2 xy;
	t_vec2 ab;
	t_color col;
	long double xtemp;

	col = color_init(data, 0);
	iter = data->max_iteration;
	printf("\nmax_iter: %d\n", data->max_iteration);
	printf("zoom_lvl: %Lf\n", data->scale);
	printf("frac_p_x: %Lf\n", data->frac_pos.x);
	printf("frac_p_y: %Lf\n", data->frac_pos.y);
	//printf("grid_pos: %f\n", (data->grid_position.x * 4 / data->win_width  - 2 )/ data->scale);
	y = 0;
	while (y < data->win_height)
	{
		x =  0;
		while (x < data->win_width)
		{
			xy = inverse_transform(xy, data, x, y);
			xy.x += data->frac_pos.x;
			xy.y += data->frac_pos.y;
			//xy.x /= data->scale;
			//xy.y /= data->scale;
			ab.x = 0;
			ab.y = 0;
			i = 0;
			while (i < iter && ab.x <= 2 && ab.y <= 2)
			{
				//z^2 + c
				//x2−y2−a, 2xy−b
				xtemp = ab.x * ab.x - ab.y * ab.y + xy.x;
				ab.y = 2.0 * ab.x * ab.y + xy.y;
				ab.x = xtemp;
				i++;
			}
				//set_image_pixel_color(data, data->fractal_buf, x + y * data->win_width ,col);
				col = set_frac_color(data, col, ab, i);
				set_image_pixel_color(data, data->fractal_buf, x + y * data->win_width ,col);
			x++;
		}
		y++;
	}
}

void	draw_fractal(t_data *data, char *buf)
{
	t_color col;
	int image_size;
	
	col = color_init(data, 0);
	col.a = 255;
	image_size = data->win_width * data->win_height;
	fill_image(data, image_size * 4, buf, col);
	draw_mandelbrot(data, buf);

}
