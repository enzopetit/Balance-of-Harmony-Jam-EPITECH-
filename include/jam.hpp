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

    #define POS1_X 500
    #define POS2_X 700
    #define POS3_X 1200

    typedef struct map_s {
        char **tab;
        sf::Vector2f player;
        sf::Vector2f current_pos;
    }map_t;

    struct Obstacle {
        float PositionX;
        sf::Vector2f position;
        sf::Vector2f size;
    };

    typedef struct yin_yang {
        map_t *m;
        sf::Sprite sprite_n;
        float playerXposition;
        sf::Texture texture_n;
        sf::RenderWindow window;
        sf::Vector2f PlayerPosition;
        sf::Vector2f spritePosition_n;
    } yin_yang_t;

    //typedef std::vector<std::array<Cell, SCREEN_HEIGHT / CELL_SIZE>> Map;
    int initializeStruct(yin_yang_t *y);
    bool MainBoxCollisions(yin_yang_t *ying);

#endif /* JAM_H_ */
