/*
** EPITECH PROJECT, 2023
** JAM
** File description:
** header file
*/

#ifndef JAM_H_
#define JAM_H_

#include <SFML/Graphics.hpp>
#include <iostream>

typedef struct yin_yang {
    sf::RenderWindow window;
    sf::Texture texture_n;
    sf::Sprite sprite_n;
    sf::Vector2f spritePosition_n;
} yin_yang_t;

#endif /* JAM_H_ */
