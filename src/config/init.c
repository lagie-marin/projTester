/*
** EPITECH PROJECT, 2024
** projTester
** File description:
** init.c
*/
#include "projtester.h"

void check_cmd(projtester_t *projtester)
{
    if (!BFT) {
        FREE(BFT);
        exit(84);
    }
}

void init(projtester_t *projtester, int ac, char **av)
{
    struct stat s;

    if (stat(av[1], &s) == -1 || !S_ISDIR(s.st_mode))
        exit(84);
    if (ac == 2) {
        TRD = av[1];
        BFT = NULL;
        OUTPUT = NULL;
    } else if (ac == 3) {
        TRD = av[1];
        BFT = get_path_exec(av[2]);
        OUTPUT = NULL;
    } else {
        TRD = av[1];
        BFT = get_path_exec(av[2]);
        OUTPUT = av[3];
    }
    CHECK_COMMANDE(ac, projtester);
    projtester->file = 1;
    projtester->mappers = NULL;
}
