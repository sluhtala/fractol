/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:56:00 by sluhtala          #+#    #+#             */
/*   Updated: 2020/03/09 18:06:55 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static long double	ldabs(long double num)
{
	if (num < 0)
		return (num * -1);
	else
		return (num);
}

t_color				draw_burning_ship(t_data *data, char *buf, int x, int y)
{
	long double xtemp;
	t_fractal	f;

	f.xy = inverse_transform(f.xy, data, x, y);
	f.xy.x += data->frac_pos.x;
	f.xy.y += data->frac_pos.y;
	f.ab.x = f.xy.x;
	f.ab.y = f.xy.y;
	f.i = 0;
	f.angle = 0;
	while (f.ab.x * f.ab.x + f.ab.y * f.ab.y < 4 && f.i++ < data->max_iteration)
	{
		xtemp = f.ab.x * f.ab.x - f.ab.y * f.ab.y + f.xy.x;
		f.ab.y = ldabs((2.0 * f.ab.x * f.ab.y + f.xy.y));
		f.ab.x = ldabs(xtemp);
		f.angle = atan2(f.temp.x - f.ab.x, f.temp.y - f.ab.y) * 180 / M_PI;
		f.temp.x = f.ab.x;
		f.temp.y = f.ab.y;
	}
	return (set_frac_color(data, f));
}
