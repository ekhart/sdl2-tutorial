#include "utils.h"

// The SDL Error Logger
/**
* Log an SDL error with som error message to the output stream of our choice
* @param os The output stream to write the message to
* @param msg The error message to write, format will be msg error: SDL_GetError()
*/
void logSDLError(ostream &os, const string &msg) {
	os << msg << " error: " << SDL_GetError() << endl;
}

void logSDLError(const string &msg) {
	logSDLError(cout, msg);
}


// The Texture Loading Function
/**
* Loads a BMP image into a texture on the rendering device
* @param file The BMP image file to load
* @param renderer The renderer to load the texture onto
* @return The loaded texture, or nullptr if something went wrong.
*/
//SDL_Texture* loadTexture(const string &file, SDL_Renderer *renderer) {
//	// initialize to nullptr to avoid dangling pointer issues
//	SDL_Texture *texture = nullptr;
//	// load the image
//	SDL_Surface *bmp = SDL_LoadBMP(file.c_str());
//	// if the loading went ok, convert to texture and return the texture
//	if (bmp != nullptr) {
//		texture = SDL_CreateTextureFromSurface(renderer, bmp);
//		SDL_FreeSurface(bmp);
//
//		// make sure converting went ok too
//		if (texture == nullptr) {
//			logSDLError(cout, "SDL_CreateTextureFromSurface");
//		}
//	}
//	else {
//		logSDLError(cout, "SDL_LoadBMP");
//	}
//
//	return texture;
//}
SDL_Texture* loadTexture(const string &file, SDL_Renderer *renderer) {
	SDL_Texture *texture = IMG_LoadTexture(renderer, file.c_str());
	if (texture == nullptr) {
		logSDLError("SDL_CreateTextureFromSurface");
	}
	return texture;
}

/**
* Draw an SDL_Texture to an SDL_Renderer at some destination rect
* taking a clip of the texture if desired
* @param texture The source texture we want to draw
* @param renderer The renderer we want to draw to
* @param destination The destination rectangle to render the texture to
* @param clip The sub-section of the texture to draw (cliping rect)
* default of nullptr draw the entire texture
*/
void renderTexture(SDL_Texture *texture, SDL_Renderer *renderer, SDL_Rect destination, SDL_Rect *clip = nullptr)
{
	SDL_RenderCopy(renderer, texture, clip, &destination);
}

/**
* Draw an SDL_Texture to an SDL_Renderer at position x, y preserving
* the texture width and height and taking a clip of the texture if desired
* @param texture The source texture we want to draw
* @param renderer The renderer we want to draw to
* @param x The x coordinate to draw to
* @param y The y coordinate to draw to
* @param clip The sub-section of the texture to draw (cliping rect)
* default of nullptr draw the entire texture
*/
void renderTexture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y, SDL_Rect *clip = nullptr)
{
	SDL_Rect destination;
	destination.x = x;
	destination.y = y;

	if (clip != nullptr) {
		destination.w = clip->w;
		destination.h = clip->h;
	}
	else {
		SDL_QueryTexture(texture, NULL, NULL, &destination.w, &destination.h);
	}

	renderTexture(texture, renderer, destination, clip);
}

// The Texture Rendering Function
/**
* Draw an SDL_Texture to an SDL_Renderer at position x, y, preserving
* the texture's width and height
* @param texture The source texture we want to draw
* @param renderer The renderer we want to draw to
* The x coordinate to draw to
* The y coordinate to draw to
*/
//void renderTexture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y) {
//	// Setup the destinantion rectangle to be at the position we want
//	SDL_Rect destination;
//	destination.x = x;
//	destination.y = y;
//	// query the texture to get its width and height to use
//	SDL_QueryTexture(texture, NULL, NULL, &destination.w, &destination.h);
//
//	SDL_RenderCopy(renderer, texture, NULL, &destination);
//}
void renderTexture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y) {
	int w, h;
	SDL_QueryTexture(texture, NULL, NULL, &w, &h);
	renderTexture(texture, renderer, x, y, w, h);
}

// Specifying Width and Height for Rendering
/**
* Draw an SDL_Texture to an SDL_Renderer at position x, y, with some desired
* width and height
* @param texture The source texture we want to draw
* @param renderer The renderer we want to draw to
* @param x The x coordinate to draw to
* @param y The y coordinate to draw to
* @param w The width of the texture to draw
* @param h The height of the texture to draw
*/
void renderTexture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y, int w, int h) {
	// Setup the destinantion rectangle to be at the position we want
	SDL_Rect destination;
	destination.x = x;
	destination.y = y;
	destination.w = w;
	destination.h = h;
	SDL_RenderCopy(renderer, texture, NULL, &destination);
}

SDL_Rect getWidhtAndHeight(SDL_Texture *texture) {
	SDL_Rect destination;

	SDL_QueryTexture(texture, NULL, NULL, &destination.w, &destination.h);

	return destination;
}

int half(int x) {
	return x / 2;
}

int center(int a, int b) {
	return half(a) - half(b);
}