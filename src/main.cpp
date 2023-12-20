#include "ai-paddle.h"

using namespace std;

Ball ball;
PlayerPaddle player;
playerAi opponent;


int main()
{
    cout << "Starting the game " << endl;

    //set screen width height and title
    const int screenWidth = 1080;
    const int screenHeight = 800;
    const char _title[20] = {"Pong"};

    //initilize window 
    InitWindow(screenWidth, screenHeight, _title);
    SetTargetFPS(60);


    //ball properties
    ball.radius =20;
    ball.x = screenWidth/2;
    ball.y = screenHeight/2;
    ball.speed_x = 7;
    ball.speed_y = 7;

    //player properties 
    player.width = 25;
    player.height = 120;
    player.x = screenWidth - player.width - 10;
    player.y = screenHeight /2 - player.height /3;
    player.speed = 9;

    //opponent ai properties 
    opponent.height = 120;
    opponent.width = 25;
    opponent.x = 10;
    opponent.y = screenHeight/2 - opponent.height/2;
    opponent.speed = 6;



    //main game loop
    while(WindowShouldClose()== false)
    {
        BeginDrawing();

        //update 
        ball.UpdateBall();
        player.updatePlayer();
        opponent.updateAi(ball.y);

        //Drawing
        ClearBackground(BLACK);
        //Draw center line 
        DrawLine(screenWidth/ 2 ,0 , screenWidth /2, screenHeight, WHITE);
        ball.DrawBall();

        //drawCircle
        DrawCircle(screenWidth/2, screenHeight/2, 30, WHITE);
        opponent.DrawPaddle();
        player.DrawPaddle();


        EndDrawing();
    }


    //close window
    CloseWindow();
    return 0;

}