/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:07:57 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/05 13:41:52 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*toadd;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	toadd = ft_lstlast(*lst);
	toadd->next = new;
}
