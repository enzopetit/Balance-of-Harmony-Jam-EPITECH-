#include "jam.hpp"

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
        if (y->builder.bloc[i].coor_x - 60 <= y->spritePosition_n.y && y->builder.bloc[i].coor_x >= y->spritePosition_n.y &&
        y->builder.bloc[i].coor_y - 30 <= y->spritePosition_n.x && y->builder.bloc[i].coor_y >= y->spritePosition_n.x) {
            printf("smash a droite\n");
            return 1;
        }
    }
    return 0;
}

int cond_stop_gauche(yin_yang_t *y)
{
    for (int i = 0; i < y->builder.nb_bloc; i++) {
        if (y->builder.bloc[i].coor_x - 30 <= y->spritePosition_n.y && y->builder.bloc[i].coor_x >= y->spritePosition_n.y &&
        y->builder.bloc[i].coor_y - 30 <= y->spritePosition_n.x && y->builder.bloc[i].coor_y + 30 >= y->spritePosition_n.x) {
            printf("smash a gauche\n");
            return 1;
        }
    }
    return 0;
}
