#include "jam.hpp"

bool cond_victoire_2(yin_yang_t *y)
{
    sf::FloatRect bounds1 = y->sprite_n.getGlobalBounds();
    sf::FloatRect bounds2 = y->sprite_b.getGlobalBounds();

    return bounds1.intersects(bounds2);
}

bool cond_victoire(yin_yang_t *y)
{
    for (int i = 0; i < y->nb_piece * 2; i++) {
        if (y->p[i].is_take)
            return false;
    }
    return true;
}

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
        update_yin_yang(y);
        update_game(y);
        if (cond_victoire(y) && cond_victoire_2(y)) {
            delete[] y->builder.bloc;
            return;
        }
    }
    if (y->lose)
        init_page(y, map, info);
}

int main()
{
    yin_yang_t *y = new yin_yang_t;

    y->window.create(sf::VideoMode::getDesktopMode(), "JAM EPITECH 3");
    y->window.setFramerateLimit(30);
    y->window.clear(sf::Color(128, 128, 128));

    start_game(y);
    delete y;
    return 0;
}
