/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:25:36 by sluhtala          #+#    #+#             */
/*   Updated: 2020/03/09 14:30:25 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize_pf(t_part *new)
{
	new->data = NULL;
	new->str = NULL;
	new->next = NULL;
	new->datalen = 0;
	new->type[0] = 0;
	new->type[1] = 0;
	new->type[2] = 0;
	new->zero = ' ';
	new->plus = 0;
	new->minus = 0;
	new->space = 0;
	new->sharp = 0;
	new->width = 0;
	new->preci = -1;
	new->hex = 0;
}
