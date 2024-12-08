#include "Tablero.hpp"
#include <iostream>

Tablero::Tablero() {
    inicializar();
}

void Tablero::inicializar() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tablero[i][j] = ' ';
        }
    }
    std::cout << "Tablero inicializado:\n";
}



void Tablero::imprimirTablero() {
    std::cout << "  0   1   2" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << i << " ";
        for (int j = 0; j < 3; j++) {
            std::cout << tablero[i][j];
            if (j < 2) std::cout << " | ";
        }
        std::cout << std::endl;
        if (i < 2) std::cout << " ---+---+---" << std::endl;
    }
}
