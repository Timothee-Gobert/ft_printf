/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgobert <tgobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:06:33 by tgobert           #+#    #+#             */
/*   Updated: 2025/11/10 09:07:33 by tgobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	n_p;
	int	number;

	while (*nptr == ' ' || ('\t' <= *nptr && *nptr <= '\r'))
		nptr++;
	n_p = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			n_p *= -1;
		nptr++;
	}
	number = 0;
	while ('0' <= *nptr && *nptr <= '9')
		number = (number * 10) + (*nptr++ - '0');
	return (number * n_p);
}
