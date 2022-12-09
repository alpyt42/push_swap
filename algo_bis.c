/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 00:52:59 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/09 11:44:46 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_hundred(t_list *lista, t_list *listb, int argc)
{
	t_list	*top;
	t_list	*bot;
	int		chunk_bot;

	top = lista;
	bot = ft_lstlast(lista);
	chunk_bot = 1;
	while (top->nbr >= chunk_bot && top->nbr < argc)
		top = top->next;
	while (bot->nbr >= chunk_bot && bot->nbr < argc)
		bot = bot->next;
	
}

void	check_sens(t_list *top, t_list *bot, t_list *lista)
{
	t_list	*elem;
	int		count_top;
	int		count_bot;

	elem = lista;
	count_top = 0;
	count_bot = 0;
	while (elem != top)
	{
		elem = elem->next;
		count_top++;
	}
	elem = lista;
	while (elem != bot)
	{
		elem = elem->next;
		count_bot++;
	}
	if (count_top <= count_bot)
		return (1);
	else if (count_top > count_bot)
		return (2);
}
