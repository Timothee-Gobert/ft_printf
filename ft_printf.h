/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgobert <tgobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 07:34:22 by tgobert           #+#    #+#             */
/*   Updated: 2025/11/14 08:52:13 by tgobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define HLF "0123456789abcdef"
# define HUF "0123456789ABCDEF"
# define DN "0123456789"

int	ft_printf(const char *str, ...);
int	check_print(va_list args, char c, int *i, int len);
int	ft_putchar_fd_len(char c, int fd, int len);
int	ft_putstr_fd_len(char *s, int fd, int len);
int	ft_putnbr_base_fd(long long nbr, char *base, int fd, int len);
int	ft_putnbr_base_u_fd(unsigned long long nbr, char *base, int fd, int len);
int	ft_printf_p(va_list args, int fd, int len);
int	ft_printf_x(long long int n, int fd, int len);
int	ft_printf_majx(long long int n, int fd, int len);
int	ft_printf_u(long long int n, int fd, int len);
int	ft_printf_s(char *str, int fd, int len);
int	ft_printf_c(int c, int fd, int len);
int	ft_printf_d_i(long long int n, int fd, int len);

#endif
