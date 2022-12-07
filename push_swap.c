/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:17:37 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/07 20:00:16 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_display_list(t_list *list)
{
	t_list	*elem;
	
	if (list == NULL)
		return;
	printf("test");
	elem = list;
	while (elem != NULL)
	{
		ft_itoa(elem->nbr);
		elem = elem->next;
	}
}

t_list	*ft_init(char **argv)
{
	t_list	*new;
	t_list	*list;
	int		i;

	i = 1;
	list = (void *)0;
	while (argv[i])
	{
		new = ft_lstnew(ft_atoi(argv[i++]));
		ft_lstadd_back(&list, new);
	}
	return (list);
}

int main(int argc, char *argv[])
{
	t_list	*lista;
	t_list	*listb;
	
	if (argc <= 1 || ft_error(argv) == 0)
	{
		ft_putstr_fd("Error",1);
		return (0);	
	}
	lista = ft_init(argv);
	if (ft_check_duplicate(lista) == 0)
	{
		ft_putstr_fd("Error",1);
		ft_clear_list(lista);
		return (0);	
	}
	listb = (void *)0;
	printf("___________\n");
	printf("argc = %d", argc);
	printf("\nInit: list a \n");
	ft_display_list(lista);
	// rotate(lista, 'a');
	// swap(lista, 'a');
	// push(&lista, &listb, 'b');
	printf("..........\n");
	if (argc == 3 || argc == 4)
		algo_three_nbrs(lista, 'a', argc - 1);
	if (argc > 4 && argc <= 7)
		algo_six_nbrs(lista, listb, argc - 1);
	printf("..........\n");
	printf("\nResults: list a \n");
	ft_display_list(lista);
	if (istri(lista) == 1 && ft_lstsize(lista) == argc - 1)
		printf("\n/'_'\\ CORRECT (sorted & no lost) /'_'\\\n___________\n");
	else
		printf("\n/!\\ NOT CORRECT (sorted || lost) /!\\\n___________\n");
	printf("\nlist b \n");
	ft_display_list(listb);
	ft_clear_list(lista);
	ft_clear_list(listb);
	return (0);
}
