#include "../includes/ft_printf.h"


static void print_cnvt(t_spdata cnvt)
{
    printf("\n#:           %d\n", cnvt.flg.hash);
    printf("0:           %d\n", cnvt.flg.zero);
    printf("-:           %d\n", cnvt.flg.dash);
    printf("+:           %d\n", cnvt.flg.plus);
    printf("sp:          %d\n", cnvt.flg.space);
    printf("hh:          %d\n", cnvt.length.hh);
    printf("h:           %d\n", cnvt.length.h);
    printf("l:           %d\n", cnvt.length.l);
    printf("ll:          %d\n", cnvt.length.ll);
    printf("L:           %d\n", cnvt.length.L);
    printf("field_width: %d\n", cnvt.fwidth);
    printf("precision:   %d\n", cnvt.prec);
    printf("conversion:  %c\n", cnvt.conv);
}

static void     get_flags(t_spdata *data, const char **fmt)
{
    if (!isinstr("#0-+ ", **fmt))
    {
        if (data->flg.dash)
            data->flg.zero = 0;
        if (data->flg.plus)
            data->flg.space = 0;
        return ;
    }
    if (**fmt == '#')
        data->flg.hash = 1;
    else if (**fmt == '0' )
        data->flg.zero = 1;
    else if (**fmt == '-')
        data->flg.dash = 1;
    else if (**fmt == '+')
        data->flg.plus = 1;
    else if (**fmt == ' ')
        data->flg.space = 1;
    (*fmt)++;
    get_flags(data, fmt);
}

static void     get_length(t_spdata *data, const char **fmt)
{
    while (isinstr("hlLzj", **fmt))
    {
        if (**fmt == 'L')
            data->length.L = 1;
        if (**fmt == 'j')
            data->length.j = 1;
        if (**fmt == 'z')
            data->length.z = 1;
        else if (**fmt == 'l')
        {
             if (*(*fmt + 1) == 'l')
             {
                (*fmt)++;
                data->length.ll = 1;
             }
             else
                data->length.l = 1;
        }
        else if (**fmt == 'h')
        {
             if (*(*fmt + 1) == 'h')
             {
                (*fmt)++;
                data->length.hh = 1;
             }
             else
                data->length.h = 1;
        }
        (*fmt)++;
    }
}

int             pf_convert(const char **fmt, va_list args)
{
    t_spdata data;

    ft_bzero(&data, sizeof(t_spdata));
    data.prec = -1;
    if (isinstr("#0-+ ", **fmt))
        get_flags(&data, fmt);
    data.fwidth = ft_atoi(*fmt);
    while (ft_isdigit(**fmt))
        (*fmt)++;
    if (**fmt == '.')
        data.prec = ft_atoi(++(*fmt));
    while (ft_isdigit(**fmt))
        (*fmt)++;
    if (isinstr("hlLzj", **fmt))
        get_length(&data, fmt);
    data.conv = **fmt;
    if (ft_strchr("SCDO", CONV))
        CONV = ft_tolower(CONV);
    return (pf_out(data, args));
}
