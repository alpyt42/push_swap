/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:36:17 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/15 12:31:44 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*extract_values(int size, char **argv)
{
	int	j;
	int	*values;

	j = -1;
	values = (int *)ft_calloc(sizeof(int), size);
	if (!values)
		return ((void *)0);
	while (++j < size)
		values[j] = ft_atoi(argv[j]);
	return (values);
}

static int	ft_check_duplicate(int size, int *list)
{
	int		i;
	int		j;

	i = 0;
	if (!list)
		return (0);
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (list[i] == list[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	parse_args(int argc, char ***argv)
{
	int		i;
	int		size;
	int		*values;
	char	*char_values;

	i = 1;
	char_values = NULL;
	while (i < argc)
		char_values = ft_strjoin(char_values, (*argv)[i++]);
	size = ft_count_words(char_values, ' ');
	*argv = ft_split(char_values, ' ');
	free(char_values);
	i = -1;
	while (++i < size)
	{
		if (ft_atoi((*argv)[i]) > INT_MAX || ft_atoi((*argv)[i]) < INT_MIN)
			return (ft_freeall((*argv), size), 0);
	}
	values = extract_values(size, (*argv));
	if (ft_check_duplicate(size, values))
	{
		ft_freeall((*argv), size);
		return (free(values), 0);
	}
	return (free(values), size);
}
