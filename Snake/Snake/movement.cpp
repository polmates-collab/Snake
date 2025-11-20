#include "movement.h"
#include "keyboard.h"



// Variables internas para recordar la última dirección
int dirX = 0;
int dirY = 0;

void UpdateMovement(int& headX, int& headY)
{
    // === DETECTAR INPUT Y ACTUALIZAR DIRECCIÓN ===
    // La serpiente una vez iniciado el movimiento ya no se para.
    // Solo actualizamos la dirección si se pulsa una tecla.
    if (IsWPressed()) { dirX = 0;  dirY = -1; }
    else if (IsSPressed()) { dirX = 0;  dirY = 1; }
    else if (IsAPressed()) { dirX = -1; dirY = 0; }
    else if (IsDPressed()) { dirX = 1;  dirY = 0; }

    // === MOVER LA CABEZA ===
    headX += dirX;
    headY += dirY;
}

// Mueve la cola para seguir a la cabeza
void UpdateTail(int prevHeadX, int prevHeadY, int* tailX, int* tailY, int tailLen)
{
    // Mover todos los elementos de la cola un paso adelante (el último desaparece)
    for (int i = tailLen - 1; i > 0; i--)
    {
        tailX[i] = tailX[i - 1];
        tailY[i] = tailY[i - 1];
    }
    // El primer segmento de la cola toma la posición anterior de la cabeza.
    if (tailLen > 0)
    {
        tailX[0] = prevHeadX;
        tailY[0] = prevHeadY;
    }
}