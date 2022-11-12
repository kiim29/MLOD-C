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
    float rayonGreeny = 25;
    DrawCircle(centreGreenyX, centreGreenyY, rayonGreeny, GREEN);
}

// def DrawObjects
void DrawObjects(int centresX[], int centresY[], float rayons[], Color couleurs[]) {
    for (int i=0; i<2000; i++) {
        int centreX = centresX[i];
        int centreY = centresY[i];
        float rayon = rayons[i];
        Color couleur = couleurs[i];
        DrawCircle(centreX, centreY, rayon, couleur);
    }
}




//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main () {
    
    // INITIALISATION
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - 2d camera mouse zoom");

    Camera2D camera = { 0 };
    camera.zoom = 1.0f;

    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second


    // INITIALISATION DE GREENY : constantes de position de Greeny
    const int centreGreenyX = random_number(0,800);
    const int centreGreenyY = random_number(0,450);


    // INITIALISATION DES OBJETS : constantes de position et caractéristiques des objets aléatoires
    const int nbrObjets = 2000;
    int centresCerclesX[nbrObjets];
    int centresCerclesY[nbrObjets];
    float rayonsCercles[nbrObjets];
    Color couleursCercles[nbrObjets];
    Color tabCouleurs[] = {YELLOW, BLUE, ORANGE, PINK, PURPLE, RED};
    for (int i=0; i<nbrObjets; i++) {
        centresCerclesX[i] = random_number(-2400,2400);
        centresCerclesY[i] = random_number(-1200,1200);
        rayonsCercles[i] = random_number(10,100);
        int numCouleur = random_number(0,5);
        couleursCercles[i] = tabCouleurs [numCouleur];
    }
    //--------------------------------------------------------------------------------------





    // Main game loop
    while (!WindowShouldClose()) {         // Detect window close button or ESC key

        // Update
        //----------------------------------------------------------------------------------
        // Translate based on mouse right click
        if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
            Vector2 delta = GetMouseDelta();
            delta = Vector2Scale(delta, -1.0f/camera.zoom);

            camera.target = Vector2Add(camera.target, delta);
        }

        // Zoom based on mouse wheel
        float wheel = GetMouseWheelMove();
        if (wheel != 0) {
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

                // Draw plenty of random (not green) objects
                DrawObjects(centresCerclesX, centresCerclesY, rayonsCercles, couleursCercles);

                // Draw Greeny
                // DrawGreeny(centreGreenyX, centreGreenyY);
                DrawGreeny(0, 0);
                
            EndMode2D();

            DrawText("Où est Greeny ? \nMouse right button drag to move, mouse wheel to zoom. \nMouse left button to click on Greeny.", 10, 10, 20, WHITE);
        
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    return 0;
}