/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:36:17 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/06 13:48:08 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_duplicate(t_list *list)
{
	t_list	*elem;
	t_list	*tmp;
	int		nbr;

	elem = list;
	while (elem)
	{
		tmp = elem->next;
		nbr = elem->nbr;
		while (tmp)
		{
			if (nbr == tmp->nbr)
				return (0);
			tmp = tmp->next;
		}
		elem = elem->next;
	}
	return (1);
}

int	ft_error(char **argv)
{
	int	i;

	i = 1;
	if (!argv)
		return (0);
	while (argv[i])
	{
		if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}
