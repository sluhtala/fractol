/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:53:30 by sluhtala          #+#    #+#             */
/*   Updated: 2019/10/28 20:29:12 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*su1;
	unsigned char	*su2;

	su1 = (unsigned char*)s1;
	su2 = (unsigned char*)s2;
	i = 0;
	while (su1[i] || su2[i])
	{
		if (su1[i] != su2[i])
			return (su1[i] - su2[i]);
		i++;
	}
	return (0);
}
