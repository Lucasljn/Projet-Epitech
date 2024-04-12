/*
** EPITECH PROJECT, 2023
** projects
** File description:
** secured2.c
*/

#include "my.h"

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    unsigned int key_hash;
    int index;
    element_t *current = NULL;
    element_t *new_elmt = malloc(sizeof(element_t));

    if (ht == NULL || key == NULL || value == NULL)
        return 84;
    key_hash = ht->hash_function(key, my_strlen(key));
    index = key_hash % ht->size;
    current = ht->array[index];
    while (current != NULL) {
        if (current->key_hash == key_hash) {
            my_strcpy(current->value, value);
            return 0;
        }
        current = current->next;
    }
    new_elmt = neweleminsert(ht, key_hash, value, new_elmt);
    ht->array[index] = new_elmt;
    return 0;
}

static int ht_delete_2(element_t *previous, element_t *current)
{
    if (current != NULL) {
        previous->next = current->next;
        free(current);
        return 0;
    }
    return 84;
}

int ht_delete(hashtable_t *ht, char *key)
{
    int key_hash;
    int index;
    element_t *previous = NULL;
    element_t *current = NULL;

    if (ht == NULL || key == NULL || ht_search(ht, key) == NULL)
        return 84;
    key_hash = ht->hash_function(key, my_strlen(key));
    index = key_hash % ht->size;
    current = ht->array[index];
    if (current->key_hash == key_hash) {
        ht->array[index] = current->next;
        free(current);
        return 0;
    }
    while (current != NULL && current->key_hash != key_hash) {
        previous = current;
        current = current->next;
    }
    return ht_delete_2(previous, current);
}

char *ht_search(hashtable_t *ht, char *key)
{
    int index;
    int key_hash;
    element_t *current = NULL;

    if (ht == NULL || key == NULL)
        return NULL;
    key_hash = ht->hash_function(key, my_strlen(key));
    index = key_hash % ht->size;
    current = ht->array[index];
    while (current != NULL) {
        if (current->key_hash == key_hash)
            return current->value;
        current = current->next;
    }
    return NULL;
}

void ht_dump(hashtable_t *ht)
{
    element_t *current = NULL;

    for (int i = 0; i < ht->size; i++) {
        current = ht->array[i];
        my_printf("[%d]:\n", i);
        while (current != NULL) {
            my_printf("> %d - %s\n", current->key_hash, current->value);
            current = current->next;
        }
    }
}

void delete_hashtable(hashtable_t *ht)
{
    element_t *current = NULL;
    element_t *tmp = NULL;

    for (int i = 0; i < ht->size; i++) {
        current = ht->array[i];
        while (current != NULL) {
            tmp = current;
            current = current->next;
            free(tmp);
        }
    }
    free(ht);
}
