/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:50:14 by sluhtala          #+#    #+#             */
/*   Updated: 2019/11/05 20:10:30 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *str;

	if ((str = ft_strnew(len + 1)) == NULL)
		return (NULL);
	str = ft_strncpy(str, s + start, len);
	return (str);
}
