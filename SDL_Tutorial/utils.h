#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

using namespace std;


const int	SCREEN_WIDTH = 640,
			SCREEN_HEIGHT = 480,
			// Setting up Tile Properties
			TILE_SIZE = 40;			// we'll just be using square tiles for now

void logSDLError(ostream &os, const string &msg);

void logSDLError(const string &msg);	// overloading

SDL_Texture* loadTexture(const string &file, SDL_Renderer *renderer);

void renderTexture(SDL_Texture *texture, SDL_Renderer *renderer, SDL_Rect destination, SDL_Rect *clip = nullptr);

void renderTexture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y, SDL_Rect *clip = nullptr);

void renderTexture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y);

void renderTexture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y, int w, int h);

SDL_Rect getWidhtAndHeight(SDL_Texture *texture);



int half(int x);

int center(int a, int b);

SDL_Texture* renderText(const std::string &message, const std::string &fontFile, SDL_Color color, int fontSize, SDL_Renderer *renderer);

#endif