#include "imageLoader.h"

SDL_Surface* ImageLoader::loadImage(std::string filename) //takes filename as a parameter
{
	SDL_Surface* image = SDL_LoadBMP(filename.c_str());

	return image;
}
