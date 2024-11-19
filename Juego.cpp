#include <iostream>;
#include "Juego.hpp";
#include "Tablero.hpp";

void Juego::iniciar() {
    tablero.inicializar();
    tablero.imprimirTablero();
}