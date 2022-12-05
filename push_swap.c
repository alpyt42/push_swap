/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:17:37 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/05 15:41:05 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	
	if (!argv || argc <= 0 || ft_error(argv) == 0)
		return (0);
	lista = ft_init(argv);
	listb = (void *)0;
	while (lista)
	{
		printf("%d \n", lista->nbr);
		lista = lista->next;
	}
	return 0;
}
