#include "fractol.h"

static void	create_vignette(t_data *data, char *buffer, t_color col)
{
	int dist[2];
	t_vec2 delta;
	t_color tcol;
	int x;
	int y;
	double dark;

	tcol = col;
	x = 0;
	y = 0;
	dark = 1.5;
	delta.x = fabs((double)(data->win_width / 2  - x));
	delta.y = fabs((double)(data->win_height / 2 - y));
	dist[0] = sqrt(delta.x * delta.x + delta.y * delta.y);
	while (y < data->win_height)
	{
		x = 0;
		while (x < data->win_width)
		{
			delta.x = fabs((double)(data->win_width / 2 - x));
			delta.y = fabs((double)(data->win_height / 2 - y));
			dist[1] = sqrt(delta.x * delta.x + delta.y * delta.y) / 2.5;
			if ((x % 2 != 0 && y % 2 == 0))
			{
				col.b = tcol.b - tcol.b * (double)dist[1] / (double)dist[0] * dark;
				col.r = tcol.r - tcol.r * (double)dist[1] / (double)dist[0] * dark;
				col.g = tcol.g - tcol.g * (double)dist[1] / (double)dist[0] * dark;
			}
			set_image_pixel_color(data, buffer, x + y * data->win_width, col);
			x++;
		}
		y++;
	}
}

void	create_background(t_data *data)
{
	t_color col;
	char *buffer;
	char *buffer2;

	col = hsv(300,0.5,0.5,0);
	data->background = mlx_new_image(data->mlx_ptr, data->win_width, data->win_height); 
	buffer = mlx_get_data_addr(data->background, &data->bits_pix, &data->size_line, &data->endian);
	fill_image(data, 4 * data->win_height * data->win_width, buffer, col);
	create_vignette(data, buffer, col);
}
