/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:14:54 by sluhtala          #+#    #+#             */
/*   Updated: 2020/03/09 19:24:35 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_color	more_frac_colors(t_data *data, t_fractal f, t_color col)
{
	double iter;

	iter = data->max_iteration;
	if (data->opt.palette == 3)
	{
		if (f.i >= iter)
			col = hsv(40, 1, 1, 0);
		else
			col = hsv(210, 1, f.angle / 360, 0);
	}
	if (data->opt.palette == 4)
	{
		if (f.i >= iter)
			col = hsv(0, 1, 0, 0);
		else
			col.a = 255;
	}
	if (data->opt.palette == 5)
	{
		if (f.i >= iter)
			col = hsv(360, 0, 1, 0);
		else
			col.a = 255;
	}
	return (col);
}

t_color			set_frac_color(t_data *data, t_fractal f)
{
	double		iter;
	t_color		col;

	if (data->opt.palette > 5)
		data->opt.palette = 1;
	iter = data->max_iteration;
	if (data->opt.palette == 1)
	{
		if (f.i >= iter)
			col = hsv(200, 0.5, 1, 0);
		else
			col = hsv(200, 1, f.i / iter, 0);
	}
	if (data->opt.palette == 2)
	{
		if (f.i >= iter)
			col = hsv(230, 0, 1, 0);
		else
			col = hsv(360 - 360 * f.i / iter, 0.8, 1, 0);
	}
	return (more_frac_colors(data, f, col));
}

t_color			color_init(t_data *data, int hex)
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
