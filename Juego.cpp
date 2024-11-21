#include <iostream>
#include "Juego.hpp"
#include "Tablero.hpp"

Juego::Juego() {
    
}

void Juego::iniciar() {
    tablero.inicializar();
    tablero.imprimirTablero();
} 