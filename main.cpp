/*
** EPITECH PROJECT, 2023
** Projet
** File description:
** main
*/

#include <SFML/Graphics.hpp>
#include <iostream>

void init_page()
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "JAM EPITECH 3");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.display();
    }
}

int main()
{
    std::cout << "START PROJET !" << std::endl;
    init_page();
    return 0;
}
