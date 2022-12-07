/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:11:21 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/07 14:03:29 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				nbr;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(int nbr);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
long	ft_atoi(char *str);
void	ft_clear_list(t_list *lst);
void	ft_display_list(t_list *lista);
void	ft_itoa(int n);
void	ft_putstr_fd(char *s, int fd);
void	swap(t_list *list, char c);
void	push(t_list **from_list, t_list **to_list, char c);
void	rotate(t_list *list, char c);
void	rev_rotate(t_list *list, char c);
int		ft_error(char **argv);
int		ft_check_duplicate(t_list *list);
int		istri(t_list *list);
void	algo_three_nbrs(t_list *list, char c, int argc);
void	algo_six_nbrs(t_list *lista, t_list *listb, int argc);

#endif