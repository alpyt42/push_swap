/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:29:13 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/07 14:38:41 by ale-cont         ###   ########.fr       */
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

void	algo_six_nbrs(t_list *lista, t_list *listb, int argc)
{
	int	len;
	int	i;
	int	j;

	j = -1;
	i = -1;
	len = 0;
	while (++j < argc - 3)
		push(&lista, &listb, 'b');
	algo_three_nbrs(lista, 'a', argc);
	if (ft_lstlast(lista)->nbr < ft_lstlast(listb)->nbr && argc == 2)
		rev_rotate(listb, 'b');
	if (ft_lstlast(lista)->nbr < listb->nbr)
	{
		push(&listb, &lista, 'a');
		rotate(lista, 'a');
	}
	else if (argc - 3 >= 2 && istri(listb) == 0)
		algo_three_nbrs(listb, 'b', argc);
	// printf("\nLista %d %d %d\n", lista->nbr,lista->next->nbr,lista->next->next->nbr);
	// printf("\nListb %d %d\n", listb->nbr,listb->next->nbr);
	// printf("last a%d", ft_lstlast(lista)->nbr);
	// printf("last b%d", ft_lstlast(listb)->nbr);
	while (listb != NULL)
	{
		while (listb->nbr > lista->nbr)
		{
			rotate(lista, 'a');
			len++;
		}
		push(&listb, &lista, 'a');
	}
	while (++i < len && !istri(lista))
		rev_rotate(lista, 'a');
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
	return (elem_med);
}