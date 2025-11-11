/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inox <inox@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:35:42 by tgobert           #+#    #+#             */
/*   Updated: 2025/11/10 16:33:02 by inox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base_fd(int nbr, char *base, int fd)
{
	int i;
	
	i = 0;
	while (base[i] != 0)
		i++;
	if (nbr < 0)
	{
		write(1, "-", 1);
		ft_putnbr_base_fd(-nbr, base, fd);
	}
	else if (nbr > i - 1)
	{
		ft_putnbr_base_fd(nbr / i, base, fd);
		ft_putnbr_base_fd(nbr % i, base, fd);
	}
	else
	{
		ft_putchar_fd(base[0 + nbr], fd);
	}
}