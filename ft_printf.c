#include "ft_printf.h"
#include "stdio.h"


static int	ft_conversion(const char type, va_list vargs)
{
	if (type == 'c')
		return (ft_putchar(va_arg(vargs, int)));
	else if (type == 'u')
		return (ft_putnbr(va_arg(vargs, unsigned int)));
	else if ((type == 'i') || (type == 'd'))
		return (ft_putnbr(va_arg(vargs, int)));
	else if (type == 's')
		return (ft_putstr(va_arg(vargs, char *)));
	else if (type == 'x' || type == 'X')
		return (ft_putnbr_hexa(va_arg(vargs, unsigned int), type));
	else if (type == 'p')
		return (ft_putptr(va_arg(vargs, void *)));
	else if (type == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(char const *str, ...)
{
	va_list	vargs;
	int		len;
	int		check;

	va_start(vargs, str);
	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			check = ft_conversion(*(++str), vargs);
			if (check == -1)
				return (-1);
			len += check;
		}
		else
		{
			if (write(1, str, 1) == -1)
				return (-1);
			len++;
		}
		str++;
	}
	va_end(vargs);
	return (len);
}
int main()
{
    ft_printf("Hello, world!\n");

    int number = 42;
    ft_printf("Číslo: %d\n", number);
    
    double decimal = 3.14159;
    ft_printf("Desetinné číslo: %.2f\n", decimal);
    
    char character = 'A';
    ft_printf("Znak: %c\n", character);
    
    printf("Hello, world!\n");
    
    int number2 = 42;
    printf("Číslo: %d\n", number2);

    double decimal2 = 3.14159;
    printf("Desetinné číslo: %.2f\n", decimal2);
    
    char character2 = 'A';
    printf("Znak: %c\n", character2);
    
    return 0;
}