#include "jam.hpp"

void update_game(yin_yang_t *y)
{
    y->spritePosition_n.x += y->P_1_vx;
    y->sprite_n.setPosition(y->spritePosition_n);
    y->spritePosition_b.x += y->P_2_vx;
    y->sprite_b.setPosition(y->spritePosition_b);
    update_sprite_n(y);
    update_sprite_b(y);
    y->window.clear(sf::Color(128, 128, 128));
    for (int i = 0; i < y->builder.nb_bloc; i++)  
        y->window.draw(y->builder.bloc[i].bloc_s);
    for (int i = 0; i < y->nb_piece * 2; i++)  
        y->window.draw(y->p[i].piece_s);
    y->window.draw(y->sprite_n);
    y->window.draw(y->sprite_b);
    y->window.display();
}

void update_physique(yin_yang_t *y)
{
    if (!y->P_1isRightPressed && !y->P_1isLeftPressed) {
        if (y->P_1_vx < 1 && y->P_1_vx > -1 && y->P_1_vy == 0) {
            y->P_1_vx = 0;
        } else if (y->P_1_vx > 0) {
            y->P_1_vx -= 5;
        } else if (y->P_1_vx < 0)
            y->P_1_vx += 5;
    }
    if (!y->P_2isRightPressed && !y->P_2isLeftPressed) {
        if (y->P_2_vx < 1 && y->P_2_vx > -1 && y->P_2_vy == 0) {
            y->P_2_vx = 0;
        } else if (y->P_2_vx > 0) {
            y->P_2_vx -= 5;
        } else if (y->P_2_vx < 0)
            y->P_2_vx += 5;
    }
}
