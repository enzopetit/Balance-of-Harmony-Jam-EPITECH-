#include "jam.hpp"

void display_credit(yin_yang_t *y)
{
    y->window.clear(sf::Color(128, 128, 128));

    sf::Text text;
    text.setFont(y->font);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.setString("Credits:\n\nEliot GOURDOUX - Premiere annee a Epitech\nArslan TETU - Premiere annee a Epitech\nEnzo PETIT - Premiere annee a Epitech");
    text.setPosition(100, 100);

    sf::RectangleShape backButton(sf::Vector2f(100.0f, 50.0f));
    backButton.setFillColor(sf::Color::Blue);
    backButton.setPosition(100, 500);

    sf::Text backText;
    backText.setFont(y->font);
    backText.setCharacterSize(20);
    backText.setFillColor(sf::Color::White);
    backText.setString("Retour");
    backText.setPosition(130, 510);

    while (y->window.isOpen()) {
        sf::Event event;
        while (y->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                y->window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(y->window);
                if (backButton.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                    return;
                }
            }
        }

        y->window.clear(sf::Color(128, 128, 128));
        y->window.draw(text);
        y->window.draw(backButton);
        y->window.draw(backText);
        y->window.display();
    }
}

void display_regle(yin_yang_t *y)
{
    y->window.clear(sf::Color(128, 128, 128));

    sf::Text text;
    text.setFont(y->font);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.setString("Regles:\n\nDans ce jeu vous incarner 1 personnages qui a ete separe en 2 entites.\nSont but est de recuperer les yin avec sa partie blanche, et la yang avec sa partie noir\nPour redevenir gris en fusionnant\nPar ce la vie, c'est pas tout blanc tout noir...\ntouche blanche = z, q, s, d\ntouche noir = fleche directionnel");
    text.setPosition(100, 100);

    sf::RectangleShape backButton(sf::Vector2f(100.0f, 50.0f));
    backButton.setFillColor(sf::Color::Blue);
    backButton.setPosition(100, 500);

    sf::Text backText;
    backText.setFont(y->font);
    backText.setCharacterSize(20);
    backText.setFillColor(sf::Color::White);
    backText.setString("Retour");
    backText.setPosition(130, 510);

    while (y->window.isOpen()) {
        sf::Event event;
        while (y->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                y->window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(y->window);
                if (backButton.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                    return;
                }
            }
        }

        y->window.clear(sf::Color(128, 128, 128));
        y->window.draw(text);
        y->window.draw(backButton);
        y->window.draw(backText);
        y->window.display();
    }
}

void display_world(yin_yang_t *y)
{
    y->window.draw(y->hoppy);

    sf::RectangleShape button1(sf::Vector2f(100.0f, 100.0f));
    button1.setFillColor(sf::Color(128, 128, 128));
    button1.setPosition(100, 370);

    sf::RectangleShape button2(sf::Vector2f(100.0f, 100.0f));
    button2.setFillColor(sf::Color(128, 128, 128));
    button2.setPosition(700, 370);

    sf::RectangleShape button3(sf::Vector2f(100.0f, 100.0f));
    button3.setFillColor(sf::Color(128, 128, 128));
    button3.setPosition(1300, 370);

    sf::Text text1;
    text1.setFont(y->font);
    text1.setString("1");
    text1.setCharacterSize(50);
    text1.setFillColor(sf::Color::White);
    text1.setStyle(sf::Text::Bold);
    text1.setOrigin(text1.getGlobalBounds().width / 2, text1.getGlobalBounds().height / 2);
    text1.setPosition(150, 400);

    sf::Text text2;
    text2.setFont(y->font);
    text2.setString("2");
    text2.setCharacterSize(50);
    text2.setFillColor(sf::Color::White);
    text2.setStyle(sf::Text::Bold);
    text2.setOrigin(text2.getGlobalBounds().width / 2, text2.getGlobalBounds().height / 2);
    text2.setPosition(750, 400);

    sf::Text text3;
    text3.setFont(y->font);
    text3.setString("3");
    text3.setCharacterSize(50);
    text3.setFillColor(sf::Color::White);
    text3.setStyle(sf::Text::Bold);
    text3.setOrigin(text3.getGlobalBounds().width / 2, text3.getGlobalBounds().height / 2);
    text3.setPosition(1350, 400);

    sf::RectangleShape backButton(sf::Vector2f(200.0f, 50.0f));
    backButton.setFillColor(sf::Color::Blue);
    backButton.setPosition(100, 600);

    sf::Text backText;
    backText.setFont(y->font);
    backText.setString("Retour");
    backText.setCharacterSize(30);
    backText.setFillColor(sf::Color::White);
    backText.setStyle(sf::Text::Bold);
    backText.setOrigin(backText.getGlobalBounds().width / 2, backText.getGlobalBounds().height / 2);
    backText.setPosition(200, 625);

    sf::Text victoryText;
    victoryText.setFont(y->font);
    victoryText.setString("FELICITATION, L'EQUILIBRE EST REVENUE");
    victoryText.setCharacterSize(30);
    victoryText.setFillColor(sf::Color::Black);
    victoryText.setStyle(sf::Text::Bold);
    victoryText.setOrigin(victoryText.getGlobalBounds().width / 2, victoryText.getGlobalBounds().height / 2);
    victoryText.setPosition(y->window.getSize().x / 2, y->window.getSize().y / 2);

    bool showVictoryMessage = false;

    while (y->window.isOpen()) {
        sf::Event event;
        while (y->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                y->window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(y->window);

                if (button1.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                    init_page(y, "map/map_1.txt", "map/info_1.txt");
                } else if (button2.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                    init_page(y, "map/map_2.txt", "map/info_2.txt");
                } else if (button3.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                    // init_page(y, "map/map_3.txt", "map/info_3.txt");
                    showVictoryMessage = true;
                } else if (backButton.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                    y->window.clear(sf::Color(128, 128, 128));
                    return;
                }
            }
        }

        y->window.clear(sf::Color(128, 128, 128));
        y->window.draw(y->hoppy);
        y->window.draw(button1);
        y->window.draw(button2);
        y->window.draw(button3);
        y->window.draw(text1);
        y->window.draw(text2);
        y->window.draw(text3);
        y->window.draw(backButton);
        y->window.draw(backText);

        if (showVictoryMessage) {
            y->window.clear(sf::Color(128, 128, 128));
            y->window.draw(backButton);
            y->window.draw(text3);
            y->window.draw(victoryText);
        }

        y->window.display();
    }
}

