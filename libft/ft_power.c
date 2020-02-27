/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 20:24:55 by sluhtala          #+#    #+#             */
/*   Updated: 2019/10/24 17:25:12 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_power(int num, int power)
{
	int result;

	if (power == 0)
		return (1);
	result = num * ft_power(num, power - 1);
	return (result);
}
