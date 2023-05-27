#include "jam.hpp"

int cond_stop_chute(yin_yang_t *y)
{
    for (int i = 0; i < y->builder.nb_bloc; i++) {
        std::cout << y->builder.bloc[i].coor_x << ' ' << y->spritePosition_n.y << std::endl;
        if (y->builder.bloc[i].coor_x - 30 <= y->spritePosition_n.y) {
            return y->builder.bloc[i].coor_x - 56;
        }
    }
    return 0;
}

void init_page(yin_yang_t *y)
{
    if (!y->texture_n.loadFromFile("assets/perso_noir.png")) {
        return;
    }
    y->sprite_n.setTexture(y->texture_n);
    y->sprite_n.setTextureRect(sf::IntRect(0, 0, 17, 28));
    y->sprite_n.setScale(2.0f, 2.0f);
    y->spritePosition_n = y->sprite_n.getPosition();
    y->spritePosition_n.x = 900;
    y->spritePosition_n.y = 300;
    y->sprite_n.setPosition(y->spritePosition_n);
    int cond;
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
        cond = cond_stop_chute(y);
        // std::cout << cond << std::endl;
        if (cond != 0) {
            y->spritePosition_n.y = cond;
            y->P_1_vy = 0;
        } else if (y->spritePosition_n.y < 900) {
            y->P_1_vy += 1;
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
