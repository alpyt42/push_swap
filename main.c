/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:45:33 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/14 18:27:56 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char *argv[])
{
	t_list	*lista;
	t_list	*listb;
	int		*res;
	int		size;

	if (argv[1] == NULL && argc == 1)
		return (0);
	size = parse_args(argc, &argv);
	if (argc <= 1 || size == 0)
	{
		ft_putstr_fd("Error", STDERR_FILENO);
		return (0);
	}
	// printf("argv%s\n", argv[0]);
	// printf("size%d\n", size);
	res = idx(argv, size);
	lista = ft_init(res, size);
	free (res);
	listb = (void *)0;
	// printf("___________\n");
	// printf("size = %d", size);
	// printf("\nInit: list a \n");
	// ft_display_list(lista);
	// printf("..........\n");
	if (!istri(lista))
	{
		if (size == 2 || size == 3)
			algo_three_nbrs(lista, 'a');
		if (size > 3 && size <= 6)
			algo_six_nbrs(lista, listb, size);
		if (size > 6)
			algo_radx(lista, listb, size);
	}
	// printf("..........\n");
	// printf("\nResults: list a \n");
	// ft_display_list(lista);
	// if (istri(lista) == 1 && ft_lstsize(lista) == size)
	// 	printf("\n/'_'\\ CORRECT (sorted & no lost) /'_'\\\n___________\n");
	// else
	// 	printf("\n/!\\ NOT CORRECT (sorted || lost) /!\\\n___________\n");
	// printf("\nlist b \n");
	// ft_display_list(listb);
	ft_clear_list(lista);
	ft_clear_list(listb);
	return (0);
}