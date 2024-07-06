/*
** EPITECH PROJECT, 2024
** B-SYN-200-LYN-2-1-projtester-marin.lagie
** File description:
** count_char.c
*/

int count_char(char *str, char subject)
{
    int count = 0;

    if (str[0] == '.' && str[1] == '/')
        str = &str[2];
    for (int i = 0; str[i]; i++)
        if (str[i] == subject && str[i - 1] != subject)
            count++;
    return count;
}
