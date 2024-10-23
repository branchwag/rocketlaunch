#include "raylib.h"
#include <math.h>
#include <stdlib.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

int main(void) {
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Rocket Launch");
	SetTargetFPS(60);

	Vector2 rocketPosition = { SCREEN_WIDTH / 2 - 25, SCREEN_HEIGHT - 100 };
	float rocketSpeed = 5.0f;

	float flameHeight = 40.0f;
	float flameWidth = 30.0f;
	float flameOffset = 0.0f;
	float flameSpeed = 0.2f;
	
	while (!WindowShouldClose()) {
		//if (rocketPosition.y > 0) {
			rocketPosition.y -= rocketSpeed;
		//}

		flameOffset += flameSpeed;
		float currentFlameHeight = flameHeight + sinf(flameOffset) * 10.0f;
		
		BeginDrawing();
		ClearBackground(BLACK);

		//rocket
		DrawRectangle(rocketPosition.x, rocketPosition.y, 50, 100, DARKGRAY);

		Vector2 triangleBase = { rocketPosition.x + 25, rocketPosition.y };
		Vector2 triangleLeft = { rocketPosition.x, rocketPosition.y };
		Vector2 triangleRight = { rocketPosition.x + 50, rocketPosition.y };
		Vector2 triangleTop = { triangleBase.x, rocketPosition.y - 50 };
		DrawTriangle(triangleTop, triangleLeft, triangleRight, RED);

		//flames
		Vector2 flameTop = { rocketPosition.x + 25, rocketPosition.y + 100 };  // Bottom center of rocket
		Vector2 flameLeft = { rocketPosition.x + 10, rocketPosition.y + 100 + currentFlameHeight };
		Vector2 flameRight = { rocketPosition.x + 40, rocketPosition.y + 100 + currentFlameHeight };
		DrawTriangle(flameTop, flameLeft, flameRight, ORANGE);
		
		Vector2 innerFlameTop = flameTop;
		Vector2 innerFlameLeft = { rocketPosition.x + 17, rocketPosition.y + 100 + currentFlameHeight * 0.7f };
		Vector2 innerFlameRight = { rocketPosition.x + 33, rocketPosition.y + 100 + currentFlameHeight * 0.7f };
		DrawTriangle(innerFlameTop, innerFlameLeft, innerFlameRight, YELLOW);
		
		float sideFlameHeight = currentFlameHeight * 0.6f;
		
		Vector2 leftFlameTop = { rocketPosition.x + 10, rocketPosition.y + 100 };
		Vector2 leftFlameLeft = { rocketPosition.x, rocketPosition.y + 100 + sideFlameHeight };
		Vector2 leftFlameRight = { rocketPosition.x + 20, rocketPosition.y + 100 + sideFlameHeight };
		DrawTriangle(leftFlameTop, leftFlameLeft, leftFlameRight, RED);
		
		Vector2 rightFlameTop = { rocketPosition.x + 40, rocketPosition.y + 100 };
		Vector2 rightFlameLeft = { rocketPosition.x + 30, rocketPosition.y + 100 + sideFlameHeight };
		Vector2 rightFlameRight = { rocketPosition.x + 50, rocketPosition.y + 100 + sideFlameHeight };
		DrawTriangle(rightFlameTop, rightFlameLeft, rightFlameRight, RED);

		EndDrawing();
	}

	CloseWindow();
	return 0;
}
