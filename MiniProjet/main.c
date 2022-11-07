#include <raylib.h>

#include <rlgl.h>
#include <raymath.h>


// Fonction pour generer un nombre aleatoire entre min_num et max_num
int random_number(int min_num, int max_num) {
    int result = 0, low_num = 0, hi_num = 0;

    if (min_num < max_num)
    {
        low_num = min_num;
        hi_num = max_num + 1; // include max_num in output
    } else {
        low_num = max_num + 1; // include max_num in output
        hi_num = min_num;
    }

    // srand(time(NULL));
    result = (rand() % (hi_num - low_num)) + low_num;
    return result;
}


// def DrawGreeny
void DrawGreeny(int centreGreenyX, int centreGreenyY) {
    float rayonGreeny = 10;
    DrawCircle(centreGreenyX, centreGreenyY, rayonGreeny, GREEN);
}

// def DrawObjects
void DrawObjects(int nbreObjets) {
    for (int i=0; i<nbreObjets; i++) {
        int centreX = random_number(800,450);
        int centreY = random_number(800,450);
        float rayon = random_number(5,60);
        int numCouleur = random_number(0,6);
        Color tabCouleurs[] = {YELLOW, BLUE, ORANGE, PINK, PURPLE, RED};
        Color couleur = tabCouleurs [numCouleur];
        DrawCircle(centreX, centreY, rayon, couleur);
    }
}




//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main ()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - 2d camera mouse zoom");

    Camera2D camera = { 0 };
    camera.zoom = 1.0f;

    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second

    const int centreGreenyX = random_number(0,800);
    const int centreGreenyY = random_number(0,450);
    //--------------------------------------------------------------------------------------

    // constantes de position de Greeny

    // Main game loop
    while (!WindowShouldClose())        // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // Translate based on mouse right click
        if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
        {
            Vector2 delta = GetMouseDelta();
            delta = Vector2Scale(delta, -1.0f/camera.zoom);

            camera.target = Vector2Add(camera.target, delta);
        }

        // Zoom based on mouse wheel
        float wheel = GetMouseWheelMove();
        if (wheel != 0)
        {
            // Get the world point that is under the mouse
            Vector2 mouseWorldPos = GetScreenToWorld2D(GetMousePosition(), camera);
            
            // Set the offset to where the mouse is
            camera.offset = GetMousePosition();

            // Set the target to match, so that the camera maps the world space point 
            // under the cursor to the screen space point under the cursor at any zoom
            camera.target = mouseWorldPos;

            // Zoom increment
            const float zoomIncrement = 0.125f;

            camera.zoom += (wheel*zoomIncrement);
            if (camera.zoom < zoomIncrement) camera.zoom = zoomIncrement;
        }

        // Clic sur Greeny
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            //traitement à faire
        }

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            ClearBackground(BLACK);

            BeginMode2D(camera);

                // Draw the 3d grid, rotated 90 degrees and centered around 0,0 
                // just so we have something in the XY plane
                rlPushMatrix();
                    rlTranslatef(0, 25*50, 0);
                    rlRotatef(90, 1, 0, 0);
                    DrawGrid(100, 50);
                rlPopMatrix();

                // Draw a reference circle
                DrawCircle(100, 100, 50, YELLOW);

                // Draw plenty of random (not green) objects
                DrawObjects(500);

                // Draw Greeny
                DrawGreeny(centreGreenyX, centreGreenyY);
                
            EndMode2D();

            DrawText("Où est Greeny ? Mouse right button drag to move, mouse wheel to zoom, mouse left button to click on Greeny", 10, 10, 20, WHITE);
        
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    return 0;
}