/*
** EPITECH PROJECT, 2024
** B-PSU-200-LYN-2-1-minishell1-marin.lagie
** File description:
** my_memset.c
*/
#include "projtester.h"

char *my_memset(char *str, char ch, int length)
{
    str = malloc(length);
    for (int i = 0; i < length; i++)
        str[i] = ch;
    return str;
}
