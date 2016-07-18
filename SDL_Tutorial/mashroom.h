#ifndef MASHROOM_H
#define MASHROOM_H

#include <SDL.h>

typedef struct {
	int x, y, vx, vy;
	SDL_Texture* texture;
} Mashroom;

Mashroom Mashroom_create(SDL_Texture* texture);

#endif