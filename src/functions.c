/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** functions
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_getnbr(char *str)
{
    int result = 0;
    int neg = (*str == '-') ? 1 && str++ : 0;

    for (; *str >= 48 && *str <= 57; str++)
        result = (result * 10) + (*str - 48);
    return (neg ? -result : result);
}

char *my_putstr(char *str)
{
    int i = 0;

    for (;str[i] != '\0'; i++)
        my_putchar(str[i]);
    return (str);
}

int my_put_nbr(int n)
{
    if (n < 0) {
        my_putchar('-');
        n = -n;
    }
    if (n >= 10) {
        my_put_nbr(n / 10);
        my_putchar(n % 10 + '0');
    }
    if (n < 10)
        my_putchar(n % 10 + '0');
    return (n);
}

int my_strlen(char *str)
{
    int	i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}
