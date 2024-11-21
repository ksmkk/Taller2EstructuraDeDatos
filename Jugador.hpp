#include <iostream>

class Jugador
{
private:
    std::string nombre;
    char simbolo;
public:
    Jugador(std::string& nombre, char simbolo);
    ~Jugador();
    std::string getNombre();
    char getSimbolo();
    void RealizarMovimiento(char tablero [3][3], int fila, int columna);
    void ObtenerMovimiento(char tablero [3][3], int& fila, int& columna);
    
};