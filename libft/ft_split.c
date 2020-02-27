/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:31:08 by sluhtala          #+#    #+#             */
/*   Updated: 2020/02/12 15:41:21 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	else
		return (0);
}

static int	ft_list_amount(char const *s)
{
	int i;
	int result;

	result = 0;
	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		while (is_space(s[i]) && s[i] != '\0')
			i++;
		if (!is_space(s[i]) && s[i] != '\0')
		{
			result++;
			while (!is_space(s[i]) && s[i] != '\0')
				i++;
		}
	}
	return (result);
}

static char	**ft_strsplit_helper(char const *s, char **list)
{
	int i;
	int y;
	int chars;

	i = 0;
	y = 0;
	while (s[i] != '\0')
	{
		chars = 0;
		while (is_space(s[i]) && s[i] != '\0')
			i++;
		if (!is_space(s[i]) && s[i] != '\0')
		{
			while (!is_space(s[i]) && s[i] != '\0')
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

char		**ft_split(char const *s)
{
	char	**list;
	int		lslen;

	lslen = ft_list_amount(s);
	if ((list = (char**)malloc(sizeof(char*) * lslen + 1)) == NULL)
		return (NULL);
	list[lslen] = NULL;
	if (!(list = ft_strsplit_helper(s, list)))
		return (NULL);
	return (list);
}
