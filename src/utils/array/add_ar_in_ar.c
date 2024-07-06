/*
** EPITECH PROJECT, 2024
** B-SYN-200-LYN-2-1-projtester-marin.lagie
** File description:
** add_ar_in_ar.c
*/
#include "projtester.h"

array_t add_ar_in_ar(array_t array1, array_t array2)
{
    int len = str_arraylen(array2);
    array_t new = NULL;
    int i = 0;

    if (!array2)
        return array1;
    new = malloc((str_arraylen(array1) + len + 1) * sizeof(char *));
    if (!new)
        return NULL;
    for (i = 0; array1[i]; i++)
        new[i] = array1[i];
    for (int x = 0; array2[x]; x++) {
        new[i] = array2[x];
        i++;
    }
    new[i] = NULL;
    return new;
}
