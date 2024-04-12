/*
** EPITECH PROJECT, 2023
** projects
** File description:
** secured2.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int hash(char *key, int len)
{
    unsigned int bernstein = 6776;
    unsigned int hash_value = 0;
    int value = 0;
    unsigned int prime;

    for (int i = 0; i < len; i++) {
        hash_value = (((bernstein << 5) + bernstein) + key[i]);
        prime = hash_value % len;
        while (my_is_prime(prime) != 1)
            prime += 1;
        hash_value = hash_value * prime * (bernstein / len);
        if (i == 0) {
            value = hash_value * len;
        } else {
            value = (value * len) ^ hash_value;
        }
    }
    if (value < 0)
        value = value * -1;
    return value;
}

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *table = malloc(sizeof(hashtable_t));

    if (len < 1)
        return NULL;
    table->size = len;
    table->hash_function = hash;
    table->array = malloc(len * sizeof(element_t *));
    for (int i = 0; i < len; i++)
        table->array[i] = NULL;
    return table;
}

element_t *neweleminsert(hashtable_t *ht, int key_hash, char *value,
    element_t *new_elmt)
{
    new_elmt->value = my_strdup(value);
    new_elmt->key_hash = key_hash;
    new_elmt->next = ht->array[key_hash % ht->size];
    return new_elmt;
}
