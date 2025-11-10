/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgobert <tgobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 08:37:28 by tgobert           #+#    #+#             */
/*   Updated: 2025/11/10 09:08:10 by tgobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len_total(int n)
{
	int	count;

	count = 1;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*ft_putchar_rec(int *i, int n, char *a)
{
	if (n < 0)
	{
		a[*i] = '-';
		(*i)++;
		if (n < -9)
			ft_putchar_rec(i, n / -10, a);
		ft_putchar_rec(i, -1 * (n % 10), a);
	}
	else if (n > 9)
	{
		ft_putchar_rec(i, n / 10, a);
		ft_putchar_rec(i, n % 10, a);
	}
	else
	{
		a[(*i)++] = n + '0';
	}
	return (a);
}

char	*ft_itoa(int n)
{
	char	*a;
	int		i;

	i = 0;
	a = malloc(sizeof(char) * count_len_total(n));
	if (!a)
		return (NULL);
	ft_putchar_rec(&i, n, a);
	a[count_len_total(n) - 1] = '\0';
	return (a);
}
