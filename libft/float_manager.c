/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:24:49 by sluhtala          #+#    #+#             */
/*   Updated: 2020/02/14 15:18:26 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

static char	*get_ldouble(va_list ar, int preci)
{
	long double	d;
	char		*data;
	char		*temp;

	d = va_arg(ar, long double);
	data = save_float(d, preci);
	if (d < 0 && data[0] == '0')
	{
		temp = ft_strjoin("-", data);
		free(data);
		data = temp;
	}
	return (data);
}

static char	*get_float(va_list ar, int preci)
{
	double	f;
	char	*data;
	char	*temp;

	f = va_arg(ar, double);
	data = save_float(f, preci);
	if (f < 0 && data[0] == '0')
	{
		temp = ft_strjoin("-", data);
		free(data);
		data = temp;
	}
	return (data);
}

char		*float_manager(t_part *new, va_list ar)
{
	char *data;
	char *temp;

	if (new->preci == -1)
		new->preci = 6;
	if (new->type[1] == 0 || new->type[1] == 'l')
		data = get_float(ar, new->preci);
	if (new->type[1] == 'L')
		data = get_ldouble(ar, new->preci);
	if (new->preci == 0 && new->sharp == 1)
	{
		temp = ft_strjoin(data, ".");
		free(data);
		data = temp;
	}
	new->preci = -1;
	return (data);
}
