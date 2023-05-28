#include "jam.hpp"

void get_info(yin_yang_t *y, const char *filename)
{
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Erreur lors de l'ouverture du fichier." << std::endl;
        return;
    }

    std::string line;
    if (std::getline(file, line)) {
        std::istringstream iss(line);
        if (!(iss >> y->nb_piece)) {
            std::cout << "Erreur lors de la lecture de y->nb_piece." << std::endl;
            return;
        }
    }
    if (std::getline(file, line)) {
        std::istringstream iss(line);
        if (!(iss >> y->spawn_nx >> y->spawn_ny)) {
            std::cout << "Erreur lors de la lecture de y->spawn_nx et y->spawn_ny." << std::endl;
            return;
        }
    }
    if (std::getline(file, line)) {
        std::istringstream iss(line);
        if (!(iss >> y->spawn_bx >> y->spawn_by)) {
            std::cout << "Erreur lors de la lecture de y->spawn_bx et y->spawn_by." << std::endl;
            return;
        }
    }
    y->p = new piece_t[y->nb_piece * 2];
    for (int i = 0; i < y->nb_piece * 2; i++) {
        if (std::getline(file, line)) {
            std::istringstream iss(line);
            if (!(iss >> y->p[i].x >> y->p[i].y)) {
                std::cout << "Erreur lors de la lecture des coordonnées de la pièce " << i << "." << std::endl;
                return;
            }
            y->p[i].is_noir = (i % 2 == 0);
            y->p[i].is_take = false;
        }
        else {
            std::cout << "Erreur lors de la lecture des coordonnées de la pièce " << i << "." << std::endl;
            return;
        }
    }
}

bool load_personnages_and_yin_yang(yin_yang_t *y, char const *info)
{
    get_info(y, info);
    if (!y->texture_n.loadFromFile("assets/perso_noir.png")) {
        return false;
    }
    y->sprite_n.setTexture(y->texture_n);
    y->sprite_n.setTextureRect(sf::IntRect(0, 0, 17, 28));
    y->sprite_n.setScale(2.0f, 2.0f);
    y->spritePosition_n = y->sprite_n.getPosition();
    y->spritePosition_n.x = y->spawn_nx;
    y->spritePosition_n.y = y->spawn_ny;
    y->sprite_n.setPosition(y->spritePosition_n);

    if (!y->texture_b.loadFromFile("assets/perso_blanc.png")) {
        return false;
    }

    y->sprite_b.setTexture(y->texture_b);
    y->sprite_b.setTextureRect(sf::IntRect(0, 0, 17, 28));
    y->sprite_b.setScale(2.0f, 2.0f);
    y->spritePosition_b = y->sprite_b.getPosition();
    y->spritePosition_b.x = y->spawn_bx;
    y->spritePosition_b.y = y->spawn_by;
    y->sprite_b.setPosition(y->spritePosition_b);

    for (int i = 0; i < y->nb_piece * 2; i++) {
        if (i % 2 == 0) {
            if (!y->p[i].piece_t.loadFromFile("assets/yang.png")) {
                return false;
            }
        } else {
            if (!y->p[i].piece_t.loadFromFile("assets/yin.png")) {
                return false;
            }
        }
        y->p[i].piece_s.setTexture(y->p[i].piece_t);
        y->p[i].piece_s.setPosition(y->p[i].x, y->p[i].y);
    }
    return true;
}
