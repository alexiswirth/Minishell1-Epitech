/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** myh
*/

#include <sys/types.h> 
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include <assert.h>
#define _GNU_SOURCE
#include <sys/wait.h>
#include <termios.h>
#include <ncurses.h>
#include <signal.h>
#include <dirent.h>
#include <time.h>

#define READ_SIZE 3200

#ifndef __pid_t_defined
typedef __pid_t pid_t;
# define __pid_t_defined
#endif

#ifndef _MY_H_
#define _MY_H_
void my_putchar(char c);
char *my_putstr(char *str);
int my_put_nbr(int n);
int	my_strlen(char *str);
int	no_foundcommand(char **array, char **arg, int i, char *buffer);
int my_getnbr(char *str);
int	my_strcomp(char *s1, char *s2);
int	delete_space(char *str, int i);
char *shell(char *str);
int	print_cd(char *path, char **arg);
int	wait_child(char *str);
int	print_command(char **arg, char **array, char **env, char *buffer);
int	mysh(char **env, char **array);
int	nbofword(char *str);
int	remove_space_double(char *str, int i);
char **my_str_to_word_tab(char *str);
int	main(int ac, char **av, char **env);
char **my_env(char **env);
int check_exit(char *line);
int	nbofword(char *str);
int mysh2(char *clean, char **arg, int res);
char *path(char *array, char *av);
char **check_tab(char **tab, char *str);

#endif