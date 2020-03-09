/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:08:38 by sluhtala          #+#    #+#             */
/*   Updated: 2019/10/23 22:22:59 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int i;
	int s2len;

	s2len = ft_strlen(s1);
	i = 0;
	while (s2[i] != '\0' && n > 0)
	{
		s1[i + s2len] = s2[i];
		i++;
		n--;
	}
	s1[i + s2len] = '\0';
	return (s1);
}
