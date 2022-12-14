/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:36:17 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/14 14:15:48 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*extract_values(int size, char **argv)
{
	int	j;
	int	*values;

	j = -1;
	values = (int *)malloc(sizeof(int) * (size + 1));
	if (!values)
		return ((void *)0);
	while (++j < size)
		values[j] = ft_atoi(argv[j]);
	return (values);
}

int	ft_check_duplicate(int size, int *list)
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
	int i;
	int size;
	int *values;
	char *char_values;

	i = 1;
	char_values = NULL;
	while (i < argc)
		char_values = ft_strjoin(char_values, (*argv)[i++]);
	// printf("char values: %s\n", char_values);
	// printf("i:%d\n", i);
	size = ft_count_words(char_values, ' ');
	// printf("size:%d\n", size);
	*argv = ft_split(char_values, ' ');
	// printf("argv[0]%s\n", (*argv)[0]);
	// printf("argv[1]%s\n", (*argv)[1]);
	// printf("argv[2]%s\n", (*argv)[2]);
	// printf("argv[3]%s\n", (*argv)[3]);
	// printf("argv[4]%s\n", (*argv)[4]);
	// printf("argv[5]%s\n", (*argv)[5]);
	free(char_values);
	i = 0;
	while (i < size)
	{
		if (ft_atoi((*argv)[i]) > INT_MAX || ft_atoi((*argv)[i]) < INT_MIN)
			return (0);
		i++;
	}
	values = extract_values(size, (*argv));
	if (ft_check_duplicate(size, values))
		return (free(values), 0);
	return (free(values), size);
}
