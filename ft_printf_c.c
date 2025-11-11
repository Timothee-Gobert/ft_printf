#include "ft_printf.h"

int ft_printf_c(int c, int fd, int len)
{
    ft_putchar_fd(c, fd);
    len++;
    return (len);
}