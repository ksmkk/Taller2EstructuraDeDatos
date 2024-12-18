#include "Tablero.hpp"
#include "Minimax.hpp"
#include <iostream>
#include <limits>

// Constructor
Tablero::Tablero() {
    inicializar();
}

// Inicializar el tablero
void Tablero::inicializar() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tablero[i][j] = ' ';
        }
    }
}

// Imprimir el tablero
void Tablero::imprimirTablero() {
    std::cout << "  0   1   2" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << i << " ";
        for (int j = 0; j < 3; j++) {
            std::cout << tablero[i][j];
            if (j < 2) std::cout << " | ";
        }
        std::cout << std::endl;
        if (i < 2) std::cout << " ---+---+---" << std::endl;
    }
}

// Validar movimiento
bool Tablero::esMovimientoValido(int fila, int columna) {
    return fila >= 0 && fila < 3 && columna >= 0 && columna < 3 && tablero[fila][columna] == ' ';
}

// Evaluar estado del tablero
int Tablero::evaluar(char simbolo) {
    char oponente = (simbolo == 'X') ? 'O' : 'X';

    // Comprobar filas y columnas
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

    // Comprobar diagonales
    if ((tablero[0][0] == simbolo && tablero[1][1] == simbolo && tablero[2][2] == simbolo) ||
        (tablero[0][2] == simbolo && tablero[1][1] == simbolo && tablero[2][0] == simbolo)) {
        return 10;
    }
    if ((tablero[0][0] == oponente && tablero[1][1] == oponente && tablero[2][2] == oponente) ||
        (tablero[0][2] == oponente && tablero[1][1] == oponente && tablero[2][0] == oponente)) {
        return -10;
    }

    // Caso de empate
    return 0;
}

// Verificar empate
bool Tablero::esEmpate() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tablero[i][j] == ' ') return false;
        }
    }
    return true;
}

// Menu principal
void Tablero::menuTablero() {
    bool EsVerdad = true, turnoJugador = true;
    int fila, columna, op;
    char simboloJugador, simboloIA;
    std::string nombre;

    while (EsVerdad) {
        std::cout << "=============== TIC TAC TOE ==============" << std::endl;
        std::cout << "1. Jugar" << std::endl;
        std::cout << "2. Salir" << std::endl;
        std::cout << "> ";
        std::cin >> op;

        switch (op) {
        case 1:
            std::cout << "Ingrese su nombre: ";
            std::cin >> nombre;
            std::cout << "Que simbolo usaras (X, O)? ";
            std::cin >> simboloJugador;
            simboloIA = (simboloJugador == 'X') ? 'O' : 'X';

            while (true) {
                imprimirTablero();

                if (turnoJugador) {
                    std::cout << nombre << " (" << simboloJugador << "), ingresa fila y columna: ";
                    std::cin >> fila >> columna;

                    if (esMovimientoValido(fila, columna)) {
                        tablero[fila][columna] = simboloJugador;

                        if (evaluar(simboloJugador) == 10) {
                            imprimirTablero();
                            std::cout << "Felicidades " << nombre << ", has ganado!" << std::endl;
                            break;
                        }

                        turnoJugador = false;
                    } else {
                        std::cout << "Movimiento invalido. Intenta de nuevo." << std::endl;
                    }
                } else {
                    int mejorFila, mejorColumna;
                    mejorMovimiento(tablero, mejorFila, mejorColumna, simboloIA);
                    tablero[mejorFila][mejorColumna] = simboloIA;

                    if (evaluar(simboloIA) == 10) {
                        imprimirTablero();
                        std::cout << "La IA ha ganado! Mejor suerte la proxima vez, " << nombre << "." << std::endl;
                        break;
                    }

                    turnoJugador = true;
                }

                if (esEmpate()) {
                    imprimirTablero();
                    std::cout << "Es un empate!" << std::endl;
                    break;
                }
            }
            break;

        case 2:
            std::cout << "Hasta luego!" << std::endl;
            EsVerdad = false;
            break;

        default:
            std::cout << "Opcion incorrecta, reintente." << std::endl;
            break;
        }
    }
}
