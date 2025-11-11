#include "ft_printf.h"

int ft_printf_p(int n, int fd, int len)
{
    ft_putchar_fd(n, fd);
    len++;
    return (len);
}