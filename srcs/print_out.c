#include "../includes/ft_printf.h"

static int      pf_offset(t_spdata data, int *neg, char *val)
{
    int offset;

    offset = 0;
    if ((!ft_strcmp(val, "0") || !ft_strlen(val)) && !(PLUS || SPACE || CONV == 'o'))
        return (0);
    if (HASH || CONV == 'p')
    {
        if (CONV == 'o')
            offset += 1;
        if (CONV == 'x' || CONV == 'X' || CONV == 'p')
            offset += 2;
    }
    if (CONV == 'd' || CONV == 'i')
        if (((PLUS || SPACE) && val[0] != '-'))
            offset += 1;
    if (val[0] == '-')
        *neg = 1;
    return (offset);
}

static int      pf_field_size(t_spdata data, int *neg, char *val)
{
    int size;

    size = ft_strlen(val) + pf_offset(data, neg, val);
    if (size > ft_max(data.prec, data.fwidth))
        return (size);
    return (ft_max(data.prec, data.fwidth));
}

static int      pf_poffs(int offs, int plus, int sp, int X, char **val)
{
    if (offs == 0 && *val[0] != '-')
        return (0);
    else if (*val[0] == '-')
        return (ft_putstr_len("-"));
    else if (offs == 2)
        return ((X) ? (ft_putstr_len("0X")) : (ft_putstr_len("0x")));
    else if (plus && *val[0] != '-')
        return (ft_putstr_len("+"));
    else if (sp && *val[0] != '-')
        return (ft_putstr_len(" "));
    return (ft_putstr_len("0"));
}

int         pf_print_out(t_spdata data, char *val)
{
    int ptotal;
    int ct;
    int offs;
    int j;
    int k;

    j = 0;
    (CONV == 'c' && *val == 0) ? (k = 1) : (k = 0);
    if (!data.fwidth && !ft_strlen(val) && !(CONV == 'o' || CONV == 'c'))
        return (0);
    if (CONV == 's' && data.prec && data.prec < ft_strlen(val))
        val = ft_strsub(val, 0, data.prec);
    ptotal = pf_field_size(data, &j, val);
    offs = pf_offset(data, &j, val);
    if (ZERO && j)
        offs += j;
    ct = ptotal;
    if (!ft_strlen(val) && data.prec > 0)
        data.prec = 0;
    if (j && data.prec && (data.prec > data.fwidth) && (ptotal > (j + ft_strlen(val))))
        ptotal += 1;
    if (!(DASH || (ZERO && (data.prec < 0))))
        ct -= ft_padding(ct - (ft_max(data.prec, ft_strlen(val)) + offs + k), ' ');
    ct -= pf_poffs(offs, PLUS, SPACE, CONV == 'X', &val);
    (ZERO) ? (ct -= ft_padding(ct - ft_strlen(val) + j, '0')) :
    (ct -= ft_padding(data.prec - ft_strlen(val) + j, '0'));
    if (CONV == 'c')
        ct -= ft_putchar_len(*val);
    else
        (CONV == 'X') ? (ct -= ft_putstrupper(val + j)) : (ct -= ft_putstr_len(val + j));
    ft_padding(ct, ' ');
    return (ptotal);
}

