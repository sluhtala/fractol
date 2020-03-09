/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:55:53 by sluhtala          #+#    #+#             */
/*   Updated: 2020/03/09 17:16:04 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	draw_mandelbrot(t_data *data, char *buf, int x, int y)
{
	long double	xtemp;
	t_fractal	f;

	f.xy = inverse_transform(f.xy, data, x, y);
	f.xy.x += data->frac_pos.x;
	f.xy.y += data->frac_pos.y;
	f.ab.x = 0;
	f.ab.y = 0;
	f.i = 0;
	f.angle = 0;
	while (f.ab.x <= 2 && f.ab.y <= 2 && f.i++ < data->max_iteration)
	{
		xtemp = f.ab.x * f.ab.x - f.ab.y * f.ab.y + f.xy.x;
		f.ab.y = 2.0 * f.ab.x * f.ab.y + f.xy.y;
		f.ab.x = xtemp;
		f.angle = atan2(f.temp.x - f.ab.x, f.temp.y - f.ab.y) * 180 / M_PI;
		f.temp.x = f.ab.x;
		f.temp.y = f.ab.y;
	}
	return (set_frac_color(data, f));
}
