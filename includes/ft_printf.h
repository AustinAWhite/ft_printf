#ifndef _FT_PRINTF_H
#define _FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include "../libft/libft.h"
#define HASH data.flg.hash
#define ZERO data.flg.zero
#define DASH data.flg.dash
#define PLUS data.flg.plus
#define SPACE data.flg.space
#define CONV data.conv


#include <stdio.h>

/*
 * %[flags][width][.precision][length]specifier 
 * https://en.wikipedia.org/wiki/Printf_format_string
 */

typedef struct  s_flags
{
    int         hash;
    int         zero;
    int         dash;
    int         plus;
    int         space;
}               t_flags;

typedef struct  s_length
{
    int         hh;
    int         h;
    int         l;
    int         ll;
    int         j;
    int         z;
    int         L;
}               t_length;

typedef struct  s_spdata
{
    t_flags     flg;
    int         fwidth;
    int         prec;
    t_length    length;
    char        conv;
}               t_spdata;

int             ft_printf(const char *fmt, ...);
int             pf_convert(const char **fmt, va_list args);
int             pf_out(t_spdata data, va_list args);

char            *ft_itoa_base(intmax_t value, int base);
char            *ft_itoa_base_uint(uintmax_t value, int base);
int             ft_putstrupper(char *str);
int		        isinstr(const char *s, int c);
int             ft_putchar_len(char c);
int             ft_putstr_len(char *str);
int             ft_max(int a, int b);
int             ft_padding(int i, char c);
int             ft_putnstr_len(char *str, int n);

int             handle_int(t_spdata data, va_list args, int base);
int             handle_uint(t_spdata data, va_list args, int base);
int             handle_s(t_spdata data, char *str);
int             handle_c(t_spdata data, char c);

int             pf_print_out(t_spdata data, char *val);

#endif