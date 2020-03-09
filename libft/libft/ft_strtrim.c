/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 20:04:44 by sluhtala          #+#    #+#             */
/*   Updated: 2019/11/05 20:10:45 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;
	int		y;
	int		slen;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	i = 0;
	j = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		i++;
	y = slen - 1;
	while ((s[y] == ' ' || s[y] == '\n' || s[y] == '\t') && y > i)
	{
		j++;
		y--;
	}
	if ((str = ft_strnew(slen + 1 - i - j)) == NULL)
		return (NULL);
	str = ft_strncpy(str, s + i, slen - i - j);
	return (str);
}
