/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:32:08 by sluhtala          #+#    #+#             */
/*   Updated: 2020/01/20 13:33:52 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_pow(int value, int e)
{
	int result;

	result = value;
	if (e == 0)
		return (1);
	while (e > 1)
	{
		result = result * value;
		e--;
	}
	return (result);
}
