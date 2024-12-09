#include "Tablero.hpp"
#include <iostream>

Tablero::Tablero() {
}

void Tablero::inicializar() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tablero[i][j] = ' ';
        }
    }
}



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
void Tablero::menuTablero(){
    bool EsVerdad = true;
    int fila, columna, op = 0;
    char simbolo; 
    
    while (EsVerdad)
    {
        std::cout << "===============TIC TAC==================" << std::endl;
        std::cout << " " << std::endl;
        std::cout << "Ingrese una opcion: " << std::endl;
        std::cout << "1. Jugar" << std::endl;
        std::cout << "2. Salir" << std::endl;
        std::cout << "> ";
        std::cin >> op;
    }
    
    
    switch (op)
    {
    case 1:
        std::cout<<"¿Que simbolo usaras (X , O)?"<<std::endl;
        std::cin >> simbolo;
        std::cout<< "Ingresa fila: "<<std::endl;
        std::cin>> fila;
        std::cout<<"Ingrese columna: "<<std::endl;
        std::cin>>columna;

        break;
    case 2:
        std::cout<<"Hasta Luego!"<<std::endl;
        EsVerdad = false;
    
    default:
        std::cout << "Opcion incorrecta, Reingrese:" << std::endl;
        break;
    }
}
