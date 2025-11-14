/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgobert <tgobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 07:28:56 by tgobert           #+#    #+#             */
/*   Updated: 2025/11/14 08:43:48 by tgobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_print(va_list args, char c, int *i, int len)
{
	if (c == 'd' || c == 'i')
		len = ft_printf_d_i(va_arg(args, int), 1, len);
	else if (c == 's')
		len = ft_printf_s(va_arg(args, char *), 1, len);
	else if (c == 'c')
		len = ft_printf_c(va_arg(args, int), 1, len);
	else if (c == 'p')
		len = ft_printf_p(args, 1, len);
	else if (c == 'u')
		len = ft_printf_u(va_arg(args, unsigned int), 1, len);
	else if (c == 'x')
		len = ft_printf_x(va_arg(args, unsigned int), 1, len);
	else if (c == 'X')
		len = ft_printf_majx(va_arg(args, unsigned int), 1, len);
	else if (c == '%')
		len = ft_putchar_fd_len('%', 1, len);
	else
	{
		len = ft_putchar_fd_len('%', 1, len);
		*i -= 1;
	}
	*i += 2;
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
			len = check_print(args, str[i + 1], &i, len);
		else
		{
			len = ft_putchar_fd_len(str[i], 1, len);
			i++;
		}
	}
	va_end (args);
	return (len);
}

// #include <stdio.h>
// #include <limits.h>
// int	main(void)
// {
// 	int	n = 1456543;
// 	int	size = 0;
// 	size = 	ft_printf("%s a %d H c 1 %c** %p %X %x %u\n"
// 			, "Tim", 33, 'c', &n, n , n, n);
// 	ft_printf("siwe of print f = %d\n", size);
// 	size =    printf("%s a %d H c 1 %c** %p %X %x %u\n"
// 			, "Tim", 33, 'c', &n, n , n, n);
// 	printf("siwe of print f = %d\n", size);
// 	return 0;
// }
// int main(void)
// {
// 	long long nike_min = LONG_MIN;
// 	long long nike_max = LONG_MAX;
// 	ft_printf(" %p %p ", &nike_min, &nike_max);
// 	printf("\n");
// 	printf(" %p %p ", &nike_min, &nike_max);
// }
