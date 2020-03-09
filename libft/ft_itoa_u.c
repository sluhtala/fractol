/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:27:40 by sluhtala          #+#    #+#             */
/*   Updated: 2020/02/05 17:20:05 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlen_u(unsigned int n)
{
	int len;

	len = 1;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa_u(unsigned int n)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = ft_intlen_u(n);
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
