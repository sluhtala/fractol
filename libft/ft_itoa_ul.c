/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:25:16 by sluhtala          #+#    #+#             */
/*   Updated: 2020/02/05 17:20:31 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlen_ull(unsigned long long int num)
{
	int result;

	result = 1;
	while (num >= 10)
	{
		result++;
		num /= 10;
	}
	return (result);
}

char		*ft_itoa_ull(unsigned long long int n)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = ft_intlen_ull(n);
	if ((str = (char*)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	str[len] = '\0';
	len--;
	while (i < len + 1)
	{
		str[len] = n % 10 + '0';
		n = (n - n % 10) / 10;
		len--;
	}
	return (str);
}

static int	ft_intlen_ul(unsigned long int num)
{
	int result;

	result = 1;
	while (num >= 10)
	{
		result++;
		num /= 10;
	}
	return (result);
}

char		*ft_itoa_ul(unsigned long int n)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = ft_intlen_ul(n);
	if ((str = (char*)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	str[len] = '\0';
	len--;
	while (i < len + 1)
	{
		str[len] = n % 10 + '0';
		n = (n - n % 10) / 10;
		len--;
	}
	return (str);
}
