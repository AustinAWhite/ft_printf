#include "../includes/ft_printf.h"

int             handle_s(t_spdata data, char *str)
{
    return (str) ? (pf_print_out(data, str)) : (ft_putstr_len("(null)"));    
}

int             handle_c(t_spdata data, char c)
{
    int ptotal;
    int ct;

    ptotal = 1;
    if (ptotal < data.fwidth)
        ptotal = data.fwidth;
    if (c == 0 && ptotal == 1)
        return (ft_putchar_len(c));
    return (pf_print_out(data, &c));
}