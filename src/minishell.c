/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** functions
*/

#include "my.h"

char **my_env(char **env)
{
    int i = 0;
    char **myenv;

    while (env[i]) {
        if (env[i][0] == 'P' && env[i][3] == 'H') {
            if ((myenv = my_str_to_word_tab(env[i])) == NULL)
                return (NULL);
        }
        i++;
    }
    return (myenv);
}

int mysh(char **env, char **array)
{
    int	readed;
    char *line = NULL;
    size_t len = 0;
    char **arg;
    char *clean;
    int	res = 0;
    int a = 0;

    while ((readed = getline(&line, &len, stdin)) > 0) {
        clean = shell(line);
        a = check_exit(line);
        if (a == 84 || (arg = my_str_to_word_tab(clean)) == NULL)
            return (1);
        if ((res = print_command(arg, array, env, clean)) == 256)
            res = 1;
        mysh2(clean, arg, res);
        my_putstr("$> ");
    }
    return (res);
}

int print_command(char **av, char **map, char **env, char *buffer)
{
    char *str;
    int	i = 0;
    int	z = 0;
    pid_t pid;

    if ((pid = fork()) == 0)
        if (av[0] == '\0')
            exit (0);
    else {
        for (; map[i]; i++) {
            str = path(map[i], av[0]);
            execve(str, av, env);
        }
        if ((execve(av[0], av, env)) == -1)
            if ((no_foundcommand(map, av, i, buffer)) == 1)
                exit (0);
    }
    else if (pid != -1)
        z = wait_child(buffer);
    return (z);
}

int mysh2(char *clean, char **arg, int res)
{
    if ((print_cd(clean, arg)) == 84)
        res = 1;
    return (res);
}
