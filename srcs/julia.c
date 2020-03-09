/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:56:09 by sluhtala          #+#    #+#             */
/*   Updated: 2020/03/09 17:14:55 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	draw_julia(t_data *data, char *buf, int x, int y)
{
	static t_vec2	xy;
	long double		xtemp;
	t_fractal		f;

	f.i = 0;
	f.ab = inverse_transform(f.ab, data, x, y);
	f.ab.x += data->frac_pos.x;
	f.ab.y += data->frac_pos.y;
	if (data->opt.screen_lock == 1)
	{
		xy.x = data->mouse.track_x * 1 / data->win_width - 0.5;
		xy.y = data->mouse.track_y * 2 / data->win_height - 1;
	}
	f.angle = 0;
	while (f.ab.x * f.ab.x + f.ab.y * f.ab.y < 4 && f.i++ < data->max_iteration)
	{
		xtemp = f.ab.x * f.ab.x - f.ab.y * f.ab.y + xy.x;
		f.ab.y = 2.0 * f.ab.x * f.ab.y + xy.y;
		f.ab.x = xtemp;
	}
	f.xy = xy;
	f.angle = 45;
	return (set_frac_color(data, f));
}
