#include "Minimax.hpp"
#include <limits>
#include <algorithm>

int evaluarTablero(char tablero[3][3], char simbolo) {
    char oponente = (simbolo == 'X') ? 'O' : 'X';
    for (int i = 0; i < 3; ++i) {
        if (tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2]) {
            if (tablero[i][0] == simbolo) return 10;
            if (tablero[i][0] == oponente) return -10;
        }
        if (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i]) {
            if (tablero[0][i] == simbolo) return 10;
            if (tablero[0][i] == oponente) return -10;
        }
    }
    if (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2]) {
        if (tablero[0][0] == simbolo) return 10;
        if (tablero[0][0] == oponente) return -10;
    }
    if (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0]) {
        if (tablero[0][2] == simbolo) return 10;
        if (tablero[0][2] == oponente) return -10;
    }
    return 0;
}

bool hayMovimientosDisponibles(char tablero[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (tablero[i][j] == ' ') return true;
        }
    }
    return false;
}

int minimax(char tablero[3][3], int profundidad, bool esMaximizador, int alpha, int beta, char simbolo) {
    int puntuacion = evaluarTablero(tablero, simbolo);
    char oponente = (simbolo == 'X') ? 'O' : 'X';
    if (puntuacion == 10) return puntuacion - profundidad;
    if (puntuacion == -10) return puntuacion + profundidad;
    if (!hayMovimientosDisponibles(tablero)) return 0;
    if (esMaximizador) {
        int mejorValor = std::numeric_limits<int>::min();
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (tablero[i][j] == ' ') {
                    tablero[i][j] = simbolo;
                    mejorValor = std::max(mejorValor, minimax(tablero, profundidad + 1, false, alpha, beta, simbolo));
                    tablero[i][j] = ' ';
                    alpha = std::max(alpha, mejorValor);
                    if (beta <= alpha) return mejorValor;
                }
            }
        }
        return mejorValor;
    } else {
        int mejorValor = std::numeric_limits<int>::max();
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (tablero[i][j] == ' ') {
                    tablero[i][j] = oponente;
                    mejorValor = std::min(mejorValor, minimax(tablero, profundidad + 1, true, alpha, beta, simbolo));
                    tablero[i][j] = ' ';
                    beta = std::min(beta, mejorValor);
                    if (beta <= alpha) return mejorValor;
                }
            }
        }
        return mejorValor;
    }
}

void mejorMovimiento(char tablero[3][3], int& fila, int& columna, char simbolo) {
    int mejorValor = std::numeric_limits<int>::min();
    fila = -1;
    columna = -1;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (tablero[i][j] == ' ') {
                tablero[i][j] = simbolo;
                int valorMovimiento = minimax(tablero, 0, false, std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), simbolo);
                tablero[i][j] = ' ';
                if (valorMovimiento > mejorValor) {
                    mejorValor = valorMovimiento;
                    fila = i;
                    columna = j;
                }
            }
        }
    }
}
