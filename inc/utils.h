#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>
#include "paddle.h"

#define ASSERT(_e, ...) if (!(_e)) { fprintf(stderr, __VA_ARGS__); exit(1); }
#define min(_a, _b) ({ __typeof__(_a) __a = (_a), __b = (_b); __a < __b ? __a : __b; })
#define max(_a, _b) ({ __typeof__(_a) __a = (_a), __b = (_b); __a > __b ? __a : __b; })

#define WIDTH 1280
#define HEIGHT 720

#define BALL_SIZE 30
#define SPEED 500

#define PLAYER_WIDTH 40
#define PLAYER_HEIGHT 350
#define PLAYER_MARGIN 30
#define PLAYER_MOVEMENT_SPEED 300.0f

extern bool served;

typedef float    f32;
typedef double   f64;
typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t   i8;
typedef int16_t  i16;
typedef int32_t  i32;
typedef int64_t  i64;
typedef size_t   usize;

#endif