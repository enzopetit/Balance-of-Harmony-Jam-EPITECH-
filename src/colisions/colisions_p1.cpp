#include "jam.hpp"

bool collisions_p1(yin_yang_t *y)
{
    y->spritePosition_n.y += y->P_1_vy;
    if (!y->jump_n) {
        y->cond_n = cond_stop_chute(y);
        y->stop_chute_n = true;
    } else
        y->cond_n = 0;
    if (y->cond_n != 0) {
        y->spritePosition_n.y = y->cond_n;
        y->P_1_vy = 0;
    } else if (y->spritePosition_n.y < 2000) {
        y->P_1_vy += 1;
    }
    if (y->spritePosition_n.y >= 2000) {
        y->lose = true;
        return true;
    }
    if (cond_stop_saut(y) != 0 && !y->stop_chute_n) {
        y->spritePosition_n.y += 30;
        y->P_1_vy = 0;
    }
    if (y->P_1_vy >= 0) {
        y->jump_n = false;
    }
    if (cond_stop_droite(y) != 0) {
        y->spritePosition_n.x -= 150;
        y->P_1_vy = 0;
    }
    if (cond_stop_gauche(y) != 0) {
        y->spritePosition_n.x += 150;
        y->P_1_vy = 0;
    }
    return false;
}

int cond_stop_chute(yin_yang_t *y)
{
    for (int i = 0; i < y->builder.nb_bloc; i++) {
        if (y->builder.bloc[i].coor_x - 60 <= y->spritePosition_n.y && y->builder.bloc[i].coor_x >= y->spritePosition_n.y &&
        y->builder.bloc[i].coor_y - 30 <= y->spritePosition_n.x && y->builder.bloc[i].coor_y + 30 >= y->spritePosition_n.x) {
            return y->builder.bloc[i].coor_x - 56;
        }
    }
    return 0;
}

int cond_stop_saut(yin_yang_t *y)
{
    for (int i = 0; i < y->builder.nb_bloc; i++) {
        if (y->builder.bloc[i].coor_x - 30 <= y->spritePosition_n.y && y->builder.bloc[i].coor_x >= y->spritePosition_n.y &&
        y->builder.bloc[i].coor_y - 30 <= y->spritePosition_n.x && y->builder.bloc[i].coor_y + 30 >= y->spritePosition_n.x) {
            return 1;
        }
    }
    return 0;
}

int cond_stop_droite(yin_yang_t *y)
{
    for (int i = 0; i < y->builder.nb_bloc; i++) {
        if (y->builder.bloc[i].coor_x - 50 <= y->spritePosition_n.y && y->builder.bloc[i].coor_x >= y->spritePosition_n.y &&
        y->builder.bloc[i].coor_y - 30 <= y->spritePosition_n.x && y->builder.bloc[i].coor_y >= y->spritePosition_n.x) {
            return 1;
        }
    }
    return 0;
}

int cond_stop_gauche(yin_yang_t *y)
{
    for (int i = 0; i < y->builder.nb_bloc; i++) {
        if (y->builder.bloc[i].coor_x - 50 <= y->spritePosition_n.y && y->builder.bloc[i].coor_x >= y->spritePosition_n.y &&
        y->builder.bloc[i].coor_y <= y->spritePosition_n.x && y->builder.bloc[i].coor_y + 30 >= y->spritePosition_n.x) {
            return 1;
        }
    }
    return 0;
}
