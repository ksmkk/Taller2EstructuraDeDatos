#include <iostream>
#include "Jugador.hpp"

Jugador::Jugador(std::string& nombre, char simbolo) : nombre(nombre), simbolo(simbolo) {}

std::string Jugador::getNombre() {
    return nombre;
}

char Jugador::getSimbolo() {
    return simbolo;
}

void Jugador::RealizarMovimiento(char tablero [3][3], int fila, int columna) {
    while (true) {
        if (fila >= 0 && fila < 3 && columna >= 0 && columna < 3 && tablero[fila][columna] == ' ') {
        tablero[fila][columna] == simbolo;
        continue;
        } else {std::cout <<"Movimiento inválido, reintente."<<std::endl;}
    }    
}

void Jugador::ObtenerMovimiento(char tablero [3][3], int& fila, int& columna) {
    while (true) {
        std::cout << "Turno de " << nombre << " (" << simbolo << "). Ingresa fila y columna (0-2): ";
        std::cin >> fila >> columna;

         if (fila >= 0 && fila < 3 && columna >= 0 && columna < 3 && tablero[fila][columna] == ' ') {
            return;

        } else {
            std::cout << "Movimiento inválido. Intenta de nuevo.\n";
        }
    }
}