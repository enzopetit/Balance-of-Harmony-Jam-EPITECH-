/*
** EPITECH PROJECT, 2023
** box's collisions
** File description:
** box_collisions
*/

#include "jam.hpp"

static int BoxCollisions(yin_yang_t *ying)
{
    if (ying->m->player.x == ying->m->current_pos.x && ying->m->player.y == ying->m->current_pos.y) {
        return SUCCESS;
    }
    return CLEAR;
}

bool MainBoxCollisions(yin_yang_t *ying)
{
    bool ReturnedBoolean = false;

    if (BoxCollisions(ying) == SUCCESS) {
        printf("Box hit!\n");
        ReturnedBoolean = true;
        return ReturnedBoolean;
    } else {
        ReturnedBoolean = false;
        return ReturnedBoolean;
    }
}
