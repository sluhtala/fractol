/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:14:58 by sluhtala          #+#    #+#             */
/*   Updated: 2019/11/04 12:18:25 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printlst(t_list *lst)
{
	if (lst == NULL)
		return ;
	ft_putendl(lst->content);
	while (lst->next != NULL)
	{
		lst = lst->next;
		ft_putendl(lst->content);
	}
}
