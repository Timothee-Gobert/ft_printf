/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgobert <tgobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:18:35 by tgobert           #+#    #+#             */
/*   Updated: 2025/11/14 08:59:18 by tgobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd_len(char c, int fd, int len)
{
	write(fd, &c, 1);
	len++;
	return (len);
}

int	ft_putstr_fd_len(char *s, int fd, int len)
{
	int	i;

	i = 0;
	if (!s)
	{
		len = ft_putstr_fd_len("(null)", fd, len);
		return (len);
	}
	while (s[i])
	{
		len = ft_putchar_fd_len(s[i], fd, len);
		i++;
	}
	return (len);
}

int	ft_putnbr_base_fd(long long int nbr, char *base, int fd, int len)
{
	long long int	i;

	i = 0;
	while (base[i] != 0)
		i++;
	if (nbr < 0)
	{
		len = ft_putchar_fd_len('-', 1, len);
		len = ft_putnbr_base_fd(-nbr, base, fd, len);
	}
	else if (nbr > i - 1)
	{
		len = ft_putnbr_base_fd(nbr / i, base, fd, len);
		len = ft_putnbr_base_fd(nbr % i, base, fd, len);
	}
	else
	{
		len = ft_putchar_fd_len(base[nbr], fd, len);
	}
	return (len);
}

int	ft_putnbr_base_u_fd(unsigned long long nbr, char *base, int fd, int len)
{
	unsigned int	i;

	i = 0;
	while (base[i] != 0)
		i++;
	if (nbr > i - 1)
	{
		len = ft_putnbr_base_fd(nbr / i, base, fd, len);
		len = ft_putnbr_base_fd(nbr % i, base, fd, len);
	}
	else
	{
		len = ft_putchar_fd_len(base[nbr], fd, len);
	}
	return (len);
}
