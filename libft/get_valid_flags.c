/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_valid_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:53:46 by sluhtala          #+#    #+#             */
/*   Updated: 2020/02/06 17:27:20 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	non_num_settings(t_part *list)
{
	if (list->type[0] != 'd' && list->type[0] != 'i' && list->type[0] != 'f')
	{
		list->plus = 0;
		list->space = 0;
	}
}

static void	negative_settings(t_part *list)
{
	if (list->data[0] == '-')
	{
		list->plus = 0;
		list->space = 0;
	}
}

static void	sharp_settings(t_part *list)
{
	char t;

	t = list->type[0];
	if (!is_hex(t))
		list->sharp = 0;
	if (t == 'p')
		return ;
	if (list->preci == -1 && is_hex(t) && ft_atoi(list->data) == 0 &&
		list->hex == 0)
		list->sharp = 0;
	if (t == 'o' && list->sharp && list->preci + list->sharp >= 3)
		list->sharp = 0;
}

void		get_valid_flags(t_part *list)
{
	non_num_settings(list);
	if (list->type[0] == 'p')
		list->sharp = 1;
	sharp_settings(list);
	if (list->type[0] == 'c' || list->type[0] == '%')
		list->preci = -1;
	if (list->plus == '+')
		list->space = 0;
	if (list->minus)
		list->zero = ' ';
	if (list->type[0] != 'f' && list->preci != -1)
		list->zero = ' ';
	negative_settings(list);
}
