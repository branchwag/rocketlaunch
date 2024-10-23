#include "raylib.h"
#include <math.h>
#include <stdlib.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800
#define MAX_SMOKE_PARTICLES 100

typedef struct {
	Vector2 position;
	float radius;
	float alpha;
	float speedX;
	float speedY;
} SmokeParticle;

int main(void) {
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Rocket Launch");
	SetTargetFPS(60);

	Vector2 rocketPosition = { SCREEN_WIDTH / 2 - 25, SCREEN_HEIGHT - 130 };
	float rocketSpeed = 5.0f;

	float flameHeight = 40.0f;
	float flameWidth = 30.0f;
	float flameOffset = 0.0f;
	float flameSpeed = 0.2f;

	SmokeParticle smoke[MAX_SMOKE_PARTICLES]  = { 0 };
	int nextSmoke = 0;

	for (int i = 0; i < MAX_SMOKE_PARTICLES; i++) {
		smoke[i].alpha = 0;
	}
	
	while (!WindowShouldClose()) {
		rocketPosition.y -= rocketSpeed;
		
		if (rocketPosition.y > 0) {

		if (smoke[nextSmoke].alpha <= 0) {
		    smoke[nextSmoke].position = (Vector2){
                    rocketPosition.x + 25 + GetRandomValue(-20, 20),
                    rocketPosition.y + 100 + GetRandomValue(0, 20)
                };
		     smoke[nextSmoke].speedX = GetRandomValue(-100, 100) / 100.0f;
		     smoke[nextSmoke].speedY = GetRandomValue(100, 200) / 100.0f;
		     smoke[nextSmoke].radius = GetRandomValue(10, 30);
		     smoke[nextSmoke].alpha = 0.7f;
		     nextSmoke = (nextSmoke + 1) % MAX_SMOKE_PARTICLES;
		  }
		}

		flameOffset += flameSpeed;
		float currentFlameHeight = flameHeight + sinf(flameOffset) * 10.0f;

		for (int i = 0; i < MAX_SMOKE_PARTICLES; i++) {
			if (smoke[i].alpha > 0) {
				smoke[i].position.x += smoke[i].speedX;
				smoke[i].position.y += smoke[i].speedY;
				smoke[i].alpha -= 0.01f;
				smoke[i].radius += 0.2f;
			}
		}
				
		
		BeginDrawing();
		ClearBackground(BLACK);

		for (int i = 0; i < MAX_SMOKE_PARTICLES; i++) {
			if (smoke[i].alpha > 0) {
				DrawCircleV(smoke[i].position, smoke[i].radius, Fade(LIGHTGRAY, smoke[i].alpha));
			}
		}

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
