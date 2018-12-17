#include "../includes/ft_printf.h"

int     ft_printf(const char *fmt, ...)
{
    int     len;
    va_list  args;

    len = 0;
    va_start(args, fmt);
    while (*fmt)
    {
        if (*fmt != '%')
            len += ft_putchar_len(*fmt);
        else
        {
            fmt++;
            len += pf_convert(&fmt, args);
        }
        fmt++;
    }
    va_end(args);
    return (len);
}