//#include <iostream>
//#include <string>
//#include <SDL.h>
//
//#include "res_path.h"
//#include "cleanup.h"
//#include "utils.h"
//
//using namespace std;
//
//
//int main(int, char**) {
//
//	//Creating the Window and Renderer
//	// starting sdl
//	if (SDL_Init(SDL_INIT_EVERYTHING)) {
//		logSDLError("SDL_Init");
//		return 1;
//	}
//
//	// Initialize SDL_image (Optional)
//	auto png = IMG_INIT_PNG;
//	if ((IMG_Init(png) & png) != png) {
//		logSDLError("IMG_Init");
//		return 1;
//	}
//
//	// opening a window
//	auto *window = SDL_CreateWindow("Lesson 2", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
//	if (!window) {
//		logSDLError("SDL_CreateWindow");
//		SDL_Quit();
//		return 2;
//	}
//
//	// creating a renderer
//	auto flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
//	auto *renderer = SDL_CreateRenderer(window, -1, flags);
//	if (renderer == nullptr) {
//		cleanup(window);
//		logSDLError("SDL_CreateRenderer");
//		SDL_Quit();
//		return 3;
//	}
//
//	// Loading a Bitmap Image
//	string resPath = getResourcePath("Lesson3");
//	auto *background = loadTexture(resPath + "background.png", renderer);
//	auto *image = loadTexture(resPath + "image.png", renderer);
//	if (!background || !image) {
//		cleanup(background, image, renderer, window);
//		logSDLError("loding textures");
//		IMG_Quit();
//		SDL_Quit();
//		return 4;
//	}
//
//	// Tiling the Background
//	//Determine how many tiles we'll need to fill the screen
//	int xTiles = SCREEN_WIDTH / TILE_SIZE,
//		yTiles = SCREEN_HEIGHT / TILE_SIZE,
//		tiles = xTiles * yTiles;
//
//	//Draw the tiles by calculationg theri posistions
//	for (int i = 0; i < tiles; ++i) {
//		int x = (i % xTiles) * TILE_SIZE,
//			y = (i / xTiles) * TILE_SIZE;
//		renderTexture(background, renderer, x, y, TILE_SIZE, TILE_SIZE);
//	}
//
//	//Drawing the Foreground
//	auto size = getWidhtAndHeight(image);
//	int x = center(SCREEN_WIDTH, size.w),
//		y = center(SCREEN_HEIGHT, size.h);
//	renderTexture(image, renderer, x, y);
//
//	SDL_RenderPresent(renderer);
//	SDL_Delay(2000);
//
//	// Cleaning Up
//	cleanup(background, image, renderer, window);
//	IMG_Quit();
//	SDL_Quit();
//
//	return 0;
//}