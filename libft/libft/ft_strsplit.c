/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 20:45:34 by sluhtala          #+#    #+#             */
/*   Updated: 2019/11/06 18:01:34 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_list_amount(char const *s, char c)
{
	int i;
	int result;

	result = 0;
	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			result++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (result);
}

static char	**ft_strsplit_helper(char const *s, char c, char **list)
{
	int i;
	int y;
	int chars;

	i = 0;
	y = 0;
	while (s[i] != '\0')
	{
		chars = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			while (s[i] != c && s[i] != '\0')
			{
				chars++;
				i++;
			}
			if (!(list[y] = ft_strsub(s, i - chars, chars)))
				return (NULL);
			y++;
		}
	}
	return (list);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**list;
	int		lslen;

	lslen = ft_list_amount(s, c);
	if ((list = (char**)malloc(sizeof(char*) * lslen + 1)) == NULL)
		return (NULL);
	list[lslen] = NULL;
	if (!(list = ft_strsplit_helper(s, c, list)))
		return (NULL);
	return (list);
}
