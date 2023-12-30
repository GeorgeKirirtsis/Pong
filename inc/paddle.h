#ifndef PADDLE_H
#define PADDLE_H

typedef struct 
{
    int score;
    float yPosition;
}Paddle;

Paddle makePaddle(void);
void updatePaddles(float elapsed);
void renderPaddles(void);

extern Paddle player1;
extern Paddle player2;
#endif