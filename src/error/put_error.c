/*
** EPITECH PROJECT, 2023
** projTester
** File description:
** put_error.c
*/

#include "projtester.h"

int put_error(char *str)
{
    write(2, str, strlen(str));
    return 84;
}
