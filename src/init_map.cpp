#include <iostream>
#include <fstream>
#include <sstream>
#include "jam.hpp"

void make_map(const char *map_name, yin_yang_t *y)
{
    std::ifstream file(map_name);
    if (!file.is_open()) {
        std::cout << "Erreur lors de l'ouverture du fichier" << std::endl;
        return;
    }

    std::string map_content;
    std::string line;

    int num_lines = 0;
    while (std::getline(file, line)) {
        map_content += line + "\n";
        num_lines++;
    }

    y->builder.nb_bloc = num_lines;
    y->builder.bloc = new bloc_t[y->builder.nb_bloc];

    file.clear();
    file.seekg(0, std::ios::beg);

    int i = 0;
    while (std::getline(file, line)) {
        int coor_x, coor_y;
        std::istringstream iss(line);
        if (!(iss >> coor_x >> coor_y)) {
            std::cout << "Erreur lors de la lecture des coordonnées" << std::endl;
            break;
        }

        // std::cout << coor_x << ' ' << coor_y << std::endl;
        if (i < y->builder.nb_bloc) {
            y->builder.bloc[i].coor_x = coor_x;
            y->builder.bloc[i].coor_y = coor_y;
            y->builder.bloc[i].bloc_t.loadFromFile("assets/bloc.png");
            y->builder.bloc[i].bloc_s.setScale(30.0f, 30.0f);
            y->builder.bloc[i].bloc_s.setTexture(y->builder.bloc[i].bloc_t);
            y->builder.bloc[i].bloc_s.setPosition(y->builder.bloc[i].coor_y, y->builder.bloc[i].coor_x);
        } else {
            break;
        }
        i++;
    }
    file.close();
}
