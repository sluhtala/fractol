/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_navigate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:32:29 by sluhtala          #+#    #+#             */
/*   Updated: 2020/03/09 19:22:42 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	move_leftright(int key, t_data *data, double amount)
{
	int i;

	i = 0;
	if (key == LEFT_KEY)
	{
		if (data->grid_position.x > 0 && data->opt.grid == 1)
			data->grid_position.x -= amount;
		else if (data->grid_position.x <= 0 || data->opt.grid == 0)
		{
			data->frac_pos.x -= (amount * 4 / data->win_width / data->scale);
			i = 1;
		}
	}
	if (key == RIGHT_KEY)
	{
		if (data->grid_position.x < data->win_width && data->opt.grid == 1)
			data->grid_position.x += amount;
		else if (data->grid_position.x >= data->win_width ||
			data->opt.grid == 0)
		{
			data->frac_pos.x += (amount * 4 / data->win_width / data->scale);
			i = 1;
		}
	}
	return (i);
}

void		move_updown(int key, t_data *data, double amount, int f)
{
	if (key == UP_KEY)
	{
		if (data->grid_position.y > 0 && data->opt.grid == 1)
			data->grid_position.y -= amount;
		else if (data->grid_position.y <= 0 || data->opt.grid == 0)
		{
			data->frac_pos.y -= (amount * 2 / data->win_height / data->scale);
			f = 1;
		}
	}
	if (key == DOWN_KEY)
	{
		if (data->grid_position.y < data->win_height && data->opt.grid == 1)
			data->grid_position.y += amount;
		else if (data->grid_position.y >= data->win_height ||
			data->opt.grid == 0)
		{
			data->frac_pos.y += (amount * 2 / data->win_height / data->scale);
			f = 1;
		}
	}
	if (key == LEFT_KEY || key == RIGHT_KEY)
		f = move_leftright(key, data, amount);
	data->opt.draw_fractal = f;
	renderer(data);
}

static void	mouse_scale(int key, t_data *data)
{
	long double tempx;
	long double tempy;

	tempx = (data->mouse.pos_x * 4 / data->win_width - 2) /
		data->scale;
	tempy = (data->mouse.pos_y * 2 / data->win_height - 1) /
		data->scale;
	if (key == 4 && data->scale > ZOOM * 3)
	{
		data->max_iteration -= 1;
		data->scale *= (1 - ZOOM);
	}
	if (key == 5)
	{
		data->max_iteration += 1;
		data->scale *= (1 + ZOOM);
	}
	data->frac_pos.x += tempx - (data->mouse.pos_x * 4 /
		data->win_width - 2) / data->scale;
	data->frac_pos.y += tempy - (data->mouse.pos_y * 2 /
		data->win_height - 1) / data->scale;
	data->opt.draw_fractal = 1;
}

void		scale(int key, t_data *data)
{
	if (key == 4 || key == 5)
	{
		mouse_scale(key, data);
		return ;
	}
	data->frac_pos.x += (data->grid_position.x * 4 /
		data->win_width - 2) / data->scale;
	data->frac_pos.y += (data->grid_position.y * 2 /
		data->win_height - 1) / data->scale;
	data->grid_position.x = data->win_width / 2;
	data->grid_position.y = data->win_height / 2;
	if (key == 18 && data->scale > ZOOM * 3)
	{
		data->max_iteration -= (1);
		data->scale *= (1 - ZOOM);
	}
	if (key == 19)
	{
		data->max_iteration += (1);
		data->scale *= (1 + ZOOM);
	}
}
