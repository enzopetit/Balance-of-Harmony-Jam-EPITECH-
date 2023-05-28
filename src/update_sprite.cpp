#include "jam.hpp"

void update_sprite_n(yin_yang_t *y)
{
    sf::IntRect textureRect = y->sprite_n.getTextureRect();
    int rectLeft = textureRect.left;
    int rectTop = textureRect.top;
    int rectWidth = textureRect.width;

    if (y->P_1_vy > 0 && y->P_1_vx < 4 && y->P_1_vx > -4) {
        y->sprite_n.setTextureRect(sf::IntRect(34, 30, 17, 28));
    } else if (y->P_1_vx > 0) {
        if (rectLeft != 34)
            y->sprite_n.setTextureRect(sf::IntRect(34, 0, 17, 28));
        if (rectLeft != 17)
            y->sprite_n.setTextureRect(sf::IntRect(17, 0, 17, 28));
    } else if (y->P_1_vx < 0) {
        if (rectTop == 0 || rectWidth == 17)
            y->sprite_n.setTextureRect(sf::IntRect(0, 30, 17, 28));
        if (rectLeft == 0)
            y->sprite_n.setTextureRect(sf::IntRect(17, 30, 17, 28));
    } else {
        y->sprite_n.setTextureRect(sf::IntRect(0, 0, 17, 28));
    }
}

void update_sprite_b(yin_yang_t *y)
{
    sf::IntRect textureRect = y->sprite_b.getTextureRect();
    int rectLeft = textureRect.left;
    int rectTop = textureRect.top;
    int rectWidth = textureRect.width;

    if (y->P_2_vy > 0 && y->P_2_vx < 4 && y->P_2_vx > -4) {
        y->sprite_b.setTextureRect(sf::IntRect(34, 30, 17, 28));
    } else if (y->P_2_vx > 0) {
        if (rectLeft != 34)
            y->sprite_b.setTextureRect(sf::IntRect(34, 0, 17, 28));
        if (rectLeft != 17)
            y->sprite_b.setTextureRect(sf::IntRect(17, 0, 17, 28));
    } else if (y->P_2_vx < 0) {
        if (rectTop == 0 || rectWidth == 17)
            y->sprite_b.setTextureRect(sf::IntRect(0, 30, 17, 28));
        if (rectLeft == 0)
            y->sprite_b.setTextureRect(sf::IntRect(17, 30, 17, 28));
    } else {
        y->sprite_b.setTextureRect(sf::IntRect(0, 0, 17, 28));
    }
}
