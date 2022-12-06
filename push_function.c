/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 01:30:17 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/06 02:34:45 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *list)
{
	int	tmp;

	if (list == NULL || list->next == NULL)
		return;
	tmp = list->next->nbr;
	list->next->nbr = list->nbr;
	list->nbr = tmp;
}

void	push(t_list **from_list, t_list **to_list)
{
	t_list	*tmp;

	if (*from_list == NULL)
		return;
	tmp = *from_list;
	*from_list = (*from_list)->next;
	tmp->next = *to_list;
	*to_list = tmp;
}
