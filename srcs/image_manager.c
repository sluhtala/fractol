#include "fractol.h"

void	fill_image(t_data *data, int buf_size, char *img_buf, t_color color)
{
	int i;

	i = 0;
	while (i < buf_size)
	{
		if (data->endian == 0)
		{
			img_buf[i] = color.b; 
			img_buf[i + 1] = (char)color.g; 
			img_buf[i + 2] = (char)color.r;
			img_buf[i + 3] = (char)color.a;
		}
		else
		{
			img_buf[i] = color.a; 
			img_buf[i + 1] = (char)color.r; 
			img_buf[i + 2] = (char)color.g;
			img_buf[i + 3] = (char)color.b;
		}
		i += 4;
	}
}

void	draw_horizontal_line(t_data *data, char *buffer, int y, t_color col)
{
	int i;

	i = 0;
	while (i < data->win_width)	
	{
		set_image_pixel_color(data, buffer, i + data->win_width * y, col);
		i++;
	}
}

void	draw_vertical_line(t_data *data, char *buffer, int x, t_color col)
{
	int i;

	i = 0;
	while (i < data->win_height)
	{
		set_image_pixel_color(data, buffer, i * data->win_width + x, col);
		i++;
	}
}

void	set_image_pixel_color(t_data *data, char *img_buf, int pos, t_color col)
{
	pos = pos * 4;
	if (data->endian == 0)
	{
		img_buf[pos] = (char)col.b; 
		img_buf[pos + 1] = (char)col.g; 
		img_buf[pos + 2] = (char)col.r;
		img_buf[pos + 3] = (char)col.a;
	}
	else
	{
		img_buf[pos] = (char)col.a; 
		img_buf[pos + 1] = (char)col.r; 
		img_buf[pos + 2] = (char)col.g;
		img_buf[pos + 3] = (char)col.b;
	}
}
