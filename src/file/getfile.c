/*
** EPITECH PROJECT, 2024
** B-SYN-200-LYN-2-1-projtester-marin.lagie
** File description:
** getfile.c
*/
#include "projtester.h"

static char *g_file(array_t data)
{
    if (!data)
        return NULL;
    for (int i = 0; data[i]; i++)
        if (strstr(data[i], "INPUT:"))
            return &data[i][6];
    return NULL;
}

static char *g_path(projtester_t *projtester, char *file)
{
    mapper_t *mapper;

    if (!file)
        return NULL;
    for (mapper = projtester->mappers; mapper; mapper = mapper->next)
        if (!strcmp(file, basename(mapper->name)))
            return mapper->name;
    return NULL;
}

static char *g_path_by_env(char *file)
{
    char *path_env = getenv("PATH");
    char *token = strtok(path_env, ":");
    char *possible_path;

    while (token) {
        possible_path = malloc(strlen(token) + strlen(file) + 2);
        strcpy(possible_path, token);
        strcat(possible_path, "/");
        strcat(possible_path, file);
        if (access(possible_path, F_OK) != -1)
            return possible_path;
        free(possible_path);
        token = strtok(NULL, ":");
    }
    return NULL;
}

char *get_path_exec(char *file)
{
    if (!ACCESS(file))
        return strdup(file);
    return g_path_by_env(file);
}

char *get_file(projtester_t *projtester, mapper_t *current)
{
    array_t data = current->data;
    char *file = g_file(data);
    char *path = g_path(projtester, file);

    if (path != NULL)
        return path;
    if (file != NULL && !path) {
        path = g_path_by_env(file);
        if (!path) {
            free(path);
            error(projtester, NULL);
        }
        return path;
    }
    return NULL;
}
