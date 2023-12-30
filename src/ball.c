#include <stdbool.h>
#include <SDL2/SDL.h>
#include "utils.h"
#include "state.h"
#include "ball.h"
#include "paddle.h"

bool coinFlip(void)
{
    return rand() % 2 == 1 ? true : false;
}
void spawn()
{
    served = false;
    player1.yPosition = HEIGHT / 2;
    player2.yPosition = HEIGHT /2;
}

void updateBall(Ball *ball, float elapsed)
{
    if(!(served))
    {
        ball->x = WIDTH - BALL_SIZE/ 2;
        ball->y = HEIGHT - BALL_SIZE / 2;
        return;
    }
    ball->x += ball->xSpeed * elapsed;
    ball->y += ball->ySpeed * elapsed;

    //collision system

    if(ball->x < BALL_SIZE / 2)
    {
        //ball->xSpeed = fabs(ball -> xSpeed);
        spawn();

    }
        
    if(ball->x > 2*WIDTH - BALL_SIZE / 2)
    {
        //ball->xSpeed = -fabs(ball -> xSpeed);
        spawn();
    }

    if(ball->y < BALL_SIZE / 2)
    {
        ball->ySpeed = fabs(ball -> ySpeed);
    }

    if(ball->y > 2*HEIGHT - BALL_SIZE / 2)
    {
        ball->ySpeed = -fabs(ball -> ySpeed);
    }

    int halfSize = ball->size / 2;

    SDL_Rect ballRect = {
        .x = ball->x - halfSize,
        .y = ball->y - halfSize,
        .w = ball->size,
        .h = ball->size
    };

     SDL_Rect player1Rect = {
        .x = PLAYER_MARGIN,
        .y = (int)(player1.yPosition) + PLAYER_HEIGHT / 2,
        .w = PLAYER_WIDTH,
        .h = PLAYER_HEIGHT,
    };
    
    if(SDL_HasIntersection(&ballRect, &player1Rect)){
        ball->xSpeed = fabs(ball->xSpeed);
    }

    SDL_Rect player2Rect = {
        .x = WIDTH + PLAYER_WIDTH + PLAYER_MARGIN + 1140,
        .y = (int)(player2.yPosition) + PLAYER_HEIGHT / 2,
        .w = PLAYER_WIDTH,
        .h = PLAYER_HEIGHT,
    };

    if(SDL_HasIntersection(&ballRect, &player2Rect)){
        ball->xSpeed = -fabs(ball->xSpeed);
    }
    
}

void renderBall(const Ball *ball)
{
    int size = ball -> size;
    int halfSize = size / 2;
    SDL_Rect rect = {
        .x = ball->x - halfSize,
        .y = ball->y - halfSize,
        .w = size,
        .h = size
    };
    SDL_SetRenderDrawColor(state.renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(state.renderer, &rect);
}

Ball makeBall(int size)
{
    
    Ball ball = {
        .x = WIDTH  - BALL_SIZE / 2,
        .y = HEIGHT - BALL_SIZE / 2,
        .size = size,
        .xSpeed = SPEED * (coinFlip() ? 1 : -1),
        .ySpeed = SPEED * (coinFlip() ? 1 : -1)
    };

    return ball;
}