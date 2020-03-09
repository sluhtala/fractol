/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:39:38 by sluhtala          #+#    #+#             */
/*   Updated: 2020/03/09 17:07:58 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		write_frac_names(t_data *data)
{
	int xpos;
	int ypos;

	xpos = 5;
	ypos = data->win_height - 20;
	mlx_string_put(data->mlx_ptr, data->mlx_win, xpos, ypos, WHITE,
		"Mandelbrot");
	xpos += data->win_width / 3;
	mlx_string_put(data->mlx_ptr, data->mlx_win, xpos, ypos, WHITE,
		"Julia");
	xpos += data->win_width / 3;
	mlx_string_put(data->mlx_ptr, data->mlx_win, xpos, ypos, WHITE,
		"Burning Ship");
}

static void		reset_options(t_data *data)
{
	data->opt.screen_lock = 1;
	data->mouse.track_x = 0;
	data->mouse.track_y = data->win_height / 4;
	data->frac_pos.x = 0;
	data->frac_pos.y = 0;
	data->scale = 1;
	data->opt.palette = 1;
	data->max_iteration = 60;
}

static void		select_screen(t_data *data)
{
	int xpos;

	xpos = 0;
	reset_options(data);
	while (xpos < data->win_width - 1)
	{
		data->frac_pos.x = (xpos) * 4 / data->win_width;
		data->frac_num++;
		draw_fractal(data);
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->background, xpos, 0);
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->fractal, xpos, 0);
		xpos += data->win_width / 3;
	}
	write_frac_names(data);
	data->frac_num = 0;
	data->opt.screen_lock = 0;
	data->frac_pos.x = 0;
}

static void		help_screen(t_data *data)
{
	int y;
	int a;

	y = 20;
	a = 25;
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->background, 0, 0);
	mlx_string_put(data->mlx_ptr, data->mlx_win, 20, y, WHITE,
		"Zoom:    Mouse Scroll, 1 and 2");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 20, y += a, WHITE,
		"Change iteration:    . and ,");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 20, y += a, WHITE,
		"Switch colors:    Space");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 20, y += a, WHITE,
		"Lock julia shape:   Mouse Left Click");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 20, y += a, WHITE,
		"Reset fractal:    C");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 20, y += a, WHITE,
		"All fractals:    Q");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 20, y += a, WHITE,
		"Toggle grid-mode:    G");
	mlx_string_put(data->mlx_ptr, data->mlx_win, 20, y += a, WHITE,
		"Quit:    esc");
}

void			renderer(t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	if (data->frac_num == 0)
	{
		select_screen(data);
		return ;
	}
	if (data->opt.help)
	{
		help_screen(data);
		return ;
	}
	if (data->opt.draw_fractal)
		draw_fractal(data);
	draw_coord_grid(data, data->grid_buf);
	if (data->opt.bg)
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->background, 0, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->fractal, 0, 0);
	if (data->opt.grid)
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->image, 0, 0);
}
