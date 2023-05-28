#include "jam.hpp"

void init_page(yin_yang_t *y, char const *map, char const *info)
{
    if (!load_personnages_and_yin_yang(y, info))
        return;
    make_map(map, y);
    while (y->window.isOpen()) {
        y->stop_chute_n = false;
        y->stop_chute_b = false;
        get_keyboard_event(y);
        update_physique(y);
        if (collisions_p1(y) || collisions_p2(y))
            break;
        update_game(y);
    }
    delete[] y->builder.bloc;
    if (y->lose)
        init_page(y, map, info);
}

int main()
{
    yin_yang_t *y = new yin_yang_t;
    initializeStruct(y);

    y->window.create(sf::VideoMode::getDesktopMode(), "JAM EPITECH 3");
    y->window.setFramerateLimit(300);
    y->window.clear(sf::Color(128, 128, 128));

    init_page(y, "map/map_1.txt", "map/info_1.txt");
    y->m->player = y->spritePosition_n;
    delete(y->m);
    delete y;
    return 0;
}
