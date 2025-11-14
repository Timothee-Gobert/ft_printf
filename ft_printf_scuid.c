/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_scuid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgobert <tgobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:25:03 by tgobert           #+#    #+#             */
/*   Updated: 2025/11/14 08:55:08 by tgobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_s(char *str, int fd, int len)
{
	len = ft_putstr_fd_len(str, fd, len);
	return (len);
}

int	ft_printf_c(int c, int fd, int len)
{
	len = ft_putchar_fd_len(c, fd, len);
	return (len);
}

int	ft_printf_u(long long int n, int fd, int len)
{
	len = ft_putnbr_base_u_fd(n, DN, fd, len);
	return (len);
}

int	ft_printf_d_i(long long int n, int fd, int len)
{
	len = ft_putnbr_base_fd(n, DN, fd, len);
	return (len);
}
