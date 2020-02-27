/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:28:25 by sluhtala          #+#    #+#             */
/*   Updated: 2019/10/28 19:10:43 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int nbr)
{
	int result;
	int i;

	i = 0;
	result = 0;
	if (nbr == 0)
		return (1);
	if (nbr == -2147483648)
		return (11);
	if (nbr < 0)
	{
		result++;
		nbr = nbr * -1;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		result++;
	}
	return (result + i);
}
