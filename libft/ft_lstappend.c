/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 13:42:04 by sluhtala          #+#    #+#             */
/*   Updated: 2019/10/30 17:10:18 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstappend(t_list **lst, t_list *lastlst)
{
	t_list	*temp;

	if (lastlst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = lastlst;
		return ;
	}
	temp = *lst;
	while (temp->next != NULL)
	{
		if (temp->next == NULL)
			break ;
		temp = temp->next;
	}
	temp->next = lastlst;
}
