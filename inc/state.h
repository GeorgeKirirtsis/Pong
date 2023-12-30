#ifndef STATE_H
#define STATE_H

#include <SDL2/SDL.h>
#include <stdbool.h>
#include "ball.h"

struct State
{
    SDL_Window* window;
    SDL_Texture* texture;
    SDL_Renderer* renderer;
    bool quit;
    Ball ball;
};

extern struct State state;

#endif