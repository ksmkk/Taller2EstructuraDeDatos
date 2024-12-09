#include "Jugador.hpp"
#include "Minimax.hpp"
#include <iostream>

Jugador::Jugador(std::string& nombre, char simbolo) : nombre(nombre), simbolo(simbolo) {}

std::string Jugador::getNombre() {
    return nombre;
}

char Jugador::getSimbolo() {
    return simbolo;
}

void Jugador::RealizarMovimiento(char tablero[3][3], int fila, int columna) {
    while (true) {
        if (fila >= 0 && fila < 3 && columna >= 0 && columna < 3 && tablero[fila][columna] == ' ') {
            tablero[fila][columna] = simbolo;
            return;
        } else {
            std::cout << "Movimiento inválido, reintente." << std::endl;
        }
    }
}

void Jugador::RealizarMovimientoIA(char tablero[3][3]) {
    int mejorFila, mejorColumna;
    mejorMovimiento(tablero, mejorFila, mejorColumna, simbolo); 
    tablero[mejorFila][mejorColumna] = simbolo;
}
