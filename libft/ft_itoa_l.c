/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:26:24 by sluhtala          #+#    #+#             */
/*   Updated: 2020/02/06 14:55:35 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_intlen_ll(long long int num)
{
	int result;

	if (num <= (long long int)-9223372036854775807)
		return (20);
	result = 1;
	if (num < 0)
	{
		result++;
		num *= -1;
	}
	while (num >= 10)
	{
		result++;
		num /= 10;
	}
	return (result);
}

char		*ft_itoa_ll(long long int n)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	if (n < (long long int)-9223372036854775807)
		return (str = ft_strdup("-9223372036854775808"));
	len = ft_intlen_ll(n);
	if ((str = (char*)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	str[len] = '\0';
	len--;
	if (n < 0)
	{
		str[0] = '-';
		i++;
		n = n * -1;
	}
	while (i < len + 1)
	{
		str[len] = n % 10 + '0';
		n = (n - n % 10) / 10;
		len--;
	}
	return (str);
}

static int	ft_intlen_l(long int num)
{
	int result;

	if (num == -2147483648)
		return (11);
	result = 1;
	if (num < 0)
	{
		result++;
		num *= -1;
	}
	while (num >= 10)
	{
		result++;
		num /= 10;
	}
	return (result);
}

char		*ft_itoa_l(long int n)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	if (n < -9223372036854775807)
		return (str = ft_strdup("-9223372036854775808"));
	len = ft_intlen_l(n);
	if ((str = (char*)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	str[len] = '\0';
	len--;
	if (n < 0)
	{
		str[0] = '-';
		i++;
		n = n * -1;
	}
	while (i < len + 1)
	{
		str[len] = n % 10 + '0';
		n = (n - n % 10) / 10;
		len--;
	}
	return (str);
}
