/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:29:13 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/06 18:24:39 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	istri(t_list *list)
{
	t_list	*elem;

	if (list == NULL)
		return (1);
	elem = list;
	while (elem->next)
	{
		if (elem->nbr > elem->next->nbr)
			return (0);
		elem = elem->next;
	}
	return (1);
}

t_list	*find_median(t_list *list)
{
	t_list	*elem_med;
	int		min;
	int		max;

	elem_med = list;
	min = list->nbr;
	max = list->nbr;
	while (elem_med)
	{
		if (elem_med->nbr < min)
			min = elem_med->nbr;
		elem_med = elem_med->next;
	}
	elem_med = list;
	while (elem_med)
	{
		if (elem_med->nbr > max)
			max = elem_med->nbr;
		elem_med = elem_med->next;
	}
	
}