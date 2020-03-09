/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:07:25 by sluhtala          #+#    #+#             */
/*   Updated: 2020/02/06 19:10:23 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*handle_signs(t_part *list, char *data, char *s_addr)
{
	char *type;

	type = list->type;
	if (list->sharp == 1)
	{
		s_addr[0] = '0';
		if (type[0] == 'x' || type[0] == 'p')
			s_addr[1] = 'x';
		if (type[0] == 'X')
			s_addr[1] = 'X';
	}
	if (list->plus == '+')
		s_addr[0] = '+';
	if (list->space == ' ')
		s_addr[0] = ' ';
	if (list->data[0] == '-')
		s_addr[0] = '-';
	return (data);
}

static char	*get_new_data(t_part *list, char *new_data, int len)
{
	char	*data_addr;
	char	*sign_addr;
	char	t;
	int		n;
	int		p;

	t = list->type[0];
	n = (list->data[0] == '-');
	p = (list->plus == '+') || list->space ||
		(list->type[0] == 'o' && list->sharp);
	data_addr = new_data + n + p;
	if (list->minus == 0)
		data_addr = data_addr + len - list->datalen - p;
	sign_addr = data_addr - n - p;
	if (list->zero == '0')
		sign_addr = new_data;
	if (list->minus == 0 && list->zero != '0' && (t == 'x' ||
		t == 'X' || t == 'p'))
		sign_addr -= 2;
	if (list->minus == 1 && list->sharp && (t == 'x' || t == 'X' || t == 'p'))
		data_addr += 2;
	new_data = ft_memset(new_data, list->zero, len);
	new_data = handle_signs(list, new_data, sign_addr);
	ft_memcpy(data_addr, list->data + n, list->datalen - n);
	return (new_data);
}

static char	*new_format(t_part *list)
{
	char	*new_data;
	char	*typ;
	int		len;

	typ = list->type;
	if (apply_preci(list) == -1)
		return (NULL);
	len = list->datalen;
	if (list->sharp != 0 && (typ[0] == 'x' || typ[0] == 'X' ||
		typ[0] == 'p'))
		len = len + 2;
	if ((list->sharp != 0 && list->type[0] == 'o') || list->plus || list->space)
		len = len + 1;
	if (len < list->width)
		len = list->width;
	if (!(new_data = ft_strnew(len + 1)))
		return (NULL);
	new_data = get_new_data(list, new_data, len);
	free(list->data);
	list->datalen = len;
	return (new_data);
}

t_part		*apply_flags(t_part *begin)
{
	t_part *temp;

	temp = begin;
	while (temp)
	{
		if (temp->str[0] == '%')
		{
			get_valid_flags(temp);
			temp->data = new_format(temp);
			if (temp->data == NULL)
				error_manager("Error.");
		}
		temp = temp->next;
	}
	return (begin);
}