void start_game(yin_yang_t *y)
{
    sf::Texture texture;
    if (!texture.loadFromFile("assets/hoppy.png")) {
        std::cout << "Erreur lors du chargement de l'image." << std::endl;
        return;
    }

    y->hoppy.setTexture(texture);
    y->hoppy.setScale(1920.0f / 660, 1080.0f / 832);
    y->hoppy.setPosition(0, 0);

    if (!y->font.loadFromFile("assets/arial.ttf")) {
        std::cout << "Erreur lors du chargement de la police." << std::endl;
        return;
    }

    sf::Text textJouer;
    textJouer.setFont(y->font);
    textJouer.setString("Start !");
    textJouer.setCharacterSize(24);
    textJouer.setFillColor(sf::Color::Black);
    textJouer.setPosition(130, 115);

    sf::Text textRegles;
    textRegles.setFont(y->font);
    textRegles.setString("Rules !");
    textRegles.setCharacterSize(24);
    textRegles.setFillColor(sf::Color::Black);
    textRegles.setPosition(130, 215);

    sf::Text textCreateur;
    textCreateur.setFont(y->font);
    textCreateur.setString("Credit");
    textCreateur.setCharacterSize(24);
    textCreateur.setFillColor(sf::Color::Black);
    textCreateur.setPosition(130, 315);

    sf::Text textQuitter;
    textQuitter.setFont(y->font);
    textQuitter.setString("Quit ...");
    textQuitter.setCharacterSize(24);
    textQuitter.setFillColor(sf::Color::Black);
    textQuitter.setPosition(130, 415);

    sf::RectangleShape buttonJouer(sf::Vector2f(200.0f, 50.0f));
    buttonJouer.setFillColor(sf::Color::Red);
    buttonJouer.setPosition(100, 100);

    sf::RectangleShape buttonRegles(sf::Vector2f(200.0f, 50.0f));
    buttonRegles.setFillColor(sf::Color::Green);
    buttonRegles.setPosition(100, 200);

    sf::RectangleShape buttonCreateur(sf::Vector2f(200.0f, 50.0f));
    buttonCreateur.setFillColor(sf::Color::Blue);
    buttonCreateur.setPosition(100, 300);

    sf::RectangleShape buttonQuitter(sf::Vector2f(200.0f, 50.0f));
    buttonQuitter.setFillColor(sf::Color::Yellow);
    buttonQuitter.setPosition(100, 400);

    while (y->window.isOpen()) {
        sf::Event event;
        while (y->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                y->window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(y->window);

                if (buttonJouer.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                    display_world(y);
                } else if (buttonRegles.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                    display_regle(y);
                } else if (buttonCreateur.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                    y->window.draw(y->hoppy);
                    display_credit(y);
                } else if (buttonQuitter.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                    y->window.close();
                }
            }
        }

        y->window.clear(sf::Color(128, 128, 128));
        y->window.draw(y->hoppy);
        y->window.draw(buttonJouer);
        y->window.draw(buttonRegles);
        y->window.draw(buttonCreateur);
        y->window.draw(buttonQuitter);
        y->window.draw(textJouer);
        y->window.draw(textRegles);
        y->window.draw(textCreateur);
        y->window.draw(textQuitter);
        y->window.display();
    }
}