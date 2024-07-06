/*
** EPITECH PROJECT, 2024
** B-SYN-200-LYN-2-1-projtester-marin.lagie
** File description:
** args.c
*/
#include "projtester.h"

static char *g_res(mapper_t *current)
{
    array_t data = current->data;
    char *res = NULL;
    int is_args = 0;

    if (!data)
        return NULL;
    for (int i = 0; data[i]; i++) {
        if ((strstr(data[i], "INPUT:") || strstr(data[i], "ARGS:")) && is_args)
            break;
        if (strstr(data[i], "RES:")) {
            res = strdup(&data[i][4]);
            is_args = 1;
        }
        if (is_args && !strstr(data[i], "RES:")) {
            res = realloc(res, strlen(res) + strlen(data[i]) + 1);
            strcat(res, data[i]);
        }
    }
    return res;
}

static array_t get_args(mapper_t *current, char *bft)
{
    array_t data = current->data;
    array_t args = NULL;
    int is_args = 0;

    for (int i = 0; data && data[i]; i++) {
        if (strstr(data[i], "INPUT:") || strstr(data[i], "RES:"))
            break;
        if (strstr(data[i], "ARGS:")) {
            args = my_str_to_word_array(&data[i][5], bft);
            is_args = 1;
        } else
            args = add_ar_in_ar(args, my_str_to_word_array(data[i], NULL));
    }
    if (is_args)
        return args;
    return my_str_to_word_array(NULL, bft);
}

static void setargs(projtester_t *projtester, mapper_t *cur, char *path)
{
    array_t element = my_strtok(path, '/');
    char *str;
    char *file;

    for (int i = 0; element[i]; i++) {
        if (strstr(element[i], ".tdf")) {
            file = get_file(projtester, cur);
            str = strtok(element[i], ".");
            write(FILES, str, strlen(str));
            write(FILES, ": ", 2);
            execute(projtester, get_args(cur, strdup(BFT)), g_res(cur), file);
        } else {
            write(FILES, "[", 1);
            write(FILES, element[i], strlen(element[i]));
            write(FILES, "] ", 2);
        }
    }
    free_strarray(element);
}

static char *get_path(projtester_t *projtester, mapper_t *current)
{
    char *name = current->name;

    if (name[0] == '.' && name[1] == '/')
        name = &name[2];
    if (strstr(name, basename(TRD)))
        return &name[strlen(TRD)];
    return name;
}

static void apply_args(projtester_t *projtester)
{
    struct stat path_stat;
    mapper_t *current = projtester->mappers;

    if (!current) {
        free_mapper(projtester);
        exit(0);
    }
    while (current) {
        stat(current->name, &path_stat);
        if (S_ISREG(path_stat.st_mode) && strstr(current->name, ".tdf"))
            setargs(projtester, current, get_path(projtester, current));
        current = current->next;
    }
}

int args(int ac, projtester_t *projtester)
{
    if (ac == 4) {
        FILES = open(OUTPUT, O_CREAT | O_APPEND | O_RDWR, 0664);
        if (FILES == -1) {
            free_mapper(projtester);
            exit(84);
        }
    }
    apply_args(projtester);
    if (ac == 4)
        close(FILES);
    return 0;
}
