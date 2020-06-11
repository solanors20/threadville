#include "raylib.h"

#define SQUARE_GRID_SIZE 20
#define BUS_SIZE 40

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

    SetTargetFPS(5); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    offset.x = villeWidth % (SQUARE_GRID_SIZE);
    offset.y = villeHeight % (SQUARE_GRID_SIZE);
    TraceLog(LOG_INFO, "offset.x: %f", offset.x);
    TraceLog(LOG_INFO, "offset.y: %f", offset.y);

    bus.position = (Vector2){ 0, 0 };
    bus.size = (Vector2){ BUS_SIZE, SQUARE_GRID_SIZE };
    bus.speed = (Vector2){ SQUARE_GRID_SIZE, 0 };
    bus.color = RED;
    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        TraceLog(LOG_INFO, "bus.position.x: %f", bus.position.x);
        TraceLog(LOG_INFO, "bus.position.y: %f", bus.position.y);
        if(bus.position.x >= (villeWidth - (BUS_SIZE)) && (bus.speed.y == 0))
        {
            bus.speed = (Vector2){ 0, SQUARE_GRID_SIZE };
            bus.size = (Vector2){ SQUARE_GRID_SIZE, BUS_SIZE };
            bus.position.x += SQUARE_GRID_SIZE;
            bus.position.y -= SQUARE_GRID_SIZE;
        }

        else if(bus.position.y >= (villeHeight - (BUS_SIZE)) && (bus.speed.x == 0))
        {
            bus.speed = (Vector2){  -1*SQUARE_GRID_SIZE, 0 };
            bus.size = (Vector2){ BUS_SIZE, SQUARE_GRID_SIZE };
            bus.position.x -= SQUARE_GRID_SIZE;
            bus.position.y += SQUARE_GRID_SIZE;
        }

        else if((bus.position.x < 0) && (bus.speed.y == 0))
        {
            bus.speed = (Vector2){ 0, -SQUARE_GRID_SIZE };
            bus.size = (Vector2){ SQUARE_GRID_SIZE, BUS_SIZE };
            bus.position.x += SQUARE_GRID_SIZE;
            bus.position.y -= SQUARE_GRID_SIZE;
        }

        else if((bus.position.y < 0) && (bus.speed.x == 0))
        {
            bus.speed = (Vector2){  SQUARE_GRID_SIZE, 0 };
            bus.size = (Vector2){ BUS_SIZE, SQUARE_GRID_SIZE };
            bus.position.x -= SQUARE_GRID_SIZE;
            bus.position.y += SQUARE_GRID_SIZE;
        }

        bus.position.x += bus.speed.x;
        bus.position.y += bus.speed.y;

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        // Draw grid lines
        for (int i = 0; i < villeWidth / SQUARE_GRID_SIZE + 1; i++)
        {
            DrawLineV(
                (Vector2){SQUARE_GRID_SIZE * i, 0},
                (Vector2){SQUARE_GRID_SIZE * i, villeHeight},
                LIGHTGRAY);
        }

        for (int i = 0; i < villeHeight / SQUARE_GRID_SIZE + 1; i++)
        {
            DrawLineV(
                (Vector2){0, SQUARE_GRID_SIZE * i},
                (Vector2){villeWidth, SQUARE_GRID_SIZE * i },
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