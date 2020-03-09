/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:51:06 by sluhtala          #+#    #+#             */
/*   Updated: 2019/11/05 17:28:57 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		if (needle[j] != haystack[i])
			j = 0;
		if (needle[j] == haystack[i])
			j++;
		if (needle[j] == '\0')
			return ((char*)haystack + i - j + 1);
		i++;
	}
	return (NULL);
}
