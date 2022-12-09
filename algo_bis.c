/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 00:52:59 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/09 13:19:15 by ale-cont         ###   ########.fr       */
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


