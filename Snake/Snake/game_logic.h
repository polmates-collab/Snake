#pragma once

// Funciones para la lógica del juego (Gameplay)
void CheckFruit(int headX, int headY, int& fruitX, int& fruitY, int boardW, int boardH, int* tailX, int* tailY, int& tailLen, int& score);
bool CheckCollision(int headX, int headY, int boardW, int boardH, const int* tailX, const int* tailY, int tailLen);
void UpdateScore(int& score, int tailLen);
void SpawnFruit(int& fruitX, int& fruitY, int boardW, int boardH, const int* tailX, const int* tailY, int tailLen);