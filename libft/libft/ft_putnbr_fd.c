/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 12:45:45 by sluhtala          #+#    #+#             */
/*   Updated: 2019/10/28 20:19:40 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		len;
	char	c;

	len = ft_intlen(n);
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		len--;
		n = n * -1;
	}
	while (len > 1)
	{
		c = (n - n % ft_power(10, len - 1)) / ft_power(10, len - 1) + '0';
		ft_putchar_fd(c, fd);
		n = n % ft_power(10, len - 1);
		len--;
	}
	n = n % ft_power(10, len);
	ft_putchar_fd(n + '0', fd);
}
