#include "Juego.hpp"
#include <iostream>

Juego::Juego() {}

void Juego::iniciar() {
    tablero.inicializar();
    tablero.imprimirTablero();
    tablero.menuTablero();
}
