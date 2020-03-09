/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 12:38:31 by sluhtala          #+#    #+#             */
/*   Updated: 2019/10/28 20:12:41 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int		len;
	char	c;

	len = ft_intlen(n);
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		len--;
		n = n * -1;
	}
	while (len > 1)
	{
		c = (n - n % ft_power(10, len - 1)) / ft_power(10, len - 1) + '0';
		ft_putchar(c);
		n = n % ft_power(10, len - 1);
		len--;
	}
	n = n % ft_power(10, len);
	ft_putchar(n + '0');
}
