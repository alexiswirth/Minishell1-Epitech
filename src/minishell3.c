/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** functions3
*/

#include "my.h"

char *shell(char *str)
{
    int	i = 0;
    int	j = 0;
    char *str2;
    str2 = malloc(sizeof(char) * my_strlen(str) + 1);

    for (;str[i] == ' ' || str[i] == '\t'; i++);
    for (; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\t') {
            str2[j] = str[i];
            j++;
            if (str[i + 1] == ' ' || str[i + 1] == '\t') {
                str2[j] = ' ';
            j++;
            }
        }
    }
    str2[j] = '\0';
    if (j > 1 && str2[j - 1] == ' ')
        str2[j - 1] = '\0';
    return (str2);
}

int wait_child(char *str)
{
    int	wait_status;
    wait(&wait_status);
    char *strcd = "cd";

    if (WIFSIGNALED(wait_status)) {
        if (WTERMSIG(wait_status) == 11) {
            my_putstr("Segmentation fault (core dumped)\n");
            wait_status = 139;
        }
    }
    if ((my_strcomp(strcd, str)) == 1)
        return (0);
    else
        return (wait_status);
}

int check_exit(char *line)
{
    char *strexit = "exit";

    if ((my_strcomp(strexit, line)) == 1)
        return (84);
}

int nbofword(char *str)
{
    int j = 1;

    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        if (str[i] == ':' && str[i + 1] != '\0')
            j++;
        else if (str[i] == ' ' && str[i + 1] != '\0')
            j++;
    }
    return (j);
}

int delete_space(char *str, int nb)
{
    int	j = nb;

    for (;str[j] == ' ' || str[j] == ':'; j++);
    return (j);
}
