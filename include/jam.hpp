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
    #include <chrono>

    #define SUCCESS 0
    #define FAILURE 84
    #define CLEAR -1

    constexpr unsigned char CELL_SIZE = 16;
    constexpr unsigned char CELL_SIZE = 2;

    constexpr unsigned short SCREEN_HEIGHT = 240;
    constexpr unsigned short SCREEN_WIDTH = 256;

    Map map(SCREEN_WIDTH / CELL_SIZE);

    constexpr std::chrono::microseconds FRAME_DURATION(16667);

    enum Cell {
        Empty,
        Wall
    };

    typedef struct map_s {
        char **tab;
        sf::Vector2f player;
    }map_t;

    typedef struct yin_yang {
        map_t *m;
        sf::Sprite sprite_n;
        sf::Texture texture_n;
        sf::RenderWindow window;
        sf::Vector2f spritePosition_n;
    } yin_yang_t;

    typedef std::vector<std::array<Cell, SCREEN_HEIGHT / CELL_SIZE>> Map;
    int initializeStruct(yin_yang_t *y);

#endif /* JAM_H_ */
