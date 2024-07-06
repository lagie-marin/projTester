/*
** EPITECH PROJECT, 2023
** B-SYN-200-LYN-2-1-projtester-marin.lagie
** File description:
** arrays.c
*/
#include "projtester.h"

int str_arraylen(char **src)
{
    int len = 0;

    if (src == NULL)
        return 0;
    while (src[len])
        len++;
    return len;
}

char **ra_array(char **array, char *new_line)
{
    char **new = malloc((WA_LEN(array) + 2) * sizeof(char *));
    int i = 0;

    for (i = 0; array != NULL && array[i]; i++)
        new[i] = array[i];
    FREE(array);
    new[i] = new_line;
    new[i + 1] = NULL;
    return new;
}
