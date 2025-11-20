#include "game_logic.h"
#include <cstdlib>
#include <cmath>

#define FRUTA 15

// Implementación de SpawnFruit para el centro y la aleatoriedad
void SpawnFruit(int& fruitX, int& fruitY, int boardW, int boardH, const int* tailX, const int* tailY, int tailLen)
{
    // Generar la fruta en una posición aleatoria y libre
    do {
        fruitX = rand() % boardW;
        fruitY = rand() % boardH;

        // Comprobar que no spawnee en la cola.
        bool isColliding = false;
        for (int i = 0; i < tailLen; i++)
        {
            if (tailX[i] == fruitX && tailY[i] == fruitY)
            {
                isColliding = true;
                break;
            }
        }
        if (!isColliding) return;

    } while (true);
}

void CheckFruit(int headX, int headY, int& fruitX, int& fruitY, int boardW, int boardH, int* tailX, int* tailY, int& tailLen, int& score)
{
    if (headX == fruitX && headY == fruitY)
    {
        // La longitud de la serpiente crece en uno [cite: 47]
        tailLen++;
        // Gana 15 puntos por fruta comida [cite: 51]
        score += FRUTA;

        SpawnFruit(fruitX, fruitY, boardW, boardH, tailX, tailY, tailLen);
    }
}

bool CheckCollision(int headX, int headY, int boardW, int boardH, const int* tailX, const int* tailY, int tailLen)
{
    // Toca los límites del mapa [cite: 49]
    if (headX < 0 || headX >= boardW || headY < 0 || headY >= boardH)
    {
        return true;
    }

    // Toca su cuerpo [cite: 48]
    for (int i = 0; i < tailLen; i++)
    {
        if (headX == tailX[i] && headY == tailY[i])
        {
            return true;
        }
    }

    return false;
}

void UpdateScore(int& score, int tailLen)
{
    // Cada frame que el jugador siga vivo ganará 1 punto por cantidad de elementos tenga la cola [cite: 50]
    score += tailLen;
}