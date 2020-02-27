/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:01:40 by sluhtala          #+#    #+#             */
/*   Updated: 2019/10/28 20:29:29 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*su1;
	unsigned char	*su2;

	su1 = (unsigned char*)s1;
	su2 = (unsigned char*)s2;
	i = 0;
	while ((su1[i] || su2[i]) && i < n)
	{
		if (su1[i] != su2[i])
			return (su1[i] - su2[i]);
		i++;
	}
	return (0);
}
