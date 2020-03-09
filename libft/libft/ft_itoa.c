/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:24:38 by sluhtala          #+#    #+#             */
/*   Updated: 2019/11/04 12:34:01 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	if (n == -2147483648)
		return (str = ft_strdup("-2147483648"));
	len = ft_intlen(n);
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
