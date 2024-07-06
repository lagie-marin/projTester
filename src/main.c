/*
** EPITECH PROJECT, 2024
** projTester
** File description:
** main.c
*/
#include "projtester.h"

static void help(void)
{
    my_printf("USAGE\n\t./projTester TRD [BFT] [outputFile]\n\nDESCRIPTION\n");
    my_printf("\tTRD\t\troot directory of all the tests\n\tBFT\t\tbinary ");
    my_printf("file to be tested\n\toutputFile\tfile in which the result is ");
    my_printf("printed\n");
    exit(84);
}

static void display(projtester_t *projtester)
{
    mapper_t *mapper = projtester->mappers;

    my_printf("%s\n", basename(TRD));
    while (mapper) {
        for (int i = 0; i < count_char(mapper->name, '/'); i++)
            my_printf("-----");
        my_printf("%s\n", basename(mapper->name));
        mapper = mapper->next;
    }
}

int main(int ac, char **av)
{
    projtester_t projtester;

    if (ac < 2 || ac > 4)
        help();
    init(&projtester, ac, av);
    scan(projtester.config.trd, &projtester.mappers);
    sort_mapper(projtester.mappers);
    if (ac == 2)
        display(&projtester);
    else
        args(ac, &projtester);
    FREE(projtester.config.bft);
    free_mapper(&projtester);
    return 0;
}
/*
RES
*/
