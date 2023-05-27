#ifndef JAM_H_
#define JAM_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>

#define SUCCESS 0
#define FAILURE 84
#define CLEAR -1

constexpr unsigned char CELL_SIZE = 16;

constexpr unsigned short SCREEN_HEIGHT = 240;
constexpr unsigned short SCREEN_WIDTH = 256;

typedef struct map_s {
    char **tab;
    sf::Vector2f player;
} map_t;

typedef struct {
    float coor_x;
    float coor_y;
    sf::Sprite bloc_s;
    sf::Texture bloc_t;
} bloc_t;

typedef struct {
    char **tab;
    int nb_bloc;
    bloc_t *bloc;
} map_build_t;

typedef struct yin_yang {
    float P_1_vx;
    float P_1_vy;
    float P_2_vx;
    float P_2_vy;
    bool P_1isRightPressed = false;
    bool P_1isLeftPressed = false;
    bool P_2isRightPressed = false;
    bool P_2isLeftPressed = false;
    bool lose = false;
    bool jump = false;
    int cond;

    map_build_t builder;

    map_t *m;
    sf::Sprite sprite_n;
    sf::Texture texture_n;

    sf::Sprite map_sprite;
    sf::Texture map_text;
    sf::Vector2f mapPosition;

    sf::RenderWindow window;
    sf::Vector2f spritePosition_n;
} yin_yang_t;

constexpr std::chrono::microseconds FRAME_DURATION(16667);

void make_map(const char *map_name, yin_yang_t *y);
void get_keyboard_event(yin_yang_t *y);
int initializeStruct(yin_yang_t *y);
int cond_stop_chute(yin_yang_t *y);
int cond_stop_saut(yin_yang_t *y);
int cond_stop_droite(yin_yang_t *y);
int cond_stop_gauche(yin_yang_t *y);

#endif /* JAM_H_ */
