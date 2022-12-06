/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 01:20:00 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/06 01:25:43 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		write(fd, &s[i++], 1);
	write(fd, "\n", 1);
}

static int	ft_sizenum(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

void	ft_itoa(int n)
{
	int		i;
	long	nb;
	char	*res;

	i = 0;
	nb = n;
	res = (char *)malloc(sizeof(char) * (ft_sizenum(n) + 1));
	if (!res)
		return ;
	if (nb == 0)
		res[0] = 0 + 48;
	if (nb < 0)
		nb *= -1;
	while (nb != 0)
	{
		res[ft_sizenum(n) - 1 - i++] = nb % 10 + 48;
		nb = nb / 10;
	}
	if (n < 0)
		res[0] = '-';
	res[ft_sizenum(n)] = '\0';
	ft_putstr_fd(res, 1);
	free(res);
}