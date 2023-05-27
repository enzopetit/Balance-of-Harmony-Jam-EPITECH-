/*
** EPITECH PROJECT, 2023
** main
** File description:
** Balance of harmony
*/

#include "jam.hpp"

static void drawObstacles(sf::RenderWindow& window, const std::vector<Obstacle>& obstacles, float playerXPosition)
{
    sf::RectangleShape obstacleShape;
    obstacleShape.setFillColor(sf::Color::Black);

    for (const auto& obstacle : obstacles)
    {
        sf::Vector2f adjustedPosition = obstacle.position;
        adjustedPosition.x += playerXPosition;

        obstacleShape.setPosition(adjustedPosition);
        obstacleShape.setSize(obstacle.size);
        window.draw(obstacleShape);
    }
}

void init_page(yin_yang_t *y)
{
    bool box = false;
    float vitesse_x = 0;
    float vitesse_y = 0;
    y->playerXposition = 0;
    bool isLeftPressed = false;
    bool isRightPressed = false;
    std::vector<Obstacle> obstacles;

    Obstacle obstacle1;
    obstacle1.PositionX = 500;
    obstacle1.position = sf::Vector2f(500, 970);
    obstacle1.size = sf::Vector2f(50, 50);
    obstacles.push_back(obstacle1);

    Obstacle obstacle2;
    obstacle2.PositionX = 700;
    obstacle2.position = sf::Vector2f(725.76, 970);
    obstacle2.size = sf::Vector2f(80, 60);
    obstacles.push_back(obstacle2);

    Obstacle obstacle3;
    obstacle3.PositionX = 1200;
    obstacle3.position = sf::Vector2f(1200, 970);
    obstacle3.size = sf::Vector2f(70, 70);
    obstacles.push_back(obstacle3);

    if (!y->texture_n.loadFromFile("assets/JAM_TEST.png"))
    {
        std::cout << "Erreur lors du chargement de l'image" << std::endl;
        return;
    }
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
                y->PlayerPosition.x = y->sprite_n.getPosition().x;
                if (y->PlayerPosition.x == POS1_X || y->PlayerPosition.x == POS2_X || y->PlayerPosition.x == POS3_X) {
                    box = true;
                }
                if (event.key.code == sf::Keyboard::Space) {
                    if (vitesse_y == 0)
                        vitesse_y -= 1.7;
                }
                if (event.key.code == sf::Keyboard::Right && box == false) {
                    if (vitesse_x == 0) {
                        vitesse_x += 1;
                        isRightPressed = true;
                    }
                }
                if (event.key.code == sf::Keyboard::Left && box == false) {
                    if (vitesse_x == 0) {
                        vitesse_x -= 1;
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
            if (MainBoxCollisions(y) == true) {
                //empecher le saut avec le bool
            } else {
                //et mettre le bool à false
            }
            box = false;
        }

        if (!isRightPressed && !isLeftPressed) {
            if (vitesse_x < 0.1 && vitesse_x > -0.1 && vitesse_y == 0) {
                vitesse_x = 0;
            } else if (vitesse_x > 0) {
                vitesse_x -= 0.02;
            } else if (vitesse_x < 0)
                vitesse_x += 0.02;
        }

        y->spritePosition_n.y += vitesse_y;
        if (y->spritePosition_n.y >= 900) {
            y->spritePosition_n.y = 900;
            vitesse_y = 0;
        } else if (y->spritePosition_n.y < 900) {
            vitesse_y += 0.01;
        }

        y->spritePosition_n.x += vitesse_x;
        y->sprite_n.setPosition(y->spritePosition_n);

        y->window.clear(sf::Color(128, 128, 128));
        drawObstacles(y->window, obstacles, y->playerXposition);
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
