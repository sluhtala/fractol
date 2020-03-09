/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:26:05 by sluhtala          #+#    #+#             */
/*   Updated: 2020/02/05 17:03:42 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_list(t_part **list)
{
	t_part *temp;
	t_part *ls;

	ls = *list;
	if (!ls)
		return ;
	temp = ls->next;
	free(ls->data);
	free(ls->str);
	free(ls);
	ls = temp;
	while (temp)
	{
		free(ls->data);
		free(ls->str);
		free(ls);
		temp = ls->next;
		ls = temp;
	}
	*list = NULL;
}
