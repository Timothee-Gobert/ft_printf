/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inox <inox@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 07:28:56 by tgobert           #+#    #+#             */
/*   Updated: 2025/11/10 22:51:23 by inox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

// reprise de libft
int	ft_putchar_fd(char c, int fd, int len)
{
	write(fd, &c, 1);
	len++;
	return (len);
}

int	ft_putstr_fd(char *s, int fd, int len)
{
	int i;

	i = 0;
	while (s[i])
	{
		len = ft_putchar_fd(s[i], fd, len);
		i++;
	}
	return (len);
}

int ft_printf_s(char *str, int fd, int len)
{
    len = ft_putstr_fd(str, fd, len);
    return (len);
}

int ft_printf_c(int c, int fd, int len)
{
    len = ft_putchar_fd(c, fd , len);
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
		len = ft_putchar_fd('-', 1, len);
		len = ft_putnbr_base_fd(-nbr, base, fd, len);
	}
	else if (nbr > i - 1)
	{
		len = ft_putnbr_base_fd(nbr / i, base, fd, len);
		len = ft_putnbr_base_fd(nbr % i, base, fd, len);
	}
	else
	{
		len = ft_putchar_fd(base[0 + nbr], fd, len);
	}
	return (len);
}

int	ft_putnbr_base_unsigned_fd(unsigned int nbr, char *base, int fd, int len)
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
		len = ft_putchar_fd(base[0 + nbr], fd, len);
	}
	return (len);
}

int ft_printf_p(long long int n, int fd, int len)
{
    len = ft_putchar_fd('0', fd, len);
	len = ft_putchar_fd('x', fd, len);
	len = ft_putnbr_base_fd(n, "0123456789abcdef", 1, len);
	return (len);
}

int ft_printf_x(long long int n, int fd, int len)
{
	len = ft_putnbr_base_fd(n, "0123456789abcdef", 1, len);
	return (len);
}

int ft_printf_X(long long int n, int fd, int len)
{
	len = ft_putnbr_base_fd(n, "0123456789ABCDEF", 1, len);
	return (len);
}

int ft_printf_u(long long int n, int fd, int len)
{
	len = ft_putnbr_base_unsigned_fd(n, "0123456789", 1, len);
	return (len);
}

int ft_printf_d_i(long long int n, int fd, int len)
{
	len = ft_putnbr_base_fd(n, "0123456789", 1, len);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	int	i;
	int	len;
	
	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if ((str[i + 1] == '%'))
				len = ft_putchar_fd('%', 1, len);
			else if ((str[i + 1] == 'c'))
				len = ft_printf_c(va_arg(args, int), 1, len);
			else if ((str[i + 1] == 's'))
				len = ft_printf_s(va_arg(args, char *), 1, len);
			else if ((str[i + 1] == 'p'))
				len = ft_printf_p(va_arg(args, long long int), 1, len);
			else if ((str[i + 1] == 'd') || (str[i + 1] == 'i'))
				len = ft_printf_d_i(va_arg(args, int), 1, len);
			else if ((str[i + 1] == 'u'))\
			 	len = ft_printf_u(va_arg(args,unsigned int), 1, len);
			else if ((str[i + 1] == 'x'))
				len = ft_printf_x(va_arg(args, long long int), 1, len);
			else if ((str[i + 1] == 'X'))
				len = ft_printf_X(va_arg(args, long long int), 1, len);
			else
			{
				len = ft_putchar_fd('%', 1, len);
				i--;
			}
			i += 2;
		}
		else
		{
			len = ft_putchar_fd(str[i], 1, len);
			i++;
		}
		// printf("%d\n", len);
	}
	va_end (args);
	printf("final %i\n", len);
	return (len);
}

int main(void)
{
	int n = 1456543;
	int size = 0;
	
	size = ft_printf("%s a %d H c 1 %c** %p %X %x %u\n", "Tim", 33, 'c', &n, n , n, n);
	printf("siwe of print f = %d", size);
	size = printf("%s a %d H c 1 %c** %p %X %x %u\n", "Tim", 33, 'c', &n, n , n, n);
	printf("siwe of print f = %d", size);
	return 0;
}
