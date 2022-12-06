/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:17:37 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/06 02:37:56 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_display_list(t_list *lista)
{
	t_list	*elem;
	
	elem = lista;
	while (elem != NULL)
	{
		ft_itoa(elem->nbr);
		elem = elem->next;
	}
}

int	ft_error(char **argv)
{
	int	i;
	
	i = 1;
	if (!argv)
		return (0);
	while (argv[i])
		if (ft_atoi(argv[i++]) == 0)
			return (0);
	return (1);
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
	
	if (argc <= 0 || ft_error(argv) == 0)
		return (0);
	lista = ft_init(argv);
	listb = (void *)0;
	swap(lista);
	push(&lista, &listb);
	push(&lista, &listb);
	push(&lista, &listb);
	push(&lista, &listb);
	printf("\nlist a \n");
	ft_display_list(lista);
	printf("\nlist b \n");
	ft_display_list(listb);
	ft_clear_list(lista);
	ft_clear_list(listb);
	return 0;
}
