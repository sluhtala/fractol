/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:25:56 by sluhtala          #+#    #+#             */
/*   Updated: 2020/03/09 14:31:24 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** These functions creates the linked list and the data in them;
** There are two kinds of nodes: normal text and formatspecifier -nodes.
*/

static void		get_type(t_part *new, char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	i--;
	new->type[0] = str[i];
	i--;
	if (str[i] == 'l' || str[i] == 'L' || str[i] == 'h')
		new->type[1] = str[i];
	i--;
	if (str[i] == 'l' || str[i] == 'h')
		new->type[2] = str[i];
}

static int		get_flags(t_part *new)
{
	char	*str;

	str = new->str;
	while (*str && *str != '.' && (*str > '9' || *str < '1'))
	{
		if (*str == '+')
			new->plus = '+';
		if (*str == '-')
			new->minus = 1;
		if (*str == '0')
			new->zero = '0';
		if (*str == ' ')
			new->space = ' ';
		if (*str == '#')
			new->sharp = 1;
		str++;
	}
	get_type(new, new->str);
	if (*str != '.')
		new->width = ft_atoi(str);
	while (*str && *str != '.')
		str++;
	if (*str)
		new->preci = ft_atoi(str + 1);
	return (0);
}

static char		*get_str(char *format, int *i)
{
	int		start;

	start = *i;
	if (format[0] == '\0')
		return (ft_strnew(1));
	if (format[*i] == '%')
	{
		*i = *i + 1;
		while (format[*i] && is_fspecif(format[*i]) == 0)
			*i = *i + 1;
		if (is_valid_format(format + start, *i - start + 1) == 0)
			return (ft_strsub(format, start + 1, *i - start));
		*i = *i + 1;
		return (ft_strsub(format, start, *i - start));
	}
	while (format[*i] && format[*i] != '%')
		*i = *i + 1;
	return (ft_strsub(format, start, *i - start));
}

static t_part	*new_part(char *format, int *i)
{
	t_part *new;

	if (!(new = (t_part*)malloc(sizeof(t_part))))
		error_manager("Error.");
	initialize_pf(new);
	if (!(new->str = get_str(format, i)))
		error_manager("Error.");
	if (new->str[0] != '%')
	{
		if (!(new->data = ft_strdup(new->str)))
			error_manager("Error.");
		new->datalen = ft_strlen(new->data);
	}
	else
	{
		if (get_flags(new) == -1)
			error_manager("Error.");
	}
	return (new);
}

t_part			*create_list(char *format)
{
	t_part	*begin;
	t_part	*part;
	t_part	*temp;
	int		i;

	i = 0;
	part = new_part(format, &i);
	begin = part;
	while (format[i])
	{
		temp = part;
		part = new_part(format, &i);
		temp->next = part;
	}
	if (!begin)
		error_manager("Error.");
	return (begin);
}
