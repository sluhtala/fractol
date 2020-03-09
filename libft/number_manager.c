/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:28:28 by sluhtala          #+#    #+#             */
/*   Updated: 2020/02/06 17:21:13 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

/*
** d and i are the same, just int. U is unsigned int.
** Both cases they have l, ll, h and hh flags possible.
** Va_arg promotes anything that is less than int to int.
*/

char	*number_manager(t_part *new, va_list ar)
{
	if ((new->type[0] == 'd' || new->type[0] == 'i') && new->type[1] == 0)
		return (ft_itoa(va_arg(ar, int)));
	if (new->type[0] == 'u' && new->type[1] == 0)
		return (ft_itoa_u(va_arg(ar, unsigned int)));
	if (new->type[0] == 'd' || new->type[0] == 'i')
	{
		if (new->type[1] == 'l' && new->type[2] == 0)
			return (ft_itoa_l(va_arg(ar, long int)));
		if (new->type[1] == 'l' && new->type[2] == 'l')
			return (ft_itoa_ll(va_arg(ar, long long int)));
		if (new->type[1] == 'h' && new->type[2] == 0)
			return (ft_itoa((short int)va_arg(ar, int)));
		if (new->type[1] == 'h' && new->type[2] == 'h')
			return (ft_itoa((char)va_arg(ar, int)));
	}
	if (new->type[1] == 'l' && new->type[2] == 0)
		return (ft_itoa_ul(va_arg(ar, unsigned long int)));
	if (new->type[1] == 'l' && new->type[2] == 'l')
		return (ft_itoa_ull(va_arg(ar, unsigned long long int)));
	if (new->type[1] == 'h' && new->type[2] == 0)
		return (ft_itoa_u((unsigned short int)va_arg(ar, int)));
	return (ft_itoa_u((unsigned char)va_arg(ar, int)));
}
