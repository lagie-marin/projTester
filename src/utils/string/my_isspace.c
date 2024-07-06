/*
** EPITECH PROJECT, 2024
** B-PSU-200-LYN-2-1-minishell1-marin.lagie
** File description:
** my_isspace.c
*/
#include "projtester.h"

int my_isspace(char arg)
{
    if (arg == ' ' || (arg >= '\b' && arg <= '\r'))
        return 1;
    return 0;
}
