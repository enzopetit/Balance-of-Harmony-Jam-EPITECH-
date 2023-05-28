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

    if (!y->texture_b.loadFromFile("assets/perso_blanc.png")) {
        return;
    }
    y->sprite_b.setTexture(y->texture_b);
    y->sprite_b.setTextureRect(sf::IntRect(0, 0, 17, 28));
    y->sprite_b.setScale(2.0f, 2.0f);
    y->spritePosition_b = y->sprite_b.getPosition();
    y->spritePosition_b.y = 50;
    y->spritePosition_b.x = 1800;
    y->sprite_b.setPosition(y->spritePosition_b);
}

void init_page(yin_yang_t *y)
{
    load_personnages(y);
    make_map("map/map_1.txt", y);
    while (y->window.isOpen()) {
        y->stop_chute_n = false;
        y->stop_chute_b = false;
        get_keyboard_event(y);
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
        if (collisions_p1(y) || collisions_p2(y))
            break;
        y->spritePosition_n.x += y->P_1_vx;
        y->sprite_n.setPosition(y->spritePosition_n);

        y->spritePosition_b.x += y->P_2_vx;
        y->sprite_b.setPosition(y->spritePosition_b);

        update_sprite_n(y);
        update_sprite_b(y);

        y->window.clear(sf::Color(128, 128, 128));
        y->window.draw(y->sprite_n);
        y->window.draw(y->sprite_b);
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
