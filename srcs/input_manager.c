/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:55:38 by sluhtala          #+#    #+#             */
/*   Updated: 2020/03/09 17:10:33 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				close_program(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	ft_putstr("Good bye.\n");
	exit(0);
	return (0);
}

static void		input_action_manager(int key, t_data *data)
{
	if (key == UP_KEY || key == DOWN_KEY ||
	key == RIGHT_KEY || key == LEFT_KEY)
		move_updown(key, data, 20, 0);
	if (key == 8)
	{
		data->max_iteration = 60;
		data->grid_position.x = data->win_width / 2;
		data->grid_position.y = data->win_height / 2;
		data->frac_pos.x = data->grid_position.x * 4 / data->win_width - 2;
		data->frac_pos.y = data->grid_position.y * 2 / data->win_height - 1;
		data->scale = 1;
		if (data->frac_num == 2)
			data->opt.screen_lock = 1;
	}
	if (key == 5)
	{
		if (data->opt.grid == 0)
			data->opt.grid = 1;
		else
			data->opt.grid = 0;
		data->grid_position.x = data->win_width / 2;
		data->grid_position.y = data->win_height / 2;
	}
}

static void		input_helper(int key, t_data *data)
{
	if (key == 18 || key == 19)
	{
		scale(key, data);
	}
	if (key == 43 && data->max_iteration - 20 > 0)
		data->max_iteration -= ITER;
	if (key == 47)
		data->max_iteration += ITER;
	if (key == 8 || key == 5)
		input_action_manager(key, data);
	if (key == SPACE_KEY)
		data->opt.palette++;
	data->opt.draw_fractal = 1;
	renderer(data);
}

int				input_manager(int key, t_data *data)
{
	if (key == ESC_KEY)
		close_program(data);
	if (key == 12)
	{
		data->frac_num = 0;
		renderer(data);
		return (0);
	}
	if (key == 4)
	{
		if (data->opt.help == 0)
			data->opt.help = 1;
		else
			data->opt.help = 0;
		renderer(data);
	}
	if (data->frac_num == 0)
		return (0);
	if (key == UP_KEY || key == DOWN_KEY ||
	key == RIGHT_KEY || key == LEFT_KEY)
		input_action_manager(key, data);
	if (key == 5 || key == 8 || key == 18 || key == 19
			|| key == 43 || key == 47 || key == SPACE_KEY)
		input_helper(key, data);
	return (key);
}
