#include "SDL2/SDL.h"
#include "imageLoader.h"
#include "GameLoop.h"

int main( int argc, char* args[])
{
	GameLoop* newGame = new GameLoop();
	newGame->run();

	SDL_Quit();

	return 0;
}
