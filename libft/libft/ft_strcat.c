/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:53:07 by sluhtala          #+#    #+#             */
/*   Updated: 2019/10/23 22:22:01 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int i;
	int s2len;

	s2len = ft_strlen(s1);
	i = 0;
	while (s2[i] != '\0')
	{
		s1[i + s2len] = s2[i];
		i++;
	}
	s1[i + s2len] = '\0';
	return (s1);
}
