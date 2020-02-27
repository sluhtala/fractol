/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:00:50 by sluhtala          #+#    #+#             */
/*   Updated: 2019/11/05 20:10:09 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = ft_strnew(ft_strlen(s) + 1)))
		return (NULL);
	str = ft_strcpy(str, s);
	while (str[i] != '\0')
	{
		str[i] = f(str[i]);
		i++;
	}
	return (str);
}
