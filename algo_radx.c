/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_radx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:32:54 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/15 11:55:52 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_radx(t_list *lista, t_list *listb, int size)
{
	int	maxbit;
	int	i;
	int	j;

	i = -1;
	maxbit = 0;
	while ((size >> maxbit) != 0)
		++maxbit;
	while (++i < maxbit)
	{
		j = -1;
		while (lista && ++j < size)
		{
			if(((lista->nbr >> i) & 1) == 1)
				rotate(lista, 'a');
			else
				push(&lista, &listb, 'b');
		}
		while (listb)
			push(&listb, &lista, 'a');
	}
}