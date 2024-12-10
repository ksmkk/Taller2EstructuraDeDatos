![image](https://github.com/user-attachments/assets/40d4af88-55cb-47ed-888e-b36387d80bc1)# Taller 2 - Estructura de Datos: Implementación del Algoritmo Minimax con Poda Alfa-Beta en un Juego
*Descripción*
Este proyecto implementa un agente inteligente para un juego clásico de tablero utilizando el algoritmo Minimax y su optimización mediante Poda Alfa-Beta. Como caso base, se desarrolló el juego del gato (tic-tac-toe), donde los jugadores compiten por completar tres casillas en línea.

El objetivo principal es demostrar el funcionamiento del algoritmo y su impacto en la toma de decisiones estratégicas.

# Integrantes
Bastián Salinas

RUT: 21.848.994-K
Correo: bastian.salinas01@alumnos.ucn.cl
Paralelo: C1
Tomás Guerra

RUT: 21.664.344-5
Correo: tomas.guerra@alumnos.ucn.cl
Paralelo: C1
# Requisitos Técnicos
Lenguaje de programación: C++
Compilador: g++
Organización: Código modular con archivos .cpp y .h.
Gestión de memoria: Uso de punteros y arrays estáticos.
Ejecución del Programa
# Compilación:
Usa el siguiente comando para compilar el programa:
g++ -o TicTac Minimax.cpp Juego.cpp Tablero.cpp main.cpp
Ejecución:
./TicTac.exe

# Implementación
1. Introducción al Algoritmo Minimax
El algoritmo Minimax se utiliza para tomar decisiones óptimas en juegos de dos jugadores. Se basa en maximizar las ganancias para un jugador mientras minimiza las del oponente, recorriendo todas las posibles configuraciones del tablero.

Poda Alfa-Beta: Optimización que reduce los nodos explorados, descartando ramas que no influyen en la decisión final.
2. Componentes del Juego
Clase Tablero: Representa el estado del juego y verifica las condiciones de victoria o empate.
Clase Juego: Controla la lógica del juego y el flujo entre los turnos.
Algoritmo Minimax: Implementa la lógica de la IA para realizar movimientos estratégicos.
3. Interfaz
La interfaz es en consola, permitiendo:

Jugar contra la IA.
Visualizar el estado del tablero en cada turno.
Ver cómo la IA toma decisiones estratégicas.

Análisis de Complejidad
Minimax sin Poda: 
𝑂
(
𝑏
𝑑
)
O(b 
d
 ), donde 
𝑏
b es el factor de ramificación y 
𝑑
d la profundidad máxima del árbol.
Minimax con Poda Alfa-Beta: 
𝑂
(
𝑏
𝑑
/
2
)
O(b 
d/2
 ) en el mejor caso, reduciendo significativamente los nodos explorados.
