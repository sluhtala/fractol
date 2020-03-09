/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:59:21 by sluhtala          #+#    #+#             */
/*   Updated: 2020/03/09 18:05:59 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_color	vignette_loop(t_color col,
		t_data *data, double dist[2], int xy[2])
{
	double	dark;
	t_color	tcol;
	t_color	color;
	t_vec2	delta;

	color = col;
	tcol = color;
	dark = 1.8;
	delta.x = fabs((double)(data->win_width / 2 - xy[0]));
	delta.y = fabs((double)(data->win_height / 2 - xy[1]));
	dist[1] = sqrt(delta.x * delta.x + delta.y * delta.y) / 2.5;
	color.b = tcol.b - tcol.b * dist[1] / dist[0] * dark;
	color.r = tcol.r - tcol.r * dist[1] / dist[0] * dark;
	color.g = tcol.g - tcol.g * dist[1] / dist[0] * dark;
	return (color);
}

static void		create_vignette(t_data *data, char *buffer, t_color col)
{
	double		dist[2];
	t_vec2		delta;
	int			xy[2];
	t_color		tcol;

	tcol = col;
	xy[0] = 0;
	xy[1] = 0;
	delta.x = fabs((double)(data->win_width / 2 - xy[0]));
	delta.y = fabs((double)(data->win_height / 2 - xy[1]));
	dist[0] = sqrt(delta.x * delta.x + delta.y * delta.y);
	while (xy[1] < data->win_height)
	{
		xy[0] = 0;
		while (xy[0] < data->win_width)
		{
			col = tcol;
			col = vignette_loop(col, data, dist, xy);
			set_image_pixel_color(data, buffer,
					xy[0] + xy[1] * data->win_width, col);
			xy[0]++;
		}
		xy[1]++;
	}
}

void			create_background(t_data *data)
{
	t_color col;
	char	*buffer;

	col = hsv(200, 1, 1, 0);
	data->background = mlx_new_image(data->mlx_ptr, data->win_width,
		data->win_height);
	buffer = mlx_get_data_addr(data->background, &data->bits_pix,
		&data->size_line, &data->endian);
	fill_image(data, 4 * data->win_height * data->win_width, buffer, col);
	create_vignette(data, buffer, col);
}
