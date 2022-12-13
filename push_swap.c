/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:17:37 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/13 20:55:12 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*idx(char *argv[], int argc)
{
	int	j;
	int	k;
	int	pos;
	int	*tab;
	int	*res;

	res = (int *)malloc(sizeof(int) * argc);
	tab = (int *)malloc(sizeof(int) * argc);
	if (!res || !tab)
		return ((void *)0);
	j = -1;
	while (++j < argc - 1)
		tab[j] = ft_atoi(argv[j + 1]);
	res[j] = '\0';
	j = -1;
	while (++j < argc - 1)
	{
		pos = 0;
		k = -1;
		while (++k < argc - 1)
			if (tab[j] > tab[k])
				pos++;
		res[j] = pos;
	}
	return (free(tab), res);
}

void	ft_display_list(t_list *list)
{
	t_list	*elem;

	if (list == NULL)
		return ;
	elem = list;
	while (elem != NULL)
	{
		ft_itoa(elem->nbr);
		elem = elem->next;
	}
}

t_list	*ft_init(int *tab, int argc)
{
	t_list	*new;
	t_list	*list;
	int		i;

	i = 0;
	list = (void *)0;
	while (i < argc - 1)
	{
		new = ft_lstnew(tab[i++]);
		ft_lstadd_back(&list, new);
	}
	return (list);
}

int main (int argc, char *argv[])
{
	t_list	*lista;
	t_list	*listb;
	int		*tab;

	if (argc <= 1 || ft_error(argv) == 0)
	{
		ft_putstr_fd("Error", STDERR_FILENO);
		return (0);
	}
	tab = idx(argv, argc);
	lista = ft_init(tab, argc);
	free (tab);
	if (ft_check_duplicate(lista) == 0)
	{
		ft_putstr_fd("Error", STDERR_FILENO);
		ft_clear_list(lista);
		return (0);
	}
	listb = (void *)0;
	// printf("___________\n");
	// printf("argc = %d", argc - 1);
	// printf("\nInit: list a \n");
	// ft_display_list(lista);
	// rotate(lista, 'a');
	// swap(lista, 'a');
	// push(&lista, &listb, 'b');
	// printf("..........\n");
	if (!istri(lista))
	{
		if (argc == 3 || argc == 4)
		algo_three_nbrs(lista, 'a');
		if (argc > 4 && argc <= 7)
			algo_six_nbrs(lista, listb, argc - 1);
		if (argc > 7)
			algo_radx(lista, listb, argc);
	}
	// printf("..........\n");
	// printf("\nResults: list a \n");
	// ft_display_list(lista);
	// if (istri(lista) == 1 && ft_lstsize(lista) == argc - 1)
	// 	printf("\n/'_'\\ CORRECT (sorted & no lost) /'_'\\\n___________\n");
	// else
	// 	printf("\n/!\\ NOT CORRECT (sorted || lost) /!\\\n___________\n");
	// printf("\nlist b \n");
	// ft_display_list(listb);
	ft_clear_list(lista);
	ft_clear_list(listb);
	return (0);
}
