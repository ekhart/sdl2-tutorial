#include "mashroom.h"

Mashroom Mashroom_create(SDL_Texture* texture) {
	Mashroom mashroom;
	mashroom.x = 0;
	mashroom.y = 0;
	mashroom.vx = 0;
	mashroom.vy = 0;
	mashroom.texture = texture;
	return mashroom;
}