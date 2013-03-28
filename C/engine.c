#include "circle.h"
#include "engine.h"

extern int xOffset = 5;
extern int yOffset = 5;


struct circle* createBall() {
  *ball = malloc(sizeof (struct circle));

  ball->xPos = 370;
  ball->yPos = 200;

  return ball;
}


void updatePosition(Ball, World) {
  Ball.x = (Ball.x + Ball.xVel)
  Ball.y = (Ball.y + Ball.yVel)

  checkBounds(Ball, World);
}

void checkBounds(Ball, World) {

  // Right wall
  if(Ball.x >= World.width) {
    Ball.x = World.width - 2*Ball.radius - 1;
    Ball.xVel *= -1;
  }

  // Left wall
  if (Ball.x <= 0) {
    Ball.x += 1;
    Ball.xVel *= -1;
  }

  // Floor
  if(Ball.y <= 0) {
    Ball.y += 1;
    Ball.yVel *= -1;
  }

  // Ceiling
  if(Ball.y >= World.height) {
    Ball.y = World.height - 2*Ball.radius - 1;
    Ball.yVel *= -1;
  }
}

