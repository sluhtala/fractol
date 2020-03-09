/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 19:55:55 by sluhtala          #+#    #+#             */
/*   Updated: 2019/10/29 17:25:10 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	slen;
	size_t	dlen;
	size_t	result;

	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	i = dlen;
	while (i + 1 < dstsize && src[i - dlen] != '\0')
	{
		dst[i] = src[i - dlen];
		i++;
	}
	if (dstsize != 0 || dstsize > dlen)
		dst[i] = '\0';
	result = dstsize + slen;
	if (result > slen + dlen)
		return (slen + dlen);
	return (result);
}
