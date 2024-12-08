#include "Minimax.hpp"
#include <algorithm>

int evaluar(char tablero[3][3], char simbolo) {
    char oponente = (simbolo == 'X') ? 'O' : 'X';

    for (int i = 0; i < 3; i++) {
        if ((tablero[i][0] == simbolo && tablero[i][1] == simbolo && tablero[i][2] == simbolo) ||
            (tablero[0][i] == simbolo && tablero[1][i] == simbolo && tablero[2][i] == simbolo)) {
            return 10;
        }
        if ((tablero[i][0] == oponente && tablero[i][1] == oponente && tablero[i][2] == oponente) ||
            (tablero[0][i] == oponente && tablero[1][i] == oponente && tablero[2][i] == oponente)) {
            return -10;
        }
    }
    if ((tablero[0][0] == simbolo && tablero[1][1] == simbolo && tablero[2][2] == simbolo) ||
        (tablero[0][2] == simbolo && tablero[1][1] == simbolo && tablero[2][0] == simbolo)) {
        return 10;
    }
    if ((tablero[0][0] == oponente && tablero[1][1] == oponente && tablero[2][2] == oponente) ||
        (tablero[0][2] == oponente && tablero[1][1] == oponente && tablero[2][0] == oponente)) {
        return -10;
    }

    return 0;
}

int minimax(char tablero[3][3], int profundidad, bool esMax, int alfa, int beta, char simbolo) {
    int evaluacion = evaluar(tablero, simbolo);
    if (evaluacion == 10 || evaluacion == -10) return evaluacion;
    if (esEmpate(tablero)) return 0;

    if (esMax) {
        int mejor = -1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tablero[i][j] == ' ') {
                    tablero[i][j] = simbolo;
                    mejor = std::max(mejor, minimax(tablero, profundidad + 1, false, alfa, beta, simbolo));
                    tablero[i][j] = ' ';
                    alfa = std::max(alfa, mejor);
                    if (beta <= alfa) return mejor;
                }
            }
        }
        return mejor;
    } else {
        int mejor = 1000;
        char oponente = (simbolo == 'X') ? 'O' : 'X';
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tablero[i][j] == ' ') {
                    tablero[i][j] = oponente;
                    mejor = std::min(mejor, minimax(tablero, profundidad + 1, true, alfa, beta, simbolo));
                    tablero[i][j] = ' ';
                    beta = std::min(beta, mejor);
                    if (beta <= alfa) return mejor;
                }
            }
        }
        return mejor;
    }
}

void mejorMovimiento(char tablero[3][3], int& mejorFila, int& mejorColumna, char simbolo) {
    int mejorValor = -1000;
    mejorFila = -1;
    mejorColumna = -1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tablero[i][j] == ' ') {
                tablero[i][j] = simbolo;
                int valorMovimiento = minimax(tablero, 0, false, -1000, 1000, simbolo);
                tablero[i][j] = ' ';
                if (valorMovimiento > mejorValor) {
                    mejorFila = i;
                    mejorColumna = j;
                    mejorValor = valorMovimiento;
                }
            }
        }
    }
}

bool esEmpate(char tablero[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (tablero[i][j] == ' ') return false;
    return true;
}