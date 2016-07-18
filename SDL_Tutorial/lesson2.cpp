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
//	string resPath = getResourcePath("Lesson2");
//	auto *background = loadTexture(resPath + "background.bmp", renderer);
//	auto *image = loadTexture(resPath + "image.bmp", renderer);
//	if (!background || !image) {
//		cleanup(background, image, renderer, window);
//		logSDLError("loding textures");
//		SDL_Quit();
//		return 4;
//	}
//
//	// Drawing a Tiled Background
//	SDL_RenderClear(renderer);
//	
//	auto backgroundSize = getWidhtAndHeight(background);
//	renderTexture(background, renderer, 0, 0);
//	renderTexture(background, renderer, backgroundSize.w, 0);
//	renderTexture(background, renderer, 0, backgroundSize.h);
//	renderTexture(background, renderer, backgroundSize.w, backgroundSize.h);
//
//	// Drawing the Foreground Image
//	auto imageSize = getWidhtAndHeight(image);
//	int x = center(SCREEN_WIDTH, imageSize.w);
//	int y = center(SCREEN_HEIGHT, imageSize.h);
//	renderTexture(image, renderer, x, y);
//
//	SDL_RenderPresent(renderer);
//	SDL_Delay(1000);
//
//	// Cleaning Up
//	cleanup(background, image, renderer, window);
//	SDL_Quit();
//
//	return 0;
//}
//
