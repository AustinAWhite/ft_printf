#include "../includes/ft_printf.h"

int         handle_int(t_spdata data, va_list args, int base)
{
    intmax_t val;

    val = va_arg(args, intmax_t);
    if (!val && !data.prec)
        return (pf_print_out(data, ""));
    if (data.length.hh)
        val = (char)val;
    else if (data.length.h)
        val = (short)val;
    else if (data.length.l)
        val = (long)val;
    else if (data.length.ll)
        val = (long long)val;
    else if (data.length.j)
        val = (intmax_t)val;
    else if (data.length.z)
        val = (size_t)val;
    else
        val = (int)val;
    return (pf_print_out(data, ft_itoa_base(val, base)));
}

int         handle_uint(t_spdata data, va_list args, int base)
{
    uintmax_t val;

    val = va_arg(args, uintmax_t);
    if (!val && !data.prec)
        return (pf_print_out(data, ""));
    if (data.length.l || CONV == 'U')
		val = (unsigned long)val;
	else if (data.length.hh)
		val = (unsigned int)val;
	else if (data.length.h)
		val = (unsigned short)val;
	else if (data.length.ll)
		val = (unsigned long long)val;
	else if (data.length.j)
		val = (uintmax_t)val;
	else if (data.length.z)
		val = (size_t)val;
	else
		val = (unsigned int)val;
	return (pf_print_out(data, ft_itoa_base_uint(val, base)));
}

