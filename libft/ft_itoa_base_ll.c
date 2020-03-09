/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ll.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:25:05 by sluhtala          #+#    #+#             */
/*   Updated: 2020/02/05 17:21:04 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_intblen(long long num, int base)
{
	int result;

	result = 1;
	if (num == -2147483648)
		return (10);
	if (num < 0)
		num = num * -1;
	if (num < base)
		return (1);
	while (num >= base)
	{
		num /= base;
		result++;
	}
	return (result);
}

static int		ft_uintblen(unsigned long long num, int base)
{
	int result;

	result = 1;
	if (num < (unsigned int)base)
		return (1);
	while (num >= (unsigned int)base)
	{
		num /= base;
		result++;
	}
	return (result);
}

static char		*baseten_negative(long long value, int len)
{
	int		i;
	char	*result;

	len++;
	i = 1;
	result = ft_strnew(sizeof(char) * len + 1);
	result[len] = '\0';
	result[0] = '-';
	value = value * -1;
	while (len > i)
	{
		len--;
		result[len] = value % 10 + '0';
		if (value >= 10)
			value = value / 10;
	}
	return (result);
}

char			*ft_itoa_base_ll(long long value, int base, int isuns)
{
	int					len;
	char				*result;
	unsigned long long	uvalue;

	len = ft_intblen((long long)value, base);
	if (value < 0 && base == 10 && isuns == 0)
		return (baseten_negative(value, len));
	len = ft_uintblen((unsigned long long)value, base);
	uvalue = (unsigned long long)value;
	result = ft_strnew(sizeof(char) * len + 1);
	result[len] = '\0';
	while (len > 0)
	{
		len--;
		result[len] = uvalue % base + '0';
		if (base > 9 && uvalue % base > 9)
			result[len] = result[len] - '0' + 'A' - 10;
		if (uvalue >= (unsigned int)base)
			uvalue = uvalue / base;
	}
	return (result);
}
