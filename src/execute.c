/*
** EPITECH PROJECT, 2024
** B-SYN-200-LYN-2-1-projtester-marin.lagie
** File description:
** execute.c
*/
#include "projtester.h"

void error(projtester_t *projtester, array_t args)
{
    free_mapper(projtester);
    free_strarray(args);
    exit(84);
}

static int create_fork(projtester_t *projtester, array_t args)
{
    int pid = fork();

    if (pid == -1)
        error(projtester, args);
    return pid;
}

static void execute_command(array_t args, int *pf, char *cmd, char *file)
{
    int fd;

    if (file != NULL) {
        fd = open(file, O_RDONLY);
        if (fd == -1 && free_strarray(args))
            exit(84);
        dup2(fd, STDIN_FILENO);
        close(fd);
    }
    close(pf[0]);
    dup2(pf[1], STDOUT_FILENO);
    close(pf[1]);
    execve(cmd, args, NULL);
    perror("execvp");
    exit(EXIT_FAILURE);
}

static void check_args(projtester_t *projtester, int *pf, char *res)
{
    char buffer[1024];
    ssize_t bytes_read;

    close(pf[1]);
    bytes_read = read(pf[0], buffer, sizeof(buffer) - 1);
    buffer[bytes_read] = '\0';
    if (!res)
        write(FILES, buffer, strlen(buffer));
    else if (strcmp(buffer, res))
        write(FILES, "KO\n", 3);
    else
        write(FILES, "OK\n", 3);
    close(pf[0]);
    wait(NULL);
}

void execute(projtester_t *projt, array_t args, char *res, char *file)
{
    int pf[2];
    pid_t pid;

    if (pipe(pf) == -1)
        error(projt, args);
    pid = create_fork(projt, args);
    if (pid == 0)
        execute_command(args, pf, projt->config.bft, file);
    else
        check_args(projt, pf, res);
    if (file)
        write(projt->file, "\n", 1);
    FREE(res);
    free_strarray(args);
}
