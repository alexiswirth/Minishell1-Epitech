/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** functions2
*/

#include "my.h"

char **strtwt2(char **tab, int j)
{
    j++;
    tab[j] = '\0';
    return (tab);
}

char **my_str_to_word_tab(char *s)
{
    char **tab = check_tab(tab, s);
    int	i = 0;
    int	j = 0;
    int	z = 0;

    if (tab == 84)
        return (NULL);
    while (s[i] != '\n' && s[i] != '\0') {
        if (s[i] == ' ' || s[i] == ':' ) {
            i = delete_space(s, i);
            j++;
            z = 0;
        }
        if ((tab[j] = malloc(sizeof(char) * (my_strlen(s + i)))) == NULL)
            return (NULL);
        while (s[i] != ':' && s[i] != ' ' && s[i] != '\n' && s[i] != '\0')
            tab[j][z++] = s[i++];
    }
    tab = strtwt2(tab, j);
    return (tab);
}

void print_cd2(char **av)
{
    my_putstr("cd: no such file or directory: ");
    my_putstr(av[1]);
    my_putchar('\n');
}

void print_cd3(char **av)
{
    my_putstr("cd: not a directory: ");
    my_putstr(av[1]);
    my_putchar('\n');
}

int	print_cd(char *path, char **av)
{
    char *strcd = "cd";

    if ((my_strcomp(strcd, path)) == 1) {
        if (av[1] != '\0') {
            if (access(av[1], F_OK) == -1) {
                print_cd2(av);
                return (84);
            }
            else if (access(av[1], X_OK) == -1) {
                print_cd3(av);
                return (84);
            }
            if ((chdir(av[1])) == -1) {
                print_cd3(av);
                return (84);
            }
        }
    }
    return (0);
}