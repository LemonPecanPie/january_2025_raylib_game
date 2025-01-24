/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit https://creativecommons.org/publicdomain/zero/1.0/

*/

#include "raylib.h"

#include "resource_dir.h" // utility header for SearchAndSetResourceDir

int main()
{

	const int screenWidth = 800;
	const int screenHeight = 450;

	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(screenWidth, screenHeight, "Hello Raylib");

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

	// Load a texture from the resources directory
	Texture wabbit = LoadTexture("wabbit_alpha.png");

	Vector2 ballPosition = {(float)screenWidth / 2, (float)screenHeight / 2};

	SetTargetFPS(60);

	// game loop
	while (!WindowShouldClose()) // run the loop untill the user presses ESCAPE or presses the Close button on the window
	{

		// Update

		if (IsKeyDown(KEY_RIGHT))
			ballPosition.x += 2.0f;
		if (IsKeyDown(KEY_LEFT))
			ballPosition.x -= 2.0f;
		if (IsKeyDown(KEY_UP))
			ballPosition.y -= 2.0f;
		if (IsKeyDown(KEY_DOWN))
			ballPosition.y += 2.0f;

		// drawing
		BeginDrawing();

		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(BLACK);

		// draw some text using the default font
		DrawText("Hello Raylib", 200, 200, 20, WHITE);

		// draw our texture to the screen
		DrawTextureV(wabbit, ballPosition, WHITE);

		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}

	// cleanup
	// unload our texture so it can be cleaned up
	UnloadTexture(wabbit);

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
