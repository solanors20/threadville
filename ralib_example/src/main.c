#include "raylib.h"

#define SQUARE_GRID_SIZE 20

typedef struct Bus
{
    Vector2 position;
    Vector2 size;
    Vector2 speed;
    Color color;
} Bus;


static const int villeWidth = 400;
static const int villeHeight = 200;
static Bus bus = {0};

static Vector2 offset = {0};

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 400;

    InitWindow(screenWidth, screenHeight, "Threadville");

    SetTargetFPS(2); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    offset.x = villeWidth % (SQUARE_GRID_SIZE*2);
    offset.y = villeHeight % (SQUARE_GRID_SIZE*2);

    bus.position = (Vector2){ 0, offset.y };
    bus.size = (Vector2){ SQUARE_GRID_SIZE*2, SQUARE_GRID_SIZE };
    bus.speed = (Vector2){ SQUARE_GRID_SIZE*2, 0 };
    bus.color = RED;
    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        bus.position.x += bus.speed.x;
        bus.position.y += bus.speed.y;

        if(bus.position.x >= (villeWidth - offset.x))
        {
            bus.speed = (Vector2){ 0, SQUARE_GRID_SIZE*2 };
            bus.size = (Vector2){ SQUARE_GRID_SIZE, SQUARE_GRID_SIZE*2 };
        }
        

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        // Draw grid lines
        for (int i = 0; i < villeWidth / SQUARE_GRID_SIZE + 1; i++)
        {
            DrawLineV(
                (Vector2){SQUARE_GRID_SIZE * i + offset.x / 2, offset.y / 2},
                (Vector2){SQUARE_GRID_SIZE * i + offset.x / 2, villeHeight - offset.y / 2},
                LIGHTGRAY);
        }

        for (int i = 0; i < villeHeight / SQUARE_GRID_SIZE + 1; i++)
        {
            DrawLineV(
                (Vector2){offset.x / 2, SQUARE_GRID_SIZE * i + offset.y / 2},
                (Vector2){villeWidth - offset.x / 2, SQUARE_GRID_SIZE * i + offset.y / 2},
                LIGHTGRAY);
        }

        DrawRectangleV(bus.position, bus.size, bus.color);

        EndDrawing();
        //------------------------------Congrats! You created your first window!----------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}