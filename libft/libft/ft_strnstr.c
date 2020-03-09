/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:09:30 by sluhtala          #+#    #+#             */
/*   Updated: 2019/10/24 17:06:31 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0' && len > 0)
	{
		if (needle[j] != haystack[i])
			j = 0;
		if (needle[j] == haystack[i])
			j++;
		if (needle[j] == '\0')
			return ((char*)haystack + i - j + 1);
		i++;
		len--;
	}
	return (NULL);
}
