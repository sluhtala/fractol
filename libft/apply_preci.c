/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_preci.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 12:27:40 by sluhtala          #+#    #+#             */
/*   Updated: 2020/02/06 19:10:54 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_s(t_part *list)
{
	char *temp;

	if (list->preci >= list->datalen)
		return (0);
	temp = ft_strnew(list->preci + 1);
	if (list->preci > 0)
		ft_memcpy(temp, list->data, list->preci);
	free(list->data);
	list->data = temp;
	list->datalen = list->preci;
	if (!temp)
		return (-1);
	return (1);
}

static int	o_case(t_part *list)
{
	free(list->data);
	list->data = ft_strdup("0");
	list->sharp = 0;
	list->datalen = 1;
	if (list->data == NULL)
		return (-1);
	return (1);
}

static int	put_zeros(t_part *list)
{
	char	*temp;
	int		n;

	n = (list->data[0] == '-');
	if (!(temp = ft_strnew(list->preci + 1 + n)))
		return (-1);
	ft_memset(temp, '0', list->preci + n);
	ft_memcpy(temp + list->preci - list->datalen + n,
		list->data, list->datalen);
	if (list->data[0] == '-')
	{
		temp[0] = '-';
		temp[list->preci - list->datalen + n] = '0';
	}
	free(list->data);
	list->data = temp;
	list->datalen = list->preci + n;
	return (1);
}

static int	handle_nums(t_part *list)
{
	int		preci;
	int		n;

	n = (list->data[0] == '-');
	preci = list->preci;
	if (list->type[0] != 'o' && preci + n <= list->datalen && preci > 0)
		return (0);
	if (list->type[0] == 'o' && ft_atoi(list->data) == 0 && list->sharp)
		return (o_case(list));
	if (ft_atoi(list->data) == 0 && list->hex == 0 && preci < list->datalen + n)
	{
		free(list->data);
		if (!(list->data = ft_strnew(1)))
			return (-1);
		list->datalen = 0;
		if (list->type[0] != 'p')
			list->sharp = 0;
		return (1);
	}
	if (list->preci + n > list->datalen)
		return (put_zeros(list));
	return (0);
}

int			apply_preci(t_part *list)
{
	int preci;

	preci = list->preci;
	if (preci == -1)
		return (0);
	if (list->type[0] == 's')
		return (handle_s(list));
	if (list->type[0] == 'd' || list->type[0] == 'u' ||
		list->type[0] == 'i' || is_hex(list->type[0]))
		return (handle_nums(list));
	return (0);
}
