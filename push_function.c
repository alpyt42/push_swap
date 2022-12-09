/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 01:30:17 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/09 10:24:22 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *list, char c)
{
	int	tmp;

	if (list == NULL || list->next == NULL)
		return;
	tmp = list->next->nbr;
	list->next->nbr = list->nbr;
	list->nbr = tmp;
	if (c == 'a')
		ft_putstr_fd("sa", 1);
	else if (c == 'b')
		ft_putstr_fd("sb", 1);
}

void	push(t_list **from_list, t_list **to_list, char c)
{
	t_list	*tmp;

	if (*from_list == NULL)
		return;
	tmp = *from_list;
	*from_list = (*from_list)->next;
	tmp->next = *to_list;
	*to_list = tmp;
	if (c == 'a')
		ft_putstr_fd("pa", 1);
	else if (c == 'b')
		ft_putstr_fd("pb", 1);
}

void	rotate(t_list *list, char c)
{
	int	last;
	int	tmp;

	if (list == NULL || list->next == NULL)
		return;
	last = ft_lstlast(list)->nbr;
	ft_lstlast(list)->nbr = list->nbr;
	while (list->next->next != NULL)
	{
		tmp = list->nbr;
		list->nbr = list->next->nbr;
		list->next->nbr = tmp;
		list = list->next;
	}
	list->nbr = last;
	if (c == 'a')
		ft_putstr_fd("ra", 1);
	else if (c == 'b')
		ft_putstr_fd("rb", 1);
}

void	rev_rotate(t_list *list, char c)
{
	int	tmp;
	int	tmp_bis;

	if (list == NULL || list->next == NULL)
		return;
	tmp = list->nbr;
	list->nbr = ft_lstlast(list)->nbr;
	list = list->next;
	while (list != NULL)
	{
		tmp_bis = list->nbr;
		list->nbr = tmp;
		tmp = tmp_bis;
		list = list->next;
	}
	if (c == 'a')
		ft_putstr_fd("rra", 1);
	else if (c == 'b')
		ft_putstr_fd("rrb", 1);
}