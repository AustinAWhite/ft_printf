#include "../includes/ft_printf.h"

int         pf_out(t_spdata data, va_list args)
{
    if (CONV == '%')
        return (pf_print_out(data, "%"));
    else if (CONV == 'd' || CONV == 'i')
        return (handle_int(data, args, 10));
    else if (CONV == 'o')
        return (handle_int(data, args, 8));
    else if (CONV == 'x' || CONV == 'X' || CONV == 'p')
        return (handle_uint(data, args, 16));
    else if (CONV == 'u' || CONV == 'U')
        return (handle_uint(data, args, 10));
    else if (CONV == 's')
        return (handle_s(data, va_arg(args, char *)));
    else if (CONV == 'c')
        return (handle_c(data, va_arg(args, int)));
    else
        return (pf_print_out(data, &CONV));
}
