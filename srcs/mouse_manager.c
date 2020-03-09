/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:44:08 by sluhtala          #+#    #+#             */
/*   Updated: 2020/03/09 19:30:09 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mouse_track(int x, int y, t_data *data)
{
	long double xfrac;
	long double yfrac;

	data->mouse.track_x = (long double)x;
	data->mouse.track_y = (long double)y;
	if (data->opt.screen_lock == 1)
	{
		data->opt.draw_fractal = 1;
		renderer(data);
	}
	if (data->mouse.down == 1)
	{
		xfrac = (long double)x - data->mouse.xfrac;
		yfrac = (long double)y - data->mouse.yfrac;
		data->frac_pos.x += -(xfrac * 4 / data->win_width) / data->scale;
		data->frac_pos.y += -(yfrac * 2 / data->win_height) / data->scale;
		data->opt.draw_fractal = 1;
		renderer(data);
		data->mouse.xfrac = (long double)x;
		data->mouse.yfrac = (long double)y;
	}
	return (0);
}

static int	mouse_helper(int button, t_data *data)
{
	if (button == 4 || button == 5)
	{
		scale(button, data);
		renderer(data);
	}
	if (button == 1)
	{
		data->mouse.xfrac = data->mouse.track_x;
		data->mouse.yfrac = data->mouse.track_y;
		data->mouse.down = 1;
		data->opt.screen_lock = 0;
	}
	return (0);
}

int			mouse_manager(int button, int x, int y, t_data *data)
{
	data->mouse.pos_x = x;
	data->mouse.pos_y = y;
	if (data->frac_num == 0)
	{
		if (button == 1 && y > 0)
			data->frac_num = (3 * x / (data->win_width)) + 1;
		else
			return (0);
		if (data->frac_num == 2)
			data->opt.screen_lock = 1;
		data->opt.draw_fractal = 1;
		renderer(data);
		return (0);
	}
	if (button == 4 || button == 5 || button == 1)
	{
		mouse_helper(button, data);
	}
	return (0);
}

int			mouse_release(int button, int x, int y, t_data *data)
{
	x = 0;
	y = 0;
	if (button == 1)
		data->mouse.down = 0;
	return (0);
}
