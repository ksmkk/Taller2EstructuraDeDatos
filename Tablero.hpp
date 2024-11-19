#include <iostream>;

class Tablero {
private:
    char tablero[3][3];

public:
    Tablero();
    void inicializar();
    void imprimirTablero();
    ~Tablero();
};