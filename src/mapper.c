/*
** EPITECH PROJECT, 2024
** B-SYN-200-LYN-2-1-projtester-marin.lagie
** File description:
** mapper.c
*/
#include "projtester.h"

static void swap_mapper(mapper_t *current, mapper_t *next)
{
    char *temp_name;
    char **temp_data;

    temp_name = current->name;
    current->name = next->name;
    next->name = temp_name;
    temp_data = current->data;
    current->data = next->data;
    next->data = temp_data;
}

void free_mapper(projtester_t *projtester)
{
    mapper_t *next;
    mapper_t *head = projtester->mappers;

    while (head) {
        next = head->next;
        FREE(head->name);
        free_strarray(head->data);
        FREE(head);
        head = next;
    }
}

mapper_t *create_mapper(char *path, char **data)
{
    mapper_t *mapper = malloc(sizeof(mapper_t));

    if (!mapper)
        exit(84);
    mapper->name = path;
    mapper->data = data;
    mapper->next = NULL;
    return mapper;
}

mapper_t *insert_mapper(mapper_t *head, char *path, char **data)
{
    mapper_t *mapper = create_mapper(path, data);

    mapper->next = head;
    return mapper;
}

void sort_mapper(mapper_t *head)
{
    mapper_t *current = head;
    int n_sort = 0;

    if (!current)
        return;
    while (current && current->next) {
        if (strcmp(current->name, current->next->name) > 0) {
            swap_mapper(current, current->next);
            n_sort = 1;
        }
        current = current->next;
    }
    if (n_sort)
        sort_mapper(head);
}
