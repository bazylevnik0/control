#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "control");
    int display = GetCurrentMonitor();
    SetWindowSize(GetMonitorWidth(display), GetMonitorHeight(display));
    SetWindowPosition(0,0);
    // Initialize audio device
    InitAudioDevice(); 

    // Define the camera to look into our 3d world
    Camera camera = { 0 };
    camera.position = (Vector3){ 0.0f, 0.0f, 10.0f }; // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera mode type

    // Loaf gltf models
    Model model_main = LoadModel("src/main.glb");
    Model model_top = LoadModel("src/top.glb");
    Model model_bottom = LoadModel("src/bottom.glb");

    Vector3 position_main          = {  0.0f,  0.0f, 0.0f };    // Set model position
    Vector3 position_top_left      = { -2.0f,  1.0f, 0.0f };    // Set model position
    Vector3 position_top_right     = {  2.0f,  1.0f, 0.0f };    // Set model position
    Vector3 position_bottom_left   = { -2.0f, -1.5f, 0.0f };    // Set model position
    Vector3 position_bottom_right  = {  2.0f, -1.5f, 0.0f };    // Set model position

    // Load sounds
    Sound sound = LoadSound("key.wav"); 

    SetCameraMode(camera, CAMERA_FREE); // Set free camera mode

    SetTargetFPS(85);                   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Prepare file for reading
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("key_temp", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    //play sound theme
    PlaySound(sound);
    // Main game loop
    while ((read = getline(&line, &len, fp)) != -1)       
    {
        // Update
        //----------------------------------------------------------------------------------
        UpdateCamera(&camera);
        float temp = strtof(line, NULL);
        position_main.y         =  0.0 + (temp/50);
        position_top_left.y     =  1.0 + (temp/50);
        position_top_right.y    =  1.0 + (temp/50);
        position_top_left.x     = -2.0 - (temp/50);
        position_top_right.x    =  2.0 + (temp/50);
        position_bottom_left.x  = -2.0 - (temp/25);
        position_bottom_right.x =  2.0 + (temp/25);
        position_bottom_left.y  = -1.5 - (temp/25);
        position_bottom_right.y = -1.5 - (temp/25);
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BLACK);

            BeginMode3D(camera);

                DrawModel(model_main  , position_main        , 1.0f, WHITE);
                DrawModel(model_top   , position_top_left    , 1.0f, WHITE);
                DrawModel(model_top   , position_top_right   , 1.0f, WHITE);
                DrawModel(model_bottom, position_bottom_left , 1.0f, WHITE);
                DrawModel(model_bottom, position_bottom_right, 1.0f, WHITE);
                DrawGrid(10, 1.0f);         // Draw a grid

            EndMode3D();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadModel(model_main);         // Unload model and meshes/material
    UnloadModel(model_top);         // Unload model and meshes/material
    UnloadModel(model_bottom);         // Unload model and meshes/material
    
    CloseWindow();              // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}