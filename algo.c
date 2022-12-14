/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:29:13 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/14 18:13:17 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	extrem_nbr(t_list *list, int inpt)
{
	t_list	*elem;
	int		nbr;

	elem = list;
	if (!list)
		return (0);
	if (inpt == 1)
	{
		nbr = 0;
		while (elem != NULL)
		{
			if (elem->nbr > nbr)
				nbr = elem->nbr;
			elem = elem->next;
		}
		return (nbr);
	}
	else
	{
		nbr = 501;
		while (elem != NULL)
		{
			if (elem->nbr < nbr)
				nbr = elem->nbr;
			elem = elem->next;
		}
	}
	return (nbr);
}

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

void	algo_three_nbrs(t_list *list, char c)
{
	int	third;

	third = ft_lstlast(list)->nbr;
	if (list->next->nbr == third)
	{
		if (list->nbr > list->next->nbr)
			swap(list, c);
	}
	else if (list->nbr > list->next->nbr && list->nbr < third)
		swap(list, c);
	else if (list->nbr > list->next->nbr && list->next->nbr > third)
	{
		swap(list, c);
		rev_rotate(list, c);
	}
	else if (list->nbr > list->next->nbr && list->next->nbr < third)
		rotate(list, c);
	else if (list->nbr < list->next->nbr && list->nbr > third)
		rev_rotate(list, c);
	else if (list->nbr < list->next->nbr && list->next->nbr > third)
	{
		swap(list, c);
		rotate(list, c);
	}
}

void	fill_a(t_list **lista, t_list **listb)
{
	int	max;
	int	min;

	while ((*listb) != NULL)
	{
		max = extrem_nbr((*lista), 1);
		min = extrem_nbr((*lista), 0);
		if ((*listb) != NULL && (*listb)->nbr < min && (*lista)->nbr == min)
			push(&(*listb), &(*lista), 'a');
		if ((*listb) != NULL && (*listb)->nbr > max 
			&& ft_lstlast((*lista))->nbr == max)
		{
			push(&(*listb), &(*lista), 'a');
			rotate((*lista), 'a');
		}
		max = extrem_nbr((*lista), 1);
		min = extrem_nbr((*lista), 0);
		if ((*listb) == NULL)
			return ;
		if ((*listb)->nbr > min && (*listb)->nbr < max)
		{
			while ((*listb)->nbr > (*lista)->nbr)
				rotate((*lista), 'a');
			push(&(*listb), &(*lista), 'a');
		}
		else if (ft_lstlast(*lista)->nbr != max)
			rotate((*lista), 'a');
	}
}

void	algo_six_nbrs(t_list *lista, t_list *listb, int size)
{
	int	i;

	i = -1;
	while (++i < size - 3)
		push(&lista, &listb, 'b');
	algo_three_nbrs(lista, 'a');
	if (size >= 5)
		algo_three_nbrs(listb, 'b');
	fill_a(&lista, &listb);
	while (istri(lista) == 0)
		rotate(lista, 'a');
}
