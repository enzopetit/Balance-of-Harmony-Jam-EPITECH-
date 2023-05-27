#include "jam.hpp"

void load_personnages(yin_yang_t *y)
{
    if (!y->texture_n.loadFromFile("assets/perso_noir.png")) {
        return;
    }
    y->sprite_n.setTexture(y->texture_n);
    y->sprite_n.setTextureRect(sf::IntRect(0, 0, 17, 28));
    y->sprite_n.setScale(2.0f, 2.0f);
    y->spritePosition_n = y->sprite_n.getPosition();
    y->spritePosition_n.y = 900;
    y->spritePosition_n.x = 1800;
    y->sprite_n.setPosition(y->spritePosition_n);
}

void init_page(yin_yang_t *y)
{
    load_personnages(y);
    make_map("map/map_1.txt", y);
    while (y->window.isOpen()) {
        get_keyboard_event(y);
        if (!y->P_1isRightPressed && !y->P_1isLeftPressed) {
            if (y->P_1_vx < 1 && y->P_1_vx > -1 && y->P_1_vy == 0) {
                y->P_1_vx = 0;
            } else if (y->P_1_vx > 0) {
                y->P_1_vx -= 5;
            } else if (y->P_1_vx < 0)
                y->P_1_vx += 5;
        }
        y->spritePosition_n.y += y->P_1_vy;
        if (!y->jump)
            y->cond = cond_stop_chute(y);
        else
            y->cond = 0;
        if (y->cond != 0) {
            y->spritePosition_n.y = y->cond;
            y->P_1_vy = 0;
        } else if (y->spritePosition_n.y < 2000) {
            y->P_1_vy += 1;
        }
        if (y->spritePosition_n.y >= 2000) {
            y->lose = true;
            break;
        }
        if (cond_stop_saut(y) != 0) {
            y->spritePosition_n.y -= y->P_1_vy;
            y->P_1_vy = 0;
        }
        if (y->P_1_vy >= 0) {
            y->jump = false;
        }

        if (cond_stop_droite(y) != 0) {
            y->spritePosition_n.y -= y->P_1_vy * 3;
            y->P_1_vy = 0;
        }

        y->spritePosition_n.x += y->P_1_vx;
        y->sprite_n.setPosition(y->spritePosition_n);

        y->window.clear(sf::Color(128, 128, 128));
        y->window.draw(y->sprite_n);
        for (int i = 0; i < y->builder.nb_bloc; i++) {
            y->window.draw(y->builder.bloc[i].bloc_s);
        }
        y->window.display();
    }
    delete[] y->builder.bloc;
    if (y->lose)
        init_page(y);
}

int main()
{
    yin_yang_t *y = new yin_yang_t;
    initializeStruct(y);

    y->window.create(sf::VideoMode::getDesktopMode(), "JAM EPITECH 3");
    y->window.setFramerateLimit(30);
    y->window.clear(sf::Color(128, 128, 128));

    init_page(y);
    y->m->player = y->spritePosition_n;
    delete(y->m);
    delete y;
    return 0;
}
