#include "Board.h"
#include <iostream>



void DrawBoard(int headX, int headY, int fruitX, int fruitY,
    int* tailX, int* tailY, int tailLen, int score)
{
    system("cls");

    // ======= BORDE SUPERIOR =======
    for (int i = 0; i < BOARD_WIDTH + 2; i++)
        std::cout << "-";
    std::cout << "\n";

    // ======= INTERIOR DEL TABLERO =======
    for (int y = 0; y < BOARD_HEIGHT; y++)
    {
        std::cout << "|"; // pared izquierda

        for (int x = 0; x < BOARD_WIDTH; x++)
        {
            // 1. Cabeza
            if (x == headX && y == headY)
            {
                std::cout << "X";
                continue;
            }

            // 2. Fruta
            if (x == fruitX && y == fruitY)
            {
                std::cout << "O";
                continue;
            }

            // 3. Cola de la serpiente
            bool printedTail = false;
            for (int i = 0; i < tailLen; i++)
            {
                if (tailX[i] == x && tailY[i] == y)
                {
                    std::cout << "x";
                    printedTail = true;
                    break;
                }
            }

            if (printedTail)
                continue;

            // 4. Espacio vacío
            std::cout << " ";
        }

        std::cout << "|\n"; // pared derecha
    }

    // ======= BORDE INFERIOR =======
    for (int i = 0; i < BOARD_WIDTH + 2; i++)
        std::cout << "-";
    std::cout << "\n";

    // ======= SCORE =======
    std::cout << "Score: " << score << "\n";
}
