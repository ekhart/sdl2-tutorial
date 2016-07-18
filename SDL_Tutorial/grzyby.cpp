//#include <iostream>
//#include <string>
//#include <SDL.h>
//
//#include <stdlib.h>
//
//#include "res_path.h"
//#include "cleanup.h"
//#include "utils.h"
////#include "mashroom.h"
//
//using namespace std;
//
//typedef struct {
//	int x, y, vx, vy;
//	SDL_Texture* texture;
//} Mashroom;
//
//const int MAX_MASHROOMS = 4;
//Mashroom mashrooms[MAX_MASHROOMS];
//
//Mashroom Mashroom_create(const string& name, SDL_Renderer* renderer) {
//	string resPath = getResourcePath("grzyby");
//	auto *blue = loadTexture(resPath + name, renderer);
//
//	Mashroom mashroom;
//	mashroom.x = 0;
//	mashroom.y = 0;
//	mashroom.vx = 0;
//	mashroom.vy = 0;
//	mashroom.texture = loadTexture(resPath + name, renderer);;
//	return mashroom;
//}
//
//Mashroom Mashroom_create_at_center(const string& name, SDL_Renderer* renderer) {
//	auto resPath = getResourcePath("grzyby");
//
//	Mashroom mashroom;
//	mashroom.texture = loadTexture(resPath + name, renderer);
//
//	auto size = getWidhtAndHeight(mashroom.texture);
//	mashroom.x = center(SCREEN_WIDTH, size.w);
//	mashroom.y = center(SCREEN_HEIGHT, size.h);
//	mashroom.vx = 0;
//	mashroom.vy = 0;
//
//	return mashroom;
//}
//
///*oid renderGrzybAtCenter(SDL_Texture* texture, SDL_Renderer* renderer, int xOffset, int yOffset) {
//	auto size = getWidhtAndHeight(texture);
//	int x = center(SCREEN_WIDTH, size.w) + xOffset;
//	int y = center(SCREEN_HEIGHT, size.h) + yOffset;
//	renderTexture(texture, renderer, x, y);
//}*/
//void renderGrzybAtCenter(Mashroom mashroom, SDL_Renderer* renderer, int xOffset, int yOffset) {
//	auto size = getWidhtAndHeight(mashroom.texture);
//	int x = center(SCREEN_WIDTH, size.w) + xOffset;
//	int y = center(SCREEN_HEIGHT, size.h) + yOffset;
//	renderTexture(mashroom.texture, renderer, x, y);
//}
//
//int randr(int min, int max)
//{
//	double scaled = (double)rand() / RAND_MAX;
//	return (max - min + 1)*scaled + min;
//}
//
//int randin(int offset)
//{
//	return randr(-offset, offset);
//}
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
//	//string resPath = getResourcePath("grzyby");
//	//auto *blue = loadTexture(resPath + "blueLSD.png", renderer);
//	//auto *fiolet = loadTexture(resPath + "fioletlsd.png", renderer);
//	//auto *kurka = loadTexture(resPath + "kurkalsd.png", renderer);
//	//auto *muchomor = loadTexture(resPath + "muchomoreklsd.png", renderer);
//	//if (!blue || !fiolet || !kurka || !muchomor) {
//	//	cleanup(blue, fiolet, kurka, muchomor, renderer, window);
//	//	logSDLError("loding textures");
//	//	IMG_Quit();
//	//	SDL_Quit();
//	//	return 4;
//	//}
//
//	auto blue = Mashroom_create_at_center("blueLSD.png", renderer);
//	auto fiolet = Mashroom_create_at_center("fioletlsd.png", renderer);
//	auto kurka = Mashroom_create_at_center("kurkalsd.png", renderer);
//	auto muchomor = Mashroom_create_at_center("muchomoreklsd.png", renderer);
//
//	mashrooms[0] = blue;
//	mashrooms[1] = fiolet;
//	mashrooms[2] = kurka;
//	mashrooms[3] = muchomor;
//
//	int offset = 100;
//	bool adding = true;
//
//	SDL_Event event;
//	auto quit = false;
//	while (!quit) {
//		while (SDL_PollEvent(&event)) {
//			quit = event.type == SDL_QUIT
//				|| event.type == SDL_KEYDOWN
//				|| event.type == SDL_MOUSEBUTTONDOWN;
//		}
//	
//		// render the scene
//		SDL_RenderClear(renderer);
//
//		//if (offset < 150) {
//		//	offset++;
//		//}
//		//else if (offset > 0) {
//		//	offset++;
//		//}
//		//else {
//		//	offset--;
//		//}
//
//		for (int i = 0; i < MAX_MASHROOMS; ++i) {
//			auto mashroom = mashrooms[i];
//
//			int offset = 10;
//			mashroom.x += randin(offset);
//			mashroom.y += randin(offset);
//
//			renderTexture(mashroom.texture, renderer, mashroom.x, mashroom.y);
//		}
//
//		//renderGrzybAtCenter(blue, renderer, -offset, -offset);
//		//renderGrzybAtCenter(fiolet, renderer, -offset, offset);
//		//renderGrzybAtCenter(kurka, renderer, offset, -offset);
//		//renderGrzybAtCenter(muchomor, renderer, offset, offset);
//	
//		SDL_RenderPresent(renderer);
//	}
//
//	//SDL_RenderPresent(renderer);
//	//SDL_Delay(2000);
//	//getc(stdin);
//
//	// Cleaning Up
//	//cleanup(blue, fiolet, kurka, muchomor, renderer, window);
//	cleanup(blue.texture, fiolet.texture, kurka.texture, muchomor.texture, 
//		renderer, window);
//	IMG_Quit();
//	SDL_Quit();
//
//	return 0;
//}