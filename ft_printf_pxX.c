/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pxX.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgobert <tgobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:35:08 by tgobert           #+#    #+#             */
/*   Updated: 2025/11/14 08:53:03 by tgobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_p(va_list args, int fd, int len)
{
	unsigned long long	n;

	n = va_arg(args, unsigned long long);
	if (!n)
	{
		len = ft_putstr_fd_len("(nil)", fd, len);
		return (len);
	}
	len = ft_putchar_fd_len('0', fd, len);
	len = ft_putchar_fd_len('x', fd, len);
	len = ft_putnbr_base_u_fd(n, HLF, 1, len);
	return (len);
}

int	ft_printf_x(long long int n, int fd, int len)
{
	len = ft_putnbr_base_fd(n, HLF, fd, len);
	return (len);
}

int	ft_printf_majx(long long int n, int fd, int len)
{
	len = ft_putnbr_base_fd(n, HUF, fd, len);
	return (len);
}
