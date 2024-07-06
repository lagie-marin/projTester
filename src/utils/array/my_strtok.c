/*
** EPITECH PROJECT, 2024
** libs
** File description:
** my_strtok.c
*/
#include "projtester.h"

static int word_count(const char *c, cc_t delimiters)
{
    int count = 1;

    for (int i = 0; c[i]; i++)
        if ((c[i] == delimiters && i > 0 && c[i - 1] != delimiters) ||
            (c[i] == '\t' && c[i - 1] != '\t'))
            count++;
    return count;
}

static int len_word(const char *str, int i)
{
    int x = i;

    while (IS_CARACT(str[x]))
        x++;
    return x - i;
}

char **my_strtok(const char *str, cc_t delimiters)
{
    int nb_word = word_count(str, delimiters);
    char **word_array = malloc(sizeof(char *) * (nb_word + 1));
    int x = 0;
    int y = 0;
    int i = 0;

    for (; y < nb_word && nb_word > 0; y++) {
        word_array[y] = malloc(len_word(str, x) + 1);
        i = 0;
        while (str[x] == delimiters)
            x++;
        for (; str[x] && str[x] != delimiters; x++) {
            word_array[y][i] = str[x];
            word_array[y][i + 1] = '\0';
            i++;
        }
    }
    word_array[y] = NULL;
    return word_array;
}
