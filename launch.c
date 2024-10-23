#include "raylib.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

int main(void) {
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Rocket Launch");
	SetTargetFPS(60);

	Vector2 rocketPosition = { SCREEN_WIDTH / 2 - 25, SCREEN_HEIGHT - 100 };
	float rocketSpeed = 5.0f;
	
	while (!WindowShouldClose()) {
		//if (rocketPosition.y > 0) {
			rocketPosition.y -= rocketSpeed;
		//}
		
		BeginDrawing();
		ClearBackground(BLACK);

		DrawRectangle(rocketPosition.x, rocketPosition.y, 50, 100, DARKGRAY);

		Vector2 triangleBase = { rocketPosition.x + 25, rocketPosition.y };
		Vector2 triangleLeft = { rocketPosition.x, rocketPosition.y };
		Vector2 triangleRight = { rocketPosition.x + 50, rocketPosition.y };
		Vector2 triangleTop = { triangleBase.x, rocketPosition.y - 50 };

		DrawTriangle(triangleTop, triangleLeft, triangleRight, RED);

		EndDrawing();
	}

	CloseWindow();
	return 0;
}
