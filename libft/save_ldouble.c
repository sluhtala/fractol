/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_ldouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:53:32 by sluhtala          #+#    #+#             */
/*   Updated: 2020/02/14 15:24:24 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long long int	ft_pow_ll(unsigned long long int num, int e)
{
	unsigned long long int result;

	result = num;
	if (e == 0)
		return (1);
	while (e > 1)
	{
		e--;
		result = result * num;
	}
	return (result);
}

static int						checkround(long long int a,
		unsigned long long int *b, int preci, long double temp)
{
	int n;

	n = temp < 0;
	if (preci == 0 && *b >= 5)
	{
		if (a % 2 == 0)
			return (0);
		else
			return (1);
	}
	if (preci == 0 && (int)*b >= 5 + n)
		return (1);
	if (*b % 10 >= 5)
	{
		*b /= 10;
		*b += 1;
		if (*b >= ft_pow_ll(10, preci))
		{
			*b = 0;
			return (1);
		}
	}
	else
		*b /= 10;
	return (0);
}

static char						*create_data(long long int a,
		unsigned long long int b, int preci, int n)
{
	char	*bdata;
	char	*data;
	char	*temp;
	int		len;

	len = ft_intlen_ll(b);
	bdata = ft_strnew(preci + 1);
	bdata = ft_memset(bdata, '0', preci);
	temp = ft_itoa_base_ll(b, 10, 1);
	ft_memcpy(bdata + preci - len, temp, len);
	free(temp);
	len = ft_intlen_ll(a);
	data = ft_strnew(len + n + 1 + 1);
	temp = ft_itoa_base_ll(a, 10, 0);
	data[0] = '-';
	data[len + n] = '.';
	ft_memcpy(data + n, temp, len);
	free(temp);
	temp = ft_strjoin(data, bdata);
	free(data);
	free(bdata);
	return (temp);
}

static unsigned long long int	get_b(long double d, int preci)
{
	long long int	b;
	long long int	temp;
	int				div;

	b = (long long int)d;
	if (b < 0)
		b *= -1;
	if (preci == 0 && b > 500000000000000)
	{
		b = 6;
		return (b);
	}
	div = 14 - preci;
	temp = b;
	while (div > 0)
	{
		div--;
		b /= 10;
	}
	if (temp + 1 >= (long long int)1000000000000000)
		b++;
	return (b);
}

char							*save_ldouble(long double d, int precision)
{
	long long int			a;
	unsigned long long int	b;
	char					*data;
	long double				temp;

	if ((temp = d) < 0)
		d *= -1;
	a = (long long int)d;
	d = d - a;
	if (precision >= 15)
		d = d * ft_pow_ll(10, precision + 1);
	else
		d = d * ft_pow_ll(10, 15);
	b = get_b(d, precision);
	a += checkround(a, &b, precision, temp);
	if (precision == 0)
	{
		if (temp < 0)
			data = ft_itoa_ll(a * -1);
		else
			data = ft_itoa_ll(a);
	}
	data = create_data(a, b, precision, (temp < 0));
	return (data);
}
