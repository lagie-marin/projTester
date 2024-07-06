/*
** EPITECH PROJECT, 2023
** B-SYN-200-LYN-2-1-projtester-marin.lagie
** File description:
** scan.c
*/

#include "projtester.h"

static array_t process_file(char *path)
{
    FILE* file = fopen(path, "r");
    char *line = NULL;
    size_t len = 0;
    array_t data = NULL;

    if (file == NULL) {
        fprintf(stderr, "Unable to open file %s\n", path);
        return NULL;
    }
    while (my_getline(&line, &len, file) != -1)
        data = ra_array(data, line);
    FREE(line);
    fclose(file);
    return data;
}

static void process_path(char *path, mapper_t **head)
{
    struct stat path_stat;

    stat(path, &path_stat);
    if (S_ISREG(path_stat.st_mode))
        *head = insert_mapper(*head, strdup(path), process_file(path));
    else
        *head = insert_mapper(*head, strdup(path), NULL);
}

void scan(char *basePath, mapper_t **head)
{
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);

    if (!dir)
        return;
    for (dp = readdir(dir); dp != NULL; dp = readdir(dir)) {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) {
            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);
            process_path(path, head);
            scan(path, head);
        }
    }
    closedir(dir);
}
