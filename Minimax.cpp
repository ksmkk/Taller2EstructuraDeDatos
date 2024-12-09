#include "Minimax.hpp"
#include "Tablero.hpp"
#include <algorithm>

int minimax(char tablero[3][3], bool esMaximizador, char simboloIA, char simboloJugador) {
    Tablero tempTablero;
    int puntaje = tempTablero.evaluar(simboloIA);

    if (puntaje == 10 || puntaje == -10 || tempTablero.esEmpate()) {
        return puntaje;
    }

    if (esMaximizador) {
        int mejorPuntaje = -1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tablero[i][j] == ' ') {
                    tablero[i][j] = simboloIA;
                    mejorPuntaje = std::max(mejorPuntaje, minimax(tablero, false, simboloIA, simboloJugador));
                    tablero[i][j] = ' ';
                }
            }
        }
        return mejorPuntaje;
    } else {
        int mejorPuntaje = 1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tablero[i][j] == ' ') {
                    tablero[i][j] = simboloJugador;
                    mejorPuntaje = std::min(mejorPuntaje, minimax(tablero, true, simboloIA, simboloJugador));
                    tablero[i][j] = ' ';
                }
            }
        }
        return mejorPuntaje;
    }
}
