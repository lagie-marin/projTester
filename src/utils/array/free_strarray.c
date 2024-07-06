/*
** EPITECH PROJECT, 2023
** B-SYN-200-LYN-2-1-projtester-marin.lagie
** File description:
** free_strarray.c
*/
#include "projtester.h"

int free_strarray(char **array)
{
    if (array == NULL)
        return 1;
    for (int i = 0; array[i] != NULL; i++)
        FREE(array[i]);
    FREE(array);
    return 1;
}
