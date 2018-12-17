#include "../includes/ft_printf.h"
#include <limits.h>

int main()
{
    //ft_printf("\nmine: %d\n", ft_printf("%.4d", -424242));
    //printf("\nreal: %d\n", printf("%.4d", -424242));
    //ft_printf("\nmine: %d\n", ft_printf("@moulitest: %.10d", -42));
    //ft_printf("%#.O\n", 0);
    //printf("%#.O\n", 0);
    //ft_printf("\nmine: %d\n", ft_printf("{%-15Z}\n", 123));
    //printf("\nreal: %d\n", printf("{%-15Z}\n", 123));
    //ft_printf("{%-15Z}\n", 123);
    //printf("{%-15Z}\n", 123);
    ft_printf("%D\n", 12);
    printf("%D\n", 12);
    return (0);
}