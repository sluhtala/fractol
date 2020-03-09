/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:28:21 by sluhtala          #+#    #+#             */
/*   Updated: 2020/02/06 19:05:55 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

static char	*pointer_type(t_part *new, long long int hex)
{
	char	*data;
	int		len;

	data = ft_itoa_base_ll((long int)hex, 16, 1);
	len = ft_strlen(data);
	new->sharp = 1;
	while (len > 0)
	{
		len--;
		data[len] = ft_tolower(data[len]);
	}
	return (data);
}

static char	*oct_type(t_part *new, long long int hex)
{
	if (new->type[1] == 0)
		return (ft_itoa_base((int)hex, 8, 1));
	if (new->type[1] == 'l' && new->type[2] == 0)
		return (ft_itoa_base_ll((long int)hex, 8, 1));
	if (new->type[1] == 'l' && new->type[2] == 'l')
		return (ft_itoa_base_ll((long long int)hex, 8, 1));
	if (new->type[1] == 'h' && new->type[2] == 0)
		return (ft_itoa_base((unsigned short int)hex, 8, 1));
	if (new->type[1] == 'h' && new->type[2] == 'h')
		return (ft_itoa_base((unsigned char)hex, 8, 1));
	return (NULL);
}

static char	*hex_type(t_part *new, long long int hex)
{
	char	*data;
	int		len;

	if (new->type[1] == 0)
		data = ft_itoa_base((int)hex, 16, 1);
	if (new->type[1] == 'l' && new->type[2] == 0)
		data = ft_itoa_base_ll((long int)hex, 16, 1);
	if (new->type[1] == 'l' && new->type[2] == 'l')
		data = ft_itoa_base_ll((long long int)hex, 16, 1);
	if (new->type[1] == 'h' && new->type[2] == 0)
		data = ft_itoa_base((unsigned short int)hex, 16, 1);
	if (new->type[1] == 'h' && new->type[2] == 'h')
		data = ft_itoa_base((unsigned char)hex, 16, 1);
	len = ft_strlen(data);
	while (new->type[0] == 'x' && len > 0)
	{
		len--;
		data[len] = ft_tolower(data[len]);
	}
	return (data);
}

char		*hex_manager(t_part *new, va_list ar)
{
	new->hex = va_arg(ar, long long int);
	if (new->type[0] == 'x' || new->type[0] == 'X')
		return (hex_type(new, new->hex));
	if (new->type[0] == 'o')
		return (oct_type(new, new->hex));
	if (new->type[0] == 'p')
		return (pointer_type(new, new->hex));
	return (NULL);
}
