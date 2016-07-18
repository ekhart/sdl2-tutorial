#ifndef CLEANUP_H
#define CLEANUP_H

#include <utility>
#include <SDL.h>

/*
 * Recurse throuh the list of arguments to clean up, cleaning up
 * the first one in the list each iteration.
 */
// https://www.google.pl/webhp?sourceid=chrome-instant&ion=1&espv=2&ie=UTF-8#q=c%2B%2B%20variadic%20template
template<typename T, typename... Args>
void cleanup(T *t, Args&&... args) {
	// cleanup the first item in the list
	cleanup(t);
	// recurse to clean up the remaining arguments
	cleanup(std::forward<Args>(args)...);
}

/*
 * These specialization serve to free the passed arguments and also provide the
 * base cases for the recursive call above, eg. when args is only single item
 * one of the specialization below will be called by
 * cleanup(std::forward<Args>(args)..., ending the recursion
 * We also make it save to pass nullptrs to handle situtation where we
 * don't want to bother finding out which values failded to load (and thus are null)
 * but rather just want to clean everything up and let cleanup sort it out
 */

template<>
inline void cleanup<SDL_Window>(SDL_Window *window) {
	if (!window) {
		return;
	}
	SDL_DestroyWindow(window);
}

template<>
inline void cleanup<SDL_Renderer>(SDL_Renderer *renderer) {
	if (!renderer) {
		return;
	}
	SDL_DestroyRenderer(renderer);
}

template<>
inline void cleanup<SDL_Texture>(SDL_Texture *texture) {
	if (!texture) {
		return;
	}
	SDL_DestroyTexture(texture);
}

template<>
inline void cleanup<SDL_Surface>(SDL_Surface *surface) {
	if (!surface) {
		return;
	}
	SDL_FreeSurface(surface);
}

#endif