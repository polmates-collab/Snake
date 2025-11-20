#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>

#include "Board.h"
#include "keyboard.h"
#include "movement.h"
#include "game_logic.h" 

#define TAIL 100

#define FRAME_RATE 150


// ======= VARIABLES DEL JUEGO =======
int headX, headY;
int fruitX, fruitY;
int tailX[TAIL], tailY[TAIL];
int tailLen;
int score;
bool bGameOver = false;

// Variables para el movimiento (se deben inicializar aquí o en movement.cpp, pero main solo usa la función)
extern int dirX;
extern int dirY;

int main()
{
    srand(time(0)); // Inicializar la semilla para rand()

    // ======= INICIALIZACIÓN =======
    // Serpiente en el centro quieta [cite: 16, 17]
    headX = BOARD_WIDTH / 2;
    headY = BOARD_HEIGHT / 2;

    // Inicializar dirección a 0, 0 para que esté quieta [cite: 17]
    dirX = 0;
    dirY = 0;

    // La fruta se genera automáticamente al inicio (uso la función SpawnFruit por modularidad)
    tailLen = 0;
    SpawnFruit(fruitX, fruitY, BOARD_WIDTH, BOARD_HEIGHT, tailX, tailY, tailLen);

    score = 0;

    // ======= GAME LOOP =======
    while (!bGameOver)
    {
        int prevHeadX = headX;
        int prevHeadY = headY;

        // 1. DIBUJAR TABLERO
        DrawBoard(headX, headY, fruitX, fruitY, tailX, tailY, tailLen, score);

        // 2. ACTUALIZAR MOVIMIENTO
        // Actualiza la dirección y la posición de la cabeza
        UpdateMovement(headX, headY);

        // 3. ACTUALIZAR COLA (Solo si hay movimiento)
        // La cola no sigue si la serpiente está estática (dirX/dirY == 0)
        if (dirX != 0 || dirY != 0)
        {
            UpdateTail(prevHeadX, prevHeadY, tailX, tailY, tailLen);
        }

        // 4. COMPROBAR COLISIONES (Game Over)
        if (CheckCollision(headX, headY, BOARD_WIDTH, BOARD_HEIGHT, tailX, tailY, tailLen))
        {
            bGameOver = true;
        }

        // 5. COMPROBAR FRUTA
        CheckFruit(headX, headY, fruitX, fruitY, BOARD_WIDTH, BOARD_HEIGHT, tailX, tailY, tailLen, score);

        // 6. ACTUALIZAR PUNTUACIÓN (solo si no es Game Over)
        if (!bGameOver)
        {
            UpdateScore(score, tailLen);
        }

        // 7. CONTROL DE VELOCIDAD
        std::this_thread::sleep_for(std::chrono::milliseconds(FRAME_RATE));
    }

    // Al finalizar el juego
    system("cls");
    std::cout << " Game over \n";

    std::cout << "\n   Puntuacion final: " << score << "\n\n";

    return 0;
}