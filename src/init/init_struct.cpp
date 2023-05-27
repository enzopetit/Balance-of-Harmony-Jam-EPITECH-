/*
** EPITECH PROJECT, 2023
** init structure
** File description:
** init_struct
*/

#include "jam.hpp"
#include <cstddef>

int initializeStruct(yin_yang_t *y)
{
    y->m = new map_t;
    y->m->tab = NULL;
    return SUCCESS;
}
