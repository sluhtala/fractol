/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:58:45 by sluhtala          #+#    #+#             */
/*   Updated: 2020/02/27 20:32:02 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include <math.h>
#include <stdio.h>

static int		close_program(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	exit(0);
	return (0);
}

static void move(int key, t_data *data)
{
	int amount;

	amount = 20;
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	if (key == UP_KEY)
		data->img_posy -= amount;
	if (key == DOWN_KEY)
		data->img_posy += amount;
	if (key == RIGHT_KEY)
		data->img_posx += amount;
	if (key == LEFT_KEY)
		data->img_posx -= amount;
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->background, 0, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->image, data->img_posx, data->img_posy);
}

/*
**
**
**
**
*/

static int		input_manager(int key, t_data *data)
{
	if (key == ESC_KEY || key == 12)
		close_program(data);
	if (key == UP_KEY || key == DOWN_KEY ||
	key == RIGHT_KEY || key == LEFT_KEY)
		move(key, data);
	if (key == 8 || key == 18 || key == 19)
	{
		mlx_clear_window(data->mlx_ptr, data->mlx_win);
		if (key != 8)
			data->scale += key * 2 - 37;
		if (key == 18)
			;// zoom out
		if (key == 19)
			;// zoom in
		if (key == 8)
		{
			data->img_posx = 0;
			data->img_posy = 0;
			mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->background, 0, 0);
			mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->image, 0, 0);
		}
	}
	return (key);
}

/*
**	- Initialize mlx
**	- Set screen dimensions
*/

static t_color	color_init(t_data *data, int hex)
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

static t_data initialize(t_data *data)
{
	
	data->mlx_ptr = mlx_init();
	data->win_width = 1920;
	data->win_height = 1080;
	data->img_posx = 0;
	data->img_posy = 0;
	data->scale = 0;
	if (!(data->mlx_win = mlx_new_window(data->mlx_ptr,
	data->win_width, data->win_height, "FDF")))
		error_manager("Error opening window.");
	return (*data);
}

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

void	draw_coord_grid(t_data *data, char *buffer, t_color col)
{
	int i;
	int y;
	int pos;
	int dist;
	int size;

	draw_horizontal_line(data, buffer, data->win_height / 2, col);
	draw_vertical_line(data, buffer, data->win_width / 2, col);
	size = 20;
	dist = 20;
	i = 0;
	y = 0;

	while (y < data->win_height)
	{
		i = 0;
		while (i < size)
		{
			pos = data->win_width / 2 - size / 2 + i; 
			set_image_pixel_color(data, buffer, pos + y * data->win_width, col);
			i++;
		}
		y += dist;
	}
	y = 0;
	while (y < data->win_width)
	{
		i = 0;
		while (i < size)
		{
			pos = data->win_width * (data->win_height / 2 - dist / 2 + i);
			set_image_pixel_color(data, buffer, pos + y, col);
			i++;
		}
		y += dist;
	}

}

void	create_vignette(t_data *data, char *buffer, t_color col)
{
	int dist_fromcenter[2];
	int xd;
	int yd;
	int x;
	int y;

	x = 0;
	y = 0;

	xd = fabs((double)(data->win_width / 2  - x));
	yd = fabs((double)(data->win_height / 2 - y));
	dist_fromcenter[0] = sqrt(xd * xd + yd * yd);;
	while (y < data->win_height)
	{
		x = 0;
		while (x < data->win_width)
		{
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, x, y, DARKGRAY);
			xd = fabs((double)(data->win_width / 2 - x));
			yd = fabs((double)(data->win_height / 2 - y));
			dist_fromcenter[1] = sqrt(xd * xd + yd * yd);
			if ((x % 2 == 0 && y % 2 == 0))
				col.a = 255 * (double)dist_fromcenter[1] / (double)dist_fromcenter[0]; 
			if (col.a > 255)
				col.a = 255;
			set_image_pixel_color(data, buffer, x + y * data->win_width, col);
			x++;
		}
		y++;
	}
}

int				main(void)
{
	t_data data;
	//void *img;
	char *buffer;
	char *buffer2;
	int size_line;
	t_color col;
	t_color col_white;
	t_color black;

	col = color_init(&data, GRAY);
	col_white = color_init(&data, 0);
	black = color_init(&data, 0);
	data = initialize(&data);
	data.image = mlx_new_image(data.mlx_ptr, data.win_width, data.win_height);
	data.background = mlx_new_image(data.mlx_ptr, data.win_width, data.win_height); 
	buffer2 = mlx_get_data_addr(data.background, &data.bits_pix, &size_line, &data.endian);
	//fill_image(&data, 4 * data.win_height * data.win_width, buffer2, col);
	create_vignette(&data, buffer2, col);
	//free(buffer);
	buffer = mlx_get_data_addr(data.image, &data.bits_pix, &size_line, &data.endian);
	col_white.a = 255;
	fill_image(&data, 4 * data.win_height * data.win_width, buffer, col_white);
	col_white = color_init(&data, WHITE);
	draw_coord_grid(&data, buffer, col_white);
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.background, 0, 0);
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.image, 0, 0);
	//mlx_destroy_image(data.mlx_ptr, img);
	mlx_hook(data.mlx_win, 2, 0, &input_manager, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
