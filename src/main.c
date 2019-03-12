/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** main
*/

#include "my.h"

char **check_tab(char **tab, char *str)
{
    tab = malloc(sizeof(*tab) * ((nbofword(str) + 1)));

    if ((tab = malloc(sizeof(*tab) * ((nbofword(str) + 1)))) == NULL)
        return (84);
}

int no_foundcommand(char **array, char **arg, int i, char *buffer)
{
    char *strcd = "cd";

    if (array[i] == 0 && my_strcomp(strcd, buffer) == 0) {
        my_putstr(arg[0]);
        my_putstr(": Command not found.\n");
        return (1);
    }
    return (0);
}

int my_strcomp(char *str1, char *str2)
{
    int	i = 0;
    int	j = 0;

    for (; str2[j] != '\0'; j++)
        if (str1[i] == str2[j])
            i++;
    if (str1[i] == '\0' && str2[j] == '\0')
        return (1);
    else
        return (0);
}

char *path(char *array, char *av)
{
    int i = 0;
    int j = 0;
    char *str;
    str = malloc(sizeof(char) * my_strlen(array) + 1);

    if ((str = malloc(sizeof(char) * my_strlen(array) + 1)) == NULL)
        return (NULL);
    for (; array[i] != '\0'; i++)
        str[i] = array[i];
    str[i++] = '/';
    for (; av[j] != '\0'; i++, j++)
        str[i] = av[j];
    str[i] = '\0';
    return (str);
}

int	main(int ac, char **av, char **env)
{
    char **str;
    int my_return = 0;

    if (ac > 1)
        return (84);
    else {
        if (isatty(0))
            my_putstr("$> ");
        if ((str = my_env(env)) == NULL)
            return (84);
        my_return = mysh(env, str);
        if (my_return == 1)
            return (0);
    }
    return (0);
}
