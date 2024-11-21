#include "Tablero.hpp"

Tablero::Tablero() {

}

void Tablero::inicializar() {
    char pieza;
    bool EsVerdad = true;
    int opcion;

    while (EsVerdad)
    {
        std::cout << "========BIENVENIDO========="<<std::endl;
        std::cout << "1. Jugar"<<std::endl;
        std::cout << "2. Salir "<<std::endl;
        std::cout << ">";
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
            std::cout << "Elija un simbolo para jugar (X o O):"<<std::endl;
            break;
        
        default:
            std::cout << "Opción incorrecta, Reintente."<<std::endl;
            break;
        }
    }
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tablero[i][j] = 'x';
        }
        
    }
    
}
void Tablero::imprimirTablero(){
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