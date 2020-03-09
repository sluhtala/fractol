/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:26:37 by sluhtala          #+#    #+#             */
/*   Updated: 2020/02/06 16:44:26 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

static void	get_valid_type(t_part *list)
{
	char c;

	c = list->type[1];
	if (list->type[0] == 'f')
	{
		if (list->type[1] != 'l' && list->type[1] != 'L')
			list->type[1] = 0;
		if (list->type[2] != 'l' && list->type[2] != 'L')
			list->type[2] = 0;
		return ;
	}
	if (list->type[1] != 'l' && list->type[1] != 'h')
		list->type[1] = 0;
	if (list->type[2] != 'l' && list->type[2] != 'h')
		list->type[2] = 0;
	if (list->type[2] != c)
		list->type[2] = 0;
}

static char	*save_char(va_list ar, char type, t_part *new)
{
	char *data;

	data = ft_strnew(2);
	if (type == '%')
		data[0] = '%';
	else
		data[0] = va_arg(ar, int);
	new->datalen = 1;
	return (data);
}

void		get_data(t_part *new, va_list ar)
{
	char t;
	char *str;

	t = new->type[0];
	get_valid_type(new);
	if (t == 'c' || t == '%')
		new->data = save_char(ar, t, new);
	if (t == 's')
	{
		str = va_arg(ar, char *);
		if (str == NULL)
			new->data = ft_strdup("(null)");
		else
			new->data = ft_strdup(str);
	}
	if (t == 'd' || t == 'i' || t == 'u')
		new->data = number_manager(new, ar);
	if (t == 'f')
		new->data = float_manager(new, ar);
	if (t == 'x' || t == 'X' || t == 'o' || t == 'p')
		new->data = hex_manager(new, ar);
	if (new->data == NULL)
		error_manager("Data error.");
	if (t != 'c' && t != '%')
		new->datalen = ft_strlen(new->data);
}
