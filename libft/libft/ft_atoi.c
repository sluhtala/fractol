/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:32:48 by sluhtala          #+#    #+#             */
/*   Updated: 2019/11/07 15:36:56 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_remove_whitespace(const char *str)
{
	int i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+')
	{
		i++;
		if (str[i] < 48 || str[i] > 57)
			return (-1);
		return (i);
	}
	return (i);
}

int			ft_atoi(const char *str)
{
	int result;
	int is_negative;
	int i;

	result = 0;
	is_negative = 1;
	i = 0;
	i = ft_remove_whitespace(str);
	if (i == -1)
		return (0);
	if (str[i] == 45)
	{
		is_negative = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * is_negative);
}
