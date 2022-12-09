/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 00:52:59 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/09 17:18:00 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		max_nbr(t_list *list)
{
	t_list	*elem;
	int		max;

	elem = list;
	max = 0;
	if (!list)
		return (0);
	while (elem->next != NULL)
	{
		if (elem->nbr > max)
			max = elem->nbr;
		elem = elem->next;
	}
	return (max);
}

int	h_first(t_list *list, int min, int max)
{
	t_list	*elem;
	int		count;

	elem = list;
	count = 0;
	while (elem->next && elem->nbr <= min && elem->nbr <= max)
	{
		elem = elem->next;
		count++;
	}
	return (count);
}

int	h_sec(t_list *list, int min, int max)
{
	t_list	*elem;
	int		count;

	elem = ft_lstlast(list);
	count = 0;
	while (elem->bef && elem->nbr <= min && elem->nbr <= max)
	{
		elem = elem->bef;
		count++;
	}
	return (count);
}

void	f_stack(t_list *flst, t_list *tlst, char c)
{
	t_list	*elem;
	int		max;

	elem = tlst;
	max = max_nbr(tlst);
	if (max < elem->nbr)
	{
		if (h_first(tlst, max, max) < h_sec(tlst, max, max))
			while (tlst->nbr != max)
				rotate(tlst, c);
		else
			while (tlst->nbr != max)
				rev_rotate(tlst, c);
	}
	else
		if (h_first(tlst, flst->nbr, max) < h_sec(tlst, flst->nbr, max))
			while (tlst->nbr != max)
				rotate(tlst, c);
		else
			while (tlst->nbr != max)
				rev_rotate(tlst, c);
	push(&flst, &tlst, c);
}

int	min_move(int bot, int top, t_list *lista)
{
	t_list	*elem;
	int		count_top;
	int		count_bot;

	elem = lista;
	count_top = 0;
	count_bot = 0;
	while (elem->nbr != top)
	{
		elem = elem->next;
		count_top++;
	}
	elem = ft_lstlast(lista);
	while (elem->nbr != bot)
	{
		elem = elem->bef;
		count_bot++;
	}
	if (count_top <= count_bot)
		return (count_top);
	else
		return (-count_bot);
}

void	algo_hundred(t_list *lista, t_list *listb, int argc)
{
	t_list	*top;
	t_list	*bot;
	int		move;
	int		i;
	int		chunk_bot;

	top = lista;
	i = -1;
	bot = ft_lstlast(lista);
	chunk_bot = 1;
	while (top->nbr < chunk_bot && top->nbr >= argc)
		top = top->next;
	while (bot->nbr < chunk_bot && bot->nbr >= argc)
		bot = bot->bef;
	move = min_move(bot->nbr, top->nbr, lista);
	if (move > 0)
		while (++i < move)
			rotate(lista, 'a');
	else
		while (++i < - move)
			rev_rotate(lista, 'a');
	f_stack(lista, listb, 'b');
}
