/*
** EPITECH PROJECT, 2023
** B-SYN-200-LYN-2-1-projtester-marin.lagie
** File description:
** my_getline.c
*/
#include "projtester.h"

int get_nb_line(FILE *fp)
{
    char c;
    int len = 0;

    if (fp == NULL)
        return 0;
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n')
            len++;
    return len;
}

ssize_t my_getline(array_t input, size_t *len, FILE *stream)
{
    ssize_t bytes = 0;

    *input = NULL;
    bytes = getline(input, len, stream);
    if (*input != NULL && bytes != -1)
        (*input)[bytes] = '\0';
    return bytes;
}
