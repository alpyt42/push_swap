/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_radx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:32:54 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/09 19:13:55 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_radx(t_list *lista, t_list *listb, int argc)
{
	int	maxbit;
	int	total;
	int	i;
	int	j;

	i = -1;
	maxbit = 0;
	total = argc - 1;
	while ((total >> maxbit) != 0)
		++maxbit;
	while (++i < maxbit)
	{
		j = -1;
		while (lista && ++j < total)
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