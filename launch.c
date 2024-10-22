#include "raylib.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

int main(void) {
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Rocket Launch");
	SetTargetFPS(60);

	Vector2 rocketPosition = { SCREEN_WIDTH / 2 - 25, SCREEN_HEIGHT - 130 };
	float rocketSpeed = 5.0f;
	
	while (!WindowShouldClose()) {
		if (rocketPosition.y > 0) {
			rocketPosition.y -= rocketSpeed;
		}
		
		BeginDrawing();
		ClearBackground(BLACK);

		DrawRectangle(rocketPosition.x, rocketPosition.y, 50, 100, DARKGRAY);
		DrawTriangle((Vector2){ 400, 200 }, (Vector2){ 300, 600}, (Vector2){ 500, 600 }, RED);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
