#include "../includes/ft_printf.h"

char    *ft_itoa_base(intmax_t value, int base)
{
	static      char rep[] = "0123456789abcdef";
    static      char buf[50];
    char        *ptr;
    intmax_t   num;

    ptr = &buf[49];
    *ptr = '\0';
    num = value;
    if (value == 0)
        *--ptr = rep[value % (intmax_t)base];
    while (value != 0)
    {
        *--ptr = rep[((value < 0) ? (-1) : (1)) * (value % (intmax_t)base)];
        value /= (intmax_t)base;
    }
    if (num < 0 && base == 10)
        *--ptr = '-';
    return (ptr);
}

char    *ft_itoa_base_uint(uintmax_t value, int base)
{
	static      char rep[] = "0123456789abcdef";
    static      char buf[50];
    char        *ptr;
    uintmax_t   num;

    ptr = &buf[49];
    *ptr = '\0';
    num = value;
    if (value == 0)
        *--ptr = rep[value % (uintmax_t)base];
    while (value != 0)
    {
        *--ptr = rep[value % (uintmax_t)base];
        value /= (uintmax_t)base;
    }
    return (ptr);
}

int     ft_max(int a, int b)
{
    if (a < b)
        return (b);
    return (a);
}

int     ft_putstrupper(char *str)
{
    int len;

    len = -1;
    while (str[++len])
        ft_putchar(ft_toupper(str[len]));
    return (len);
}

int		isinstr(const char *s, int c)
{
	int i;

	i = -1;
	while (s[++i])
		if (s[i] == c)
			return (1);
	return (0);
}

int     ft_putchar_len(char c)
{
    write(1, &c, 1);
    return (1);
}

int     ft_putstr_len(char *str)
{
    int len;

    len = ft_strlen(str);
    write(1, str, len);
    return (len);
}

int     ft_putnstr_len(char *str, int n)
{
    int len;

    len = -1;
    while (++len < n && str[len])
        write(1, &str[len], 1);
    return (len);
}

int     ft_padding(int i, char c)
{
    int count;

    count = i;
    if (i < 0)
        return (0);
    while (i--)
        ft_putchar(c);
    return (count);
}