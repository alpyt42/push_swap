/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:29:13 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/09 00:49:32 by ale-cont         ###   ########.fr       */
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

void	algo_three_nbrs(t_list *list, char c, int argc)
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

int	fill_a(t_list **lista, t_list **listb, int len)
{
	int	max;

	if ((*lista) == NULL)
		return (0);
	max = ft_lstlast(*lista)->nbr;
	while ((*listb) != NULL)
	{
		while ((*listb) != NULL && max < (*listb)->nbr)
		{
			push(&(*listb), &(*lista), 'a');
			rotate((*lista), 'a');
			max = ft_lstlast(*lista)->nbr;
		}
		if ((*listb) == NULL)
			return (len);
		while ((*listb)->nbr > (*lista)->nbr && (*lista)->nbr != max)
		{
			rotate((*lista), 'a');
			len++;
		}
		push(&(*listb), &(*lista), 'a');
	}
	return (len);
}

void	algo_six_nbrs(t_list *lista, t_list *listb, int argc)
{
	int	len;
	int	i;

	i = -1;
	len = 0;
	while (++i < argc - 3)
		push(&lista, &listb, 'b');
	algo_three_nbrs(lista, 'a', argc);
	if (ft_lstlast(lista)->nbr < ft_lstlast(listb)->nbr && argc == 5)
		rev_rotate(listb, 'b');
	else if (argc >= 5)
		algo_three_nbrs(listb, 'b', argc);
	len += fill_a(&lista, &listb, len);
	i = -1;
	while (++i < len && istri(lista) == 0)
		rev_rotate(lista, 'a');
}
