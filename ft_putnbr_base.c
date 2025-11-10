/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgobert <tgobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:35:42 by tgobert           #+#    #+#             */
/*   Updated: 2025/11/10 12:55:15 by tgobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putnbr_base_fd(int nbr, char *base, int fd)
{
	int	i;
	int	length_base;

	i = 0;
	while (base[i] != 0)
		i++;
	length_base = i;
	if (nbr < 0)
	{
		write(1, "-", 1);
		ft_putnbr_base_fd(-nbr, base, fd);
	}
	else if (nbr > length_base - 1)
	{
		ft_putnbr_base_fd(nbr / length_base, base, fd);
		ft_putnbr_base_fd(nbr % length_base, base, fd);
	}
	else
	{
		ft_putchar_fd(base[0 + nbr]);
	}
}