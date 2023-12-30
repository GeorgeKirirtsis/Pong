#ifndef BALL_H
#define BALL_H

typedef struct 
{
    float x;
    float y;
    float xSpeed;
    float ySpeed;
    int size; 

}Ball;

Ball makeBall(int size);
void updateBall(Ball *ball, float elapsed);
void renderBall(const Ball *ball);
bool coinFlip(void);

#endif