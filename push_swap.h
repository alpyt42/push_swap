/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:11:21 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/15 11:11:40 by ale-cont         ###   ########.fr       */
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
	struct s_list	*bef;
}	t_list;

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
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
int		istri(t_list *list);
void	algo_three_nbrs(t_list *list, char c);
void	algo_six_nbrs(t_list *lista, t_list *listb, int argc);
void	fill_a(t_list **lista, t_list **listb);
int		*idx(char *argv[], int argc);
void	algo_radx(t_list *lista, t_list *listb, int argc);
int		parse_args(int argc, char ***argv);
int		ft_check_duplicate(int size, int *list);
char	**ft_split(char const *s, char c);
int		ft_strlen(char *str);
int		ft_count_words(char *str, char c);
char	*ft_strjoin(char *left_str, char *buf);
int		*idx(char *argv[], int argc);
void	ft_display_list(t_list *list);
t_list	*ft_init(int *tab, int argc);
int		extrem_nbr(t_list *list, int inpt);
char	**ft_freeall(char **res, size_t args);

#endif