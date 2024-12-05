#ifndef JUGADOR_HPP
#define JUGADOR_HPP

#include <string>

class Jugador {
private:
    std::string nombre;
    char simbolo;

public:
    Jugador(std::string& nombre, char simbolo);
    std::string getNombre();
    char getSimbolo();
    void RealizarMovimiento(char tablero[3][3], int fila, int columna);
    void ObtenerMovimiento(char tablero[3][3], int& fila, int& columna);
    void RealizarMovimientoIA(char tablero[3][3]); 
};

#endif
