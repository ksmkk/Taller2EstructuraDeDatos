#ifndef MINIMAX_HPP
#define MINIMAX_HPP

int evaluar(char tablero[3][3], char simbolo);
int minimax(char tablero[3][3], bool profundida, char simboloIA, char simboloJugador);
void mejorMovimiento(char tablero[3][3], int& fila, int& columna, char simbolo);
bool esEmpate(char tablero[3][3]);

#endif
