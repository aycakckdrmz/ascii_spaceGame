#ifndef IMAGELOADER_H
#define IMAGELOADER_H
#include "SDL2/SDL.h"
#include <string>


class ImageLoader
{
	public:
		static SDL_Surface* loadImage(std::string filename); //load an image onto the screen
		
};



#endif
