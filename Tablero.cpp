#include "Tablero.hpp"

void Tablero::inicializar() {
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tablero[i][j] = ' ';
        }
        
    }
    
}