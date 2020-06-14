#include "raylib.h"
#include "raymath.h"
#include <time.h>

#define SQUARE_GRID_SIZE 20
#define BUS_SIZE 40

typedef struct Bus
{
    Vector2 position;
    Vector2 size;
    Vector2 speed;
    Color color;
} Bus;

static const int villeWidth = 960;
static const int villeHeight = 200;
static Bus bus = {0};

Vector2 Vector2Multiply2(Vector2 v1, Vector2 v2)
{
    Vector2 result = {v1.x * v2.x, v1.y * v2.y};
    return result;
}

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1000;
    const int screenHeight = 400;

    InitWindow(screenWidth, screenHeight, "Threadville");

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    bus.position = (Vector2){0, 0};
    bus.size = (Vector2){BUS_SIZE, SQUARE_GRID_SIZE};
    bus.speed = (Vector2){SQUARE_GRID_SIZE, 0};
    bus.color = RED;

    Vector2 target_right = {(villeWidth - (BUS_SIZE)), 0};
    Vector2 target_down = {(villeWidth - (BUS_SIZE)), (villeHeight - (BUS_SIZE))};

    Vector2 normalize = {0};

    float acceleration = 48 / 5;

    float velocity = 0;
    int framesCounter = 0;
    float deltaTime = 0;

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        //TraceLog(LOG_INFO, "bus.position.x: %f", bus.position.x);
        //TraceLog(LOG_INFO, "bus.position.y: %f", bus.position.y);
        framesCounter++;

        deltaTime = GetFrameTime();

        Vector2 b_to_t = Vector2Subtract(target_right, bus.position);

        normalize = Vector2Normalize(b_to_t);

        TraceLog(LOG_INFO, "normalize");
        TraceLog(LOG_INFO, "x=%f, y=%f", normalize.x, normalize.y);
        TraceLog(LOG_INFO, "magnitude=%f", Vector2Length(normalize));

        if (bus.position.x <= (villeWidth - (BUS_SIZE)))
        {
            TraceLog(LOG_INFO, "delta: %f", deltaTime);
            bus.position.x += SQUARE_GRID_SIZE * deltaTime * acceleration * normalize.x;

            Vector2 vr = Vector2Rotate(normalize, 270);
            TraceLog(LOG_INFO, "\t vr.x: %f vr.y: %f\n", vr.x, vr.y);
        }

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
                (Vector2){villeWidth, SQUARE_GRID_SIZE * i},
                LIGHTGRAY);
        }

        DrawRectangleV(bus.position, bus.size, bus.color);

        DrawText(FormatText("framesCounter/sec: %i", framesCounter / 60), 0, 300, 14, GREEN);

        EndDrawing();
        //------------------------------Congrats! You created your first window!----------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
