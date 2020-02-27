/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 19:30:20 by sluhtala          #+#    #+#             */
/*   Updated: 2019/11/07 15:34:43 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *ls;

	while (*alst != NULL)
	{
		ls = *alst;
		*alst = ls->next;
		del(ls->content, ls->content_size);
		free(ls);
		ls = NULL;
	}
}
