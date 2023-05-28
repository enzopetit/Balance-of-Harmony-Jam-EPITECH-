#include "jam.hpp"

bool collisions_p2(yin_yang_t *y)
{
    y->spritePosition_b.y += y->P_2_vy;
    if (!y->jump_b) {
        y->cond_b = cond_stop_chute_2(y);
        y->stop_chute_b = true;
    } else
        y->cond_b = 0;
    if (y->cond_b != 0) {
        y->spritePosition_b.y = y->cond_b;
        y->P_2_vy = 0;
    } else if (y->spritePosition_b.y < 2000) {
        y->P_2_vy += 1;
    }
    if (y->spritePosition_b.y >= 2000) {
        y->lose = true;
        return true;
    }
    if (cond_stop_saut_2(y) != 0 && !y->stop_chute_b) {
        y->spritePosition_b.y += 30;
        y->P_2_vy = 0;
    }
    if (y->P_2_vy >= 0) {
        y->jump_b = false;
    }
    if (cond_stop_droite_2(y) != 0) {
        y->spritePosition_b.x -= 150;
        y->P_2_vy = 0;
    }
    if (cond_stop_gauche_2(y) != 0) {
        y->spritePosition_b.x += 150;
        y->P_2_vy = 0;
    }
    return false;
}

int cond_stop_chute_2(yin_yang_t *y)
{
    for (int i = 0; i < y->builder.nb_bloc; i++) {
        if (y->builder.bloc[i].coor_x - 60 <= y->spritePosition_b.y && y->builder.bloc[i].coor_x >= y->spritePosition_b.y &&
        y->builder.bloc[i].coor_y - 30 <= y->spritePosition_b.x && y->builder.bloc[i].coor_y + 30 >= y->spritePosition_b.x) {
            return y->builder.bloc[i].coor_x - 56;
        }
    }
    return 0;
}

int cond_stop_saut_2(yin_yang_t *y)
{
    for (int i = 0; i < y->builder.nb_bloc; i++) {
        if (y->builder.bloc[i].coor_x - 30 <= y->spritePosition_b.y && y->builder.bloc[i].coor_x >= y->spritePosition_b.y &&
        y->builder.bloc[i].coor_y - 30 <= y->spritePosition_b.x && y->builder.bloc[i].coor_y + 30 >= y->spritePosition_b.x) {
            return 1;
        }
    }
    return 0;
}

int cond_stop_droite_2(yin_yang_t *y)
{
    for (int i = 0; i < y->builder.nb_bloc; i++) {
        if (y->builder.bloc[i].coor_x - 50 <= y->spritePosition_b.y && y->builder.bloc[i].coor_x >= y->spritePosition_b.y &&
        y->builder.bloc[i].coor_y - 30 <= y->spritePosition_b.x && y->builder.bloc[i].coor_y >= y->spritePosition_b.x) {
            return 1;
        }
    }
    return 0;
}

int cond_stop_gauche_2(yin_yang_t *y)
{
    for (int i = 0; i < y->builder.nb_bloc; i++) {
        if (y->builder.bloc[i].coor_x - 50 <= y->spritePosition_b.y && y->builder.bloc[i].coor_x >= y->spritePosition_b.y &&
        y->builder.bloc[i].coor_y <= y->spritePosition_b.x && y->builder.bloc[i].coor_y + 30 >= y->spritePosition_b.x) {
            return 1;
        }
    }
    return 0;
}
