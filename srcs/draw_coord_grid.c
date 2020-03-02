#include "fractol.h"

static void draw_vertical_tics(t_data *data, char *buffer, t_color col, int sizedist[2])
{
	int size;
	int dist;
	int pos;
	int i;
	int y;

	size = sizedist[0];
	dist = sizedist[1];
	y = 0;
	while (y < data->win_height)
	{
		i = 0;
		while (i < size)
		{
			if (data->grid_position.x - size / 2 + i > 0 && data->grid_position.x - size / 2 + i < data->win_width)
			{
				pos = data->grid_position.x - size / 2 + i + data->grid_position.y * data->win_width;
				if (y + data->grid_position.y < data->win_height && y + data->grid_position.y > 0)
					set_image_pixel_color(data, buffer, pos + y * data->win_width, col);
				if (data->grid_position.y - y < data->win_height && data->grid_position.y - y > 0)
					set_image_pixel_color(data, buffer, pos - y * data->win_width, col);
			}
			i++;
		}
		y += dist;
	}

}

static void draw_horizontal_tics(t_data *data, char *buffer, t_color col, int sizedist[2])
{
	int size;
	int dist;
	int pos;
	int i;
	int y;

	size = sizedist[0];
	dist = sizedist[1];
	y = 0;
	while (y < data->win_width)
	{
		i = 0;
		while (i < size)
		{
			if (data->grid_position.y - size / 2 + i > 0 && data->grid_position.y - size / 2 + i < data->win_height)
			{
				pos = data->grid_position.x + (data->grid_position.y - size / 2 + i)  * data->win_width;
				if (y + data->grid_position.x < data->win_width && y + data->grid_position.x > 0)
					set_image_pixel_color(data, buffer, pos + y, col);
				if (data->grid_position.x - y < data->win_width && data->grid_position.x - y > 0)
					set_image_pixel_color(data, buffer, pos - y, col);
			}
			i++;
		}
		y += dist;
	}
}

void	draw_coord_grid(t_data *data, char *buffer)
{
	int dist;
	int size;
	int sd[2];
	t_color col;

	col = color_init(data, 0);
	col.a = 255;
	fill_image(data, data->win_width * data->win_height * 4, buffer, col);
	col = color_init(data, WHITE);
	if (data->grid_position.y >= 0 && data->grid_position.y < data->win_height)
		draw_horizontal_line(data, buffer, data->grid_position.y, col);
	if (data->grid_position.x >= 0 && data->grid_position.x < data->win_width)
		draw_vertical_line(data, buffer, data->grid_position.x, col);
	size = 11;
	dist = 40;
	sd[0] = size;
	sd[1] = dist;
	draw_horizontal_tics(data, buffer, col, sd);
	draw_vertical_tics(data, buffer, col, sd);
}
