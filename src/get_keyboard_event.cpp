#include "jam.hpp"

void get_keyboard_event(yin_yang_t *y)
{
    sf::Event event;
    while (y->window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            y->window.close();
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Up) {
                if (y->cond != 0)
                    y->P_1_vy = -18;
                y->jump = true;
            }
            if (event.key.code == sf::Keyboard::Right) {
                if (y->P_1_vx == 0) {
                    y->P_1_vx += 15;
                    y->P_1isRightPressed = true;
                }
            }
            if (event.key.code == sf::Keyboard::Left) {
                if (y->P_1_vx == 0) {
                    y->P_1_vx -= 15;
                    y->P_1isLeftPressed = true;
                }
            }
            if (event.key.code == sf::Keyboard::A) {}
        }
        else if (event.type == sf::Event::KeyReleased)
        {
            if (event.key.code == sf::Keyboard::Right) {
                y->P_1isRightPressed = false;
            }
            if (event.key.code == sf::Keyboard::Left) {
                y->P_1isLeftPressed = false;
            }
        }
    }
}
