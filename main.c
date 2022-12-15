/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:45:33 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/15 14:22:10 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_action(t_list *lista, t_list *listb, int size)
{
	if (!istri(lista))
	{
		if (size == 2 || size == 3)
			algo_three_nbrs(lista, 'a');
		if (size > 3 && size <= 6)
			algo_six_nbrs(lista, listb, size);
		if (size > 6)
			algo_radx(lista, listb, size);
	}
}

int	main(int argc, char *argv[])
{
	t_list	*lista;
	t_list	*listb;
	int		*res;
	int		size;

	if (argc <= 1 || (argv[1][0] == '\0' && argc == 2))
		return (0);
	size = parse_args(argc, &argv);
	if (size == 0)
		return (ft_putstr_fd("Error", STDERR_FILENO), 0);
	res = idx(argv, size);
	lista = ft_init(res, size);
	free (res);
	ft_freeall(argv, size);
	listb = (void *)0;
	ft_action(lista, listb, size);
	ft_clear_list(lista);
	ft_clear_list(listb);
	return (0);
}
