/*
** EPITECH PROJECT, 2023
** projects
** File description:
** sort.c
*/

#include "stdlib.h"
#include "libshell/shell.h"
#include "my.h"

organized_t *fusion_gauche(organized_t *list, int diff)
{
    int mid = lenlistchaine(list) / 2;
    int gauche = 0;
    organized_t *fusgauche = NULL;
    organized_t *temp;

    while (gauche < mid) {
        temp = malloc(sizeof(organized_t));
        temp->name = list->name;
        temp->type = list->type;
        temp->id = list->id;
        temp->next = fusgauche;
        fusgauche = temp;
        list = list->next;
        gauche++;
    }
    return tri_fusion(fusgauche, diff);
}

organized_t *fusion_droite(organized_t *list, int diff)
{
    int mid = lenlistchaine(list) / 2;
    organized_t *fusdroite = NULL;
    organized_t *temp;

    for (int debut = 0; debut < mid; debut++)
        list = list->next;
    if (mid % 2 != 0)
        mid = mid + 1;
    while (list != NULL) {
        temp = malloc(sizeof(organized_t));
        temp->name = list->name;
        temp->type = list->type;
        temp->id = list->id;
        temp->next = fusdroite;
        fusdroite = temp;
        list = list->next;
        mid--;
    }
    return tri_fusion(fusdroite, diff);
}

organized_t *tri_fusion(organized_t *list, int diff)
{
    organized_t *fusgauche;
    organized_t *fusdroite;

    if (list == NULL || list->next == NULL)
        return list;
    fusgauche = fusion_gauche(list, diff);
    fusdroite = fusion_droite(list, diff);
    if (diff == 0)
        return fusionname(fusgauche, fusdroite);
    if (diff == 1)
        return fusiontype(fusgauche, fusdroite);
    if (diff == 2)
        return fusionid(fusgauche, fusdroite);
}

organized_t *fusionname(organized_t *gauche, organized_t *droite)
{
    fusion_t *fus = malloc(sizeof(fusion_t));

    fus->result = NULL;
    fus->tail = NULL;
    fus->temp = NULL;
    while (gauche != NULL && droite != NULL) {
        fus->temp = NULL;
        if (my_strcmp(gauche->name, droite->name) <= 0) {
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

organized_t *fusiontype(organized_t *gauche, organized_t *droite)
{
    fusion_t *fus = malloc(sizeof(fusion_t));

    fus->result = NULL;
    fus->tail = NULL;
    fus->temp = NULL;
    while (gauche != NULL && droite != NULL) {
        fus->temp = NULL;
        if (my_strcmp(gauche->type, droite->type) <= 0) {
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
