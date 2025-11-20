#pragma once

const int BOARD_WIDTH = 20;   // ajusta tú
const int BOARD_HEIGHT = 10;  // ajusta tú

void DrawBoard(int headX, int headY, int fruitX, int fruitY,
    int* tailX, int* tailY, int tailLen, int score);
