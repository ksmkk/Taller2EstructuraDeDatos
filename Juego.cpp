#include "Juego.hpp"
#include <iostream>

Juego::Juego() {}

void Juego::iniciar() {
    tablero.inicializar();
    tablero.menuTablero();
}
