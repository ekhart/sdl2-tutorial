#include <iostream>
#include <string>
#include <SDL.h>

#include "res_path.h"
#include "cleanup.h"
#include "utils.h"

using namespace std;


int main(int, char**) {

	//Creating the Window and Renderer
	// starting sdl
	if (SDL_Init(SDL_INIT_EVERYTHING)) {
		logSDLError("SDL_Init");
		return 1;
	}

	// Initialize SDL_image (Optional)
	auto png = IMG_INIT_PNG;
	if ((IMG_Init(png) & png) != png) {
		logSDLError("IMG_Init");
		return 1;
	}

	if (TTF_Init()) {
		logSDLError("TTF_Init");
		SDL_Quit();
		return 1;
	}

	// opening a window
	auto *window = SDL_CreateWindow("Lesson 5", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (!window) {
		logSDLError("SDL_CreateWindow");
		SDL_Quit();
		return 2;
	}

	// creating a renderer
	auto flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	auto *renderer = SDL_CreateRenderer(window, -1, flags);
	if (renderer == nullptr) {
		cleanup(window);
		logSDLError("SDL_CreateRenderer");
		SDL_Quit();
		return 3;
	}

	string resPath = getResourcePath("Lesson6");
	// We'll render the string "TTF font are cool!" in white
	// Color is in RGBA format
	SDL_Color color = { 255, 255, 255, 255 };
	SDL_Texture *image = renderText("TTF fonts are cool!", resPath + "sample.ttf", color, 64, renderer);
	if (image == nullptr) {
		cleanup(renderer, window);
		TTF_Quit();
		SDL_Quit();
		return 4;
	}

	//iW and iH are the clip width and height
	//We'll be drawing only clips so get a center position for the w/h of a clip
	int iW, iH;
	SDL_QueryTexture(image, NULL, NULL, &iW, &iH);
	
	int x = center(SCREEN_WIDTH, iW),
		y = center(SCREEN_HEIGHT, iH);

	// Cleaning Up
	cleanup(image, renderer, window);
	IMG_Quit();
	SDL_Quit();

	return 0;
}