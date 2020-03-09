/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_fspecif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:26:44 by sluhtala          #+#    #+#             */
/*   Updated: 2020/02/06 16:25:48 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_flag(char c)
{
	if (c == 'l' || c == 'L' || c == 'h' || c == ' ' ||
	c == '+' || c == '-' || c == '#' || c == '0'
	|| (c >= '1' && c <= '9') || c == '.')
		return (1);
	return (0);
}

int			is_fspecif(char c)
{
	if (c == '%' || c == 'c' || c == 's' || c == 'o' ||
	c == 'i' || c == 'u' || c == 'x' || c == 'X'
	|| c == 'f' || c == 'p' || c == 'd')
		return (1);
	return (0);
}

int			is_valid_format(char *str, int len)
{
	int i;

	i = 0;
	if (len < 2)
		return (0);
	while (str[i] && i < len)
	{
		if (!is_flag(str[i]) && !is_fspecif(str[i]))
			return (0);
		i++;
	}
	if (i < 2 || !is_fspecif(str[i - 1]))
		return (0);
	return (1);
}
