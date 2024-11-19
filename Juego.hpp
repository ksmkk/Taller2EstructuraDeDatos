#include <iostream>
#include "Tablero.hpp";

class Juego {
private:
    Tablero tablero;
    char jugador1 , jugador2;
public:
    Juego();
    void iniciar();
    ~Juego();
};