/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myradar-marin.lagie
** File description:
** my_str_to_word_array.c
*/

#include "projtester.h"

static int word_count(const char *str)
{
    int count = 0;

    if (!str)
        return 0;
    for (int i = 0; str[i]; i++)
        if (IS_CARACT(str[i]) && !IS_CARACT(str[i + 1]))
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

char **my_str_to_word_array(const char *str, char *bft)
{
    int nb_word = word_count(str) + (bft == NULL ? 0 : 1);
    char **word_array = malloc(sizeof(char *) * (nb_word + 2));
    int x = 0;
    int y = bft == NULL ? 0 : 1;
    int i = 0;

    if (bft)
        word_array[0] = bft;
    for (; y < nb_word && nb_word > 0 && str; y++) {
        while (my_isspace(str[x]))
            x++;
        word_array[y] = my_memset(word_array[y], '\0', len_word(str, x) + 1);
        for (i = 0; str[x] != '\0' && IS_CARACT(str[x]); x++) {
            word_array[y][i] = str[x];
            word_array[y][i + 1] = '\0';
            i++;
        }
    }
    word_array[nb_word] = NULL;
    return word_array;
}
