/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgobert <tgobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 07:28:56 by tgobert           #+#    #+#             */
/*   Updated: 2025/11/10 12:21:52 by tgobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

// reprise de libft
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
	{
		return ((void) NULL);
	}
	while (*s)
		write(fd, s++, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	ln;

	ln = n;
	if (ln < 0)
	{
		ft_putchar_fd('-', fd);
		ln *= -1;
	}
	if (ln <= 9)
		ft_putchar_fd(ln + '0', fd);
	else
	{
		ft_putnbr_fd(ln / 10, fd);
		ft_putnbr_fd(ln % 10, fd);
	}
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
				write(STDOUT_FILENO, "%", 1);
			else if ((str[i + 1] == 'c'))
				ft_putchar_fd(va_arg(args, int), 1);
			else if ((str[i + 1] == 's'))
				ft_putstr_fd(va_arg(args, char *), 1);
			// else if ((str[i + 1] == 'p'))
			else if ((str[i + 1] == 'd'))
				ft_putnbr_fd(va_arg(args, int), 1);
			// else if ((str[i + 1] == 'i'))
			// else if ((str[i + 1] == 'u'))
			// else if ((str[i + 1] == 'x'))
			// else if ((str[i + 1] == 'X'))
			else
				write(STDOUT_FILENO, "%", 1);
			i += 2;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			i++;
		}
	}
	va_end (args);
	return (0);
}

int main(void)
{
	int n = 1;
	ft_printf("%s a %d H c 1 %c**\n", "Tim", 33 , 'c');
	printf("%s a %d H c 1 %c** %p\n", "Tim", 33 , 'c', &n);
	return 0;
}
