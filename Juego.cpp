#include "Juego.hpp"
#include <iostream>

Juego::Juego() {}

void Juego::iniciar() {
    tablero.menuTablero();
    tablero.inicializar();
    tablero.imprimirTablero();
}
