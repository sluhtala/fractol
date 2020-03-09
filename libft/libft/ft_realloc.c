/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:22:23 by sluhtala          #+#    #+#             */
/*   Updated: 2019/11/07 16:25:20 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *s, size_t oldsize, size_t newsize)
{
	unsigned char	*new;
	unsigned char	*temp;
	size_t			i;

	i = 0;
	temp = (unsigned char*)s;
	if (!(new = (unsigned char*)ft_memalloc(newsize)))
		return (NULL);
	ft_bzero(new, newsize);
	if (s != NULL && newsize >= oldsize)
		new = ft_memcpy(new, s, oldsize);
	if (oldsize > newsize)
	{
		while (i < newsize)
		{
			new[i] = temp[i];
			i++;
		}
	}
	ft_memdel(&s);
	return (new);
}
