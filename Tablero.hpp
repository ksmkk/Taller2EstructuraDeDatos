#ifndef TABLERO_HPP
#define TABLERO_HPP

class Tablero {
private:
    char tablero[3][3];

public:
    Tablero();
    void inicializar();
    void imprimirTablero();
    void menuTablero();
};

#endif
