/*
** EPITECH PROJECT, 2023
** projects
** File description:
** sort2.c
*/

#include "stdlib.h"
#include "libshell/shell.h"
#include "my.h"

organized_t *fusionid(organized_t *gauche, organized_t *droite)
{
    fusion_t *fus = malloc(sizeof(fusion_t));

    fus->result = NULL;
    fus->tail = NULL;
    fus->temp = NULL;
    while (gauche != NULL && droite != NULL) {
        fus->temp = NULL;
        if (gauche->id <= droite->id) {
            fus->temp = gauche;
            gauche = gauche->next;
        } else {
            fus->temp = droite;
            droite = droite->next;
        }
        fus = resulttail(fus);
    }
    fus = finishresult(fus, gauche, droite);
    return fus->result;
}

fusion_t *resulttail(fusion_t *fus)
{
    if (fus->result == NULL) {
        fus->result = fus->temp;
        fus->tail = fus->temp;
    } else {
        fus->tail->next = fus->temp;
        fus->tail = fus->temp;
    }
    return fus;
}

fusion_t *finishresult(fusion_t *fus, organized_t *gauche, organized_t *droite)
{
    if (gauche != NULL) {
        if (fus->result == NULL) {
            fus->result = gauche;
        } else {
            fus->tail->next = gauche;
        }
    } else {
        if (fus->result == NULL) {
            fus->result = droite;
        } else {
            fus->tail->next = droite;
        }
    }
    return fus;
}

int conddelerror(int i, int j, char **args)
{
    if (args[i][j] < '0' || args[i][j] > '9') {
        return 84;
    } else {
        return 0;
    }
}
