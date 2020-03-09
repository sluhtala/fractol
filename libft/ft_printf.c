/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:28:09 by sluhtala          #+#    #+#             */
/*   Updated: 2020/02/07 14:23:44 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

static int		print_list(t_part *begin)
{
	int		result;
	t_part	*temp;

	temp = begin;
	result = 0;
	while (temp)
	{
		if (!temp->data)
			error_manager("Data error.");
		result = result + temp->datalen;
		write(1, temp->data, temp->datalen);
		temp = temp->next;
	}
	return (result);
}

static t_part	*data_loop(t_part *list, va_list ar)
{
	t_part *temp;

	temp = list;
	while (temp)
	{
		if (temp->str[0] == '%')
		{
			get_data(temp, ar);
			if (list->data == NULL)
				error_manager("Data error.");
		}
		temp = temp->next;
	}
	return (list);
}

int				ft_printf(const char *format, ...)
{
	int			result;
	t_part		*begin;
	va_list		ar;
	char		*temp;

	temp = ft_strdup(format);
	result = 0;
	va_start(ar, format);
	begin = create_list(temp);
	begin = data_loop(begin, ar);
	begin = apply_flags(begin);
	result = print_list(begin);
	free_list(&begin);
	free(temp);
	va_end(ar);
	begin = NULL;
	return (result);
}
