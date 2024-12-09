#ifndef MINIMAX_HPP
#define MINIMAX_HPP

void mejorMovimiento(char tablero[3][3], int& fila, int& columna, char simbolo);
int minimax(char tablero[3][3], int profundidad, bool esMaximizador, int alpha, int beta, char simbolo);

#endif
