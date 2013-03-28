/** ***********************************************************************
 *
 * Lab 3 C Code (Basic pong animation)
 * 
 * Main.c 
 *
** ***********************************************************************/
#include <stdio.h>
#include <stdlib.h>

//#include "engine.h"
#include "circle.h"
#include "world.h"

int leftBound(const struct circle* Ball) {
  return Ball->xPos - Ball->radius;
}

int rightBound(const struct circle* Ball) {
  return Ball->xPos + Ball->radius;
}

int topBound(const struct circle* Ball) {
  return Ball->yPos + Ball->radius;
}

int bottomBound(const struct circle* Ball) {
  return Ball->yPos - Ball->radius;
}

void checkBounds(struct circle* Ball, struct world* World) {

  // Right wall
  if(rightBound(Ball) >= World->width) {
    Ball->xPos = World->width - 2*Ball->radius - 1;
    Ball->xVel *= -1;
  }

  // Left wall
  if (leftBound(Ball) <= 0) {
    Ball->xPos += 1;
    Ball->xVel *= -1;
  }

  // Floor
  if(bottomBound(Ball) <= 0) {
    Ball->yPos += 1;
    Ball->yVel *= -1;
  }

  // Ceiling
  if(topBound(Ball) >= World->height) {
    Ball->yPos = World->height - 2*Ball->radius - 1;
    Ball->yVel *= -1;
  }
}

void updatePosition(struct circle* Ball, struct world* World) {
  checkBounds(Ball, World);

  Ball->xPos = (Ball->xPos + Ball->xVel);
  Ball->yPos = (Ball->yPos + Ball->yVel);

}

int main(char* args) { 

  // TODO: Check the resolution of the world in pixels

  //struct circle* ball_func = createBall();
  //printf("Ball position: %d %d", ball_func->xPos, ball_func->yPos);

  struct circle* ball = malloc(sizeof (struct circle)); 
  struct world* World = malloc(sizeof (struct world)); 

  // Initial position and velocity of the ball.
  ball->xPos = 560;
  ball->yPos = 340;
  ball->xVel = 6;
  ball->yVel = 9;
  ball->radius = 10;

  World->width = 600;
  World->height = 400;
  
  printf("Ball position: %d %d\n", ball->xPos, ball->yPos);
  printf("World dimensions: %d %d\n", World->width, World->height);

  printf("Ball right: %d\n", rightBound(ball));
  printf("Ball left: %d\n", leftBound(ball));
  printf("Ball top: %d\n", topBound(ball));
  printf("Ball bottom: %d\n", bottomBound(ball));

  int i=0;
  for (i=0; i<10000; ++i) {
    updatePosition(ball, World);
    printf("Ball position: %d %d\n", ball->xPos, ball->yPos);
  }

  return 0;
}

