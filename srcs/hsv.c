/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsv.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 17:46:21 by sluhtala          #+#    #+#             */
/*   Updated: 2020/03/09 17:46:23 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_color	more_cases(double h, double s, double v, int i)
{
	t_color col;

	if (i == 3)
	{
		col.r = v * (1.0 - s);
		col.g = v * (1.0 - (s * (h - i)));
		col.b = v;
	}
	else if (i == 4)
	{
		col.r = v * (1.0 - (s * (1.0 - (h - i))));
		col.g = v * (1.0 - s);
		col.b = v;
	}
	else
	{
		col.r = v;
		col.g = v * (1.0 - s);
		col.b = v * (1.0 - (s * (h - i)));
	}
	return (col);
}

static t_color	cases(double h, double s, double v, int i)
{
	t_color col;

	if (i == 0)
	{
		col.r = v;
		col.g = v * (1.0 - (s * (1.0 - (h - i))));
		col.b = v * (1.0 - s);
	}
	else if (i == 1)
	{
		col.r = v * (1.0 - (s * (h - i)));
		col.g = v;
		col.b = v * (1.0 - s);
	}
	else if (i == 2)
	{
		col.r = v * (1.0 - s);
		col.g = v;
		col.b = v * (1.0 - (s * (1.0 - (h - i))));
	}
	else
		col = more_cases(h, s, v, i);
	return (col);
}

t_color			hsv(double hue, double saturation, double value, double alpha)
{
	t_color	col;
	int		i;

	col.a = alpha * 255;
	if (saturation == 0)
	{
		col.r = value;
		col.g = value;
		col.b = value;
	}
	else
	{
		if (hue == 360)
			hue = 0;
		else
			hue /= 60;
		i = (int)trunc(hue);
		col = cases(hue, saturation, value, i);
	}
	col.r *= 255;
	col.g *= 255;
	col.b *= 255;
	return (col);
}
