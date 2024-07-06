/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-alexis.drago-beltran
** File description:
** my_printf.c
*/

#include "projtester.h"

static void my_putchar(char c)
{
    write(1, &c, 1);
}

static int my_putstr(char const *str)
{
    if (str[0] == '\0')
        return (0);
    write(1, str, strlen(str));
    return (0);
}

static int my_put_nbr(int n)
{
    if (n == -2147483648) {
        my_putstr("-2147483648");
        return 0;
    }
    if (n < 0) {
        my_putchar('-');
        n = -n;
    }
    if (n >= 10)
        my_put_nbr(n / 10);
    my_putchar(n % 10 + '0');
    return 0;
}

static void print(char c, va_list ap)
{
    if (c == 'c')
        my_putchar((int)va_arg(ap, int));
    if (c == 's')
        my_putstr(va_arg(ap, char *));
    if (c == '%')
        my_putchar('%');
    if (c == 'd' || c == 'i')
        my_put_nbr((int)va_arg(ap, int));
}

int my_printf(const char *format, ...)
{
    va_list ap;

    va_start(ap, format);
    for (int i = 0; format[i]; i++) {
        if (format[i] == '%') {
            i++;
            print(format[i], ap);
        } else
            my_putchar(format[i]);
    }
    va_end(ap);
    return 0;
}
