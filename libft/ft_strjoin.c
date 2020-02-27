/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:36:28 by sluhtala          #+#    #+#             */
/*   Updated: 2019/11/05 20:09:48 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;

	if ((str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)) == NULL)
		return (NULL);
	str = ft_strncpy(str, s1, ft_strlen(s1));
	str = ft_strcat(str, s2);
	return (str);
}
