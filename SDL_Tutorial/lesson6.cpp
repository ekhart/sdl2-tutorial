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

	// Loading a Bitmap Image
	string resPath = getResourcePath("Lesson5");
	auto *background = loadTexture(resPath + "background.png", renderer);
	auto *image = loadTexture(resPath + "image.png", renderer);
	if (!background || !image) {
		cleanup(background, image, renderer, window);
		logSDLError("loding textures");
		IMG_Quit();
		SDL_Quit();
		return 4;
	}

	//iW and iH are the clip width and height
	//We'll be drawing only clips so get a center position for the w/h of a clip
	int iW = 100, iH = 100,
		x = center(SCREEN_WIDTH, iW),
		y = center(SCREEN_HEIGHT, iH);

	//Setup the clips for our image
	const int CLIPS_COUNT = 4;
	SDL_Rect clips[CLIPS_COUNT];

	//Since our clips our uniform in size we can generate a list of their
	//positions using some math (the specifics of this are coverd in the lesson)
	for (int i = 0; i < CLIPS_COUNT; ++i) {
		auto clip = &clips[i];
		clip->x = half(i) * iW;
		clip->y = i % 2 * iH;
		clip->w = iW;
		clip->h = iH;
	}

	//Specify a default clip to start with 
	int useClip = 0;

	// Completing the Main Loop
	// our event structure
	SDL_Event event;
	auto quit = false;
	while (!quit) {
		while (SDL_PollEvent(&event)) {
			quit = event.type == SDL_QUIT;

			//Use number input to select which clip should be drawn
			if (event.type == SDL_KEYDOWN) {
				switch (event.key.keysym.sym)
				{
				case SDLK_1: useClip = 0; break;
				case SDLK_2: useClip = 1; break;
				case SDLK_3: useClip = 2; break;
				case SDLK_4: useClip = 3; break;
				case SDLK_ESCAPE: quit = true; break;
				default:
					break;
				}
			}
		}

		// render the scene
		SDL_RenderClear(renderer);

		//Drawing the image
		renderTexture(image, renderer, x, y, &clips[useClip]);

		//Update the screen
		SDL_RenderPresent(renderer);
	}

	// Cleaning Up
	cleanup(background, image, renderer, window);
	IMG_Quit();
	SDL_Quit();

	return 0;
}