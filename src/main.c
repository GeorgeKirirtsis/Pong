#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <SDL2/SDL.h>
#include "utils.h"
#include "ball.h"
#include "paddle.h"
#include "state.h"

bool served = false;
struct State state;

void shutdown(void)
{
    if(state.renderer) SDL_DestroyRenderer(state.renderer);
    if(state.window)   SDL_DestroyWindow(state.window);
    SDL_Quit();
}

void update(f32 elapsed)
{
    printf("%f\n", elapsed);
    SDL_SetRenderDrawColor(state.renderer, 0, 0, 0, 255);
    SDL_RenderClear(state.renderer);

    updateBall(&state.ball, elapsed);
    renderBall(&state.ball);

    updatePaddles(elapsed);
    renderPaddles();

    SDL_RenderPresent(state.renderer);

}

int main(int argc, char *argv[])
{
    atexit(shutdown);

    ASSERT(
        !SDL_Init(SDL_INIT_VIDEO),
        "SDL failed to initialize: %s\n",
        SDL_GetError()
    );

    state.window =
        SDL_CreateWindow(
            "PONG",
            SDL_WINDOWPOS_CENTERED_DISPLAY(1),
            SDL_WINDOWPOS_CENTERED_DISPLAY(1),
            WIDTH,
            HEIGHT,
            SDL_WINDOW_ALLOW_HIGHDPI
        );

    ASSERT(state.window, "Failed to create SDL Window: %s\n", SDL_GetError());

    state.renderer =
        SDL_CreateRenderer(
            state.window,
            -1,
            SDL_RENDERER_ACCELERATED 
            |SDL_RENDERER_PRESENTVSYNC
        );


    state.ball = makeBall(BALL_SIZE);
    served = false;

    //create paddles
    player1 = makePaddle();
    player2 = makePaddle();

    u32 lastTick = SDL_GetTicks();
    

    while(!state.quit){
        SDL_Event ev;
        while(SDL_PollEvent(&ev)){
            switch (ev.type)
            {
            case SDL_QUIT:
                state.quit = true;
                break;
            

            }
        }
        u32 currentTick = SDL_GetTicks();
        u32 diff = currentTick - lastTick;
        float elapsed = diff / 1000.0f;

        update(elapsed);
        
        lastTick = currentTick;
    }


    return 0;
}

