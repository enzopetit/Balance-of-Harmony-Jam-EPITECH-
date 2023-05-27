/*
** EPITECH PROJECT, 2023
** main
** File description:
** Balance of harmony
*/

#include "jam.hpp"

void init_page(yin_yang_t *y)
{
    float vitesse_x = 0;
    float vitesse_y = 0;
    bool isRightPressed = false;
    bool isLeftPressed = false;

    if (!y->texture_n.loadFromFile("assets/JAM_TEST.png")) {
        std::cout << "Erreur lors du chargement de l'image" << std::endl;
        return;
    }
    y->window.setFramerateLimit(30);
    y->sprite_n.setTexture(y->texture_n);
    y->sprite_n.setTextureRect(sf::IntRect(0, 0, 17, 28));
    y->sprite_n.setScale(3.0f, 3.0f);
    y->spritePosition_n = y->sprite_n.getPosition();
    y->spritePosition_n.y = 900;
    y->sprite_n.setPosition(y->spritePosition_n);

    while (y->window.isOpen())
    {
        sf::Event event;
        while (y->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                y->window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space) {
                    if (y->spritePosition_n.y == 900)
                        vitesse_y -= 15;
                }
                if (event.key.code == sf::Keyboard::Right) {
                    if (vitesse_x == 0) {
                        vitesse_x += 10;
                        isRightPressed = true;
                    }
                }
                if (event.key.code == sf::Keyboard::Left) {
                    if (vitesse_x == 0) {
                        vitesse_x -= 10;
                        isLeftPressed = true;
                    }
                }
                if (event.key.code == sf::Keyboard::Up && vitesse_y == 0)
                    std::cout << "haut" << std::endl;
                if (event.key.code == sf::Keyboard::A)
                    std::cout << "bas" << std::endl;
            }
            else if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Right) {
                    isRightPressed = false;
                    printf("Droite\n");
                }
                if (event.key.code == sf::Keyboard::Left) {
                    isLeftPressed = false;
                    std::cout << "Left released" << std::endl;
                }
            }
        }

        if (!isRightPressed && !isLeftPressed) {
            if (vitesse_x < 1 && vitesse_x > -1 && vitesse_y == 0) {
                vitesse_x = 0;
            } else if (vitesse_x > 0) {
                vitesse_x -= 5;
            } else if (vitesse_x < 0)
                vitesse_x += 5;
        }

        y->spritePosition_n.y += vitesse_y;
        if (y->spritePosition_n.y >= 900) {
            y->spritePosition_n.y = 900;
            vitesse_y = 0;
        } else if (y->spritePosition_n.y < 900) {
            vitesse_y += 1;
        }

        y->spritePosition_n.x += vitesse_x;
        y->sprite_n.setPosition(y->spritePosition_n);

        y->window.clear(sf::Color(128, 128, 128));
        y->window.draw(y->sprite_n);
        y->window.display();
    }
}

int main()
{
    std::cout << "START PROJET !" << std::endl;

    yin_yang_t *y = new yin_yang_t;
    initializeStruct(y);

    y->window.create(sf::VideoMode::getDesktopMode(), "JAM EPITECH 3");
    y->window.clear(sf::Color(128, 128, 128));

    init_page(y);
    y->m->player = y->spritePosition_n;
    delete(y->m);
    delete y;
    return 0;
}
