/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "tObjectPools.h"
#include <time.h>

int main()
{
	srand(time(NULL));
	
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");


	tObjectPool<Texture2D> * meteors = new tObjectPool<Texture2D>;
	meteors->setObject(LoadTexture("resources/spaceMeteors_001.png"));
	meteors->setSize(80);
	SetTargetFPS(60);
	while (!WindowShouldClose()){
		BeginDrawing();
		ClearBackground(BLACK);

		meteors->Draw();
		meteors->updateClicked();


		EndDrawing();
	}

	CloseWindow();

	return 0;
}