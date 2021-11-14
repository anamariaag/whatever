#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"
#include "raymath.h"

#include "Lists.h"
#include "gusanos.h"

#define valorInicial 10



int main() {
    printf("Hello, World!\n");
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    Vector2 pInicial = { 100.0f, 100.0f };
    Vector2 *ptrPosicionInicial=&pInicial;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    List *posiciones = newList();
    List *gusano = newList();

    Color random1=(Color){ GetRandomValue(0, 255), GetRandomValue(0, 255), GetRandomValue(0, 255), 255 };
    for(int i = 0; i<10;i++){//inicializar bloque
        addElement(gusano, newBloque(random1,i));
    }

    for(int i = 0; i<10;i++){//inicializar posiciones
        addElement(posiciones, ptrPosicionInicial);
    }

    Vector2 pMouse;
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        pMouse=GetMousePosition();
        Vector2 *posicion=&pMouse;
        updateListaP(posiciones, posicion);//agrega nueva posicion mouse y quita ultima
        updateGusano(gusano,posiciones);

        //----------------------------------------------------------------------------------
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        for(int i=0;i<valorInicial;i++){
            DrawCircleV(getPosicion(gusano,i), getRadio(gusano,i), getColor(gusano,i));
        }
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}