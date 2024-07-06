/*
** EPITECH PROJECT, 2024
** projTester
** File description:
** projtester.h
*/
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <libgen.h>
#include <stdarg.h>
#include <fcntl.h>

#ifndef PROJTESTER_H
    #define PROJTESTER_H
    #define TRD projtester->config.trd
    #define BFT projtester->config.bft
    #define OUTPUT projtester->config.output
    #define FILES projtester->file
    #define FREE(str) if (str != NULL) free(str)
    #define MY_GETLINE my_getline(&line, &len, fp)
    #define WA_LEN(array) str_arraylen(array)
    #define IS_CARACT(ch) (ch >= '!' && ch <= '~' && !my_isspace(ch))
    #define ACCESS(str) access(str, F_OK)
    #define EXECUTION(str) access(str, X_OK)
    #define CHECK_COMMANDE(ac, projtester) if (ac >= 3) check_cmd(projtester)

typedef struct projtester_s projtester_t;
typedef struct config_s config_t;
typedef struct mapper_s mapper_t;
typedef char **array_t;
typedef const char cc_t;

struct config_s {
    char *trd;
    char *bft;
    char *output;
};

struct mapper_s {
    char *name;
    array_t data;
    mapper_t *next;
};

struct projtester_s {
    config_t config;
    mapper_t *mappers;
    struct dirent *d;
    int file;
};

void init(projtester_t *projtester, int ac, char **av);
void scan(char *basePath, mapper_t **head);
int put_error(char *str);
ssize_t my_getline(array_t input, size_t *len, FILE *stream);
char **ra_array(char **array, char *new_line);
int str_arraylen(char **src);
int free_strarray(char **array);
int get_nb_line(FILE *fp);

mapper_t *create_mapper(char *path, char **data);
mapper_t *insert_mapper(mapper_t *head, char *path, char **data);
void free_mapper(projtester_t *projtester);
void sort_mapper(mapper_t *head);
int count_char(char *str, char subject);
int args(int ac, projtester_t *projtester);
int my_isspace(char arg);
char **my_strtok(const char *str, cc_t delimiters);
int my_printf(const char *format, ...);
char **my_str_to_word_array(const char *str, char *bft);
void execute(projtester_t *projt, array_t args, char *res, char *file);
char *my_memset(char *str, char ch, int length);
void error(projtester_t *projtester, array_t args);
char *get_file(projtester_t *projtester, mapper_t *current);
char *get_path_exec(char *file);
array_t add_ar_in_ar(array_t array1, array_t array2);
void check_cmd(projtester_t *projtester);
#endif
