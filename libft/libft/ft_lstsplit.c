/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:19:07 by sluhtala          #+#    #+#             */
/*   Updated: 2019/11/04 12:20:28 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstsplit(char const *s, char c)
{
	t_list	*lst;
	t_list	*alist;
	char	*content;
	int		i;
	int		len;

	alist = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		len = 0;
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		while (s[i + len] != c && s[i + len])
			len++;
		if (!(content = ft_strsub(s, i, len)))
			return (NULL);
		ft_lstappend(&alist, lst = ft_lstnew(content, len + 1));
		lst = lst->next;
		i = i + len;
		free(content);
	}
	return (alist);
}
