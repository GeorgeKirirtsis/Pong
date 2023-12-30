#include <SDL2/SDL.h>
#include <stdbool.h>
#include "utils.h"
#include "ball.h"
#include "state.h"
#include "paddle.h"

struct State state;
Paddle player1 = {0}; 
Paddle player2 = {0};

void updatePaddles(float elapsed)
{
    const u8 *keyboardState = SDL_GetKeyboardState(NULL);

    if(keyboardState[SDL_SCANCODE_SPACE]){
        served = true;
    }

    if(served)
    {
        if(keyboardState[SDL_SCANCODE_W]) {
            player1.yPosition -= PLAYER_MOVEMENT_SPEED * elapsed;
        }

        if(keyboardState[SDL_SCANCODE_S]) {
            player1.yPosition += PLAYER_MOVEMENT_SPEED * elapsed;
        }

        if(player1.yPosition < -PLAYER_HEIGHT / 2 - 1)
        {
            player1.yPosition = -PLAYER_HEIGHT /2 - 1;
        }

        if(player1.yPosition > HEIGHT + PLAYER_HEIGHT / 2 + 10)
        {
            player1.yPosition = HEIGHT + PLAYER_HEIGHT /2  + 10;
        }


        if(keyboardState[SDL_SCANCODE_UP]) {
            player2.yPosition -= PLAYER_MOVEMENT_SPEED * elapsed;
        }

        if(keyboardState[SDL_SCANCODE_DOWN]) {
            player2.yPosition += PLAYER_MOVEMENT_SPEED * elapsed;
        }

        if(player2.yPosition < -PLAYER_HEIGHT / 2 - 1)
        {
            player2.yPosition = -PLAYER_HEIGHT /2 - 1;
        }

        if(player2.yPosition > HEIGHT + PLAYER_HEIGHT / 2 + 10)
        {
            player2.yPosition = HEIGHT + PLAYER_HEIGHT /2 + 10;
        }

    }

}

void renderPaddles(void)
{
    SDL_SetRenderDrawColor(state.renderer, 255, 0, 0, 255);
    SDL_Rect player1Rect = {
        .x = PLAYER_MARGIN,
        .y = (int)(player1.yPosition) + PLAYER_HEIGHT / 2,
        .w = PLAYER_WIDTH,
        .h = PLAYER_HEIGHT,
    };
    
    SDL_RenderFillRect(state.renderer, &player1Rect);

    SDL_SetRenderDrawColor(state.renderer, 0, 0, 255, 255);
    SDL_Rect player2Rect = {
        .x = WIDTH + PLAYER_WIDTH + PLAYER_MARGIN + 1140,
        .y = (int)(player2.yPosition) + PLAYER_HEIGHT / 2,
        .w = PLAYER_WIDTH,
        .h = PLAYER_HEIGHT,
    };

    SDL_RenderFillRect(state.renderer, &player2Rect);
}

Paddle makePaddle(void)
{
    Paddle paddle = {
        .yPosition = HEIGHT / 2, // score is set automatic to 0
    };

    return paddle;
}