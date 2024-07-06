/*
** EPITECH PROJECT, 2024
** projTester
** File description:
** requirement.c
*/

#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void my_ps_synthesis(void)
{
    char *args[2] = {"ps", NULL};
    pid_t pid = fork();
    int s;

    if (pid == -1)
        exit(84);
    if (pid == 0)
        execve("/bin/ps", args, NULL);
    else
        wait(&s);
}
