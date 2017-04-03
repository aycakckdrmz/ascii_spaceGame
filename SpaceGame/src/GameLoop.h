#ifndef GAMELOOP_H
#define GAMELOOP_H
#include "SDL2/SDL.h"
#include "imageLoader.h"
#include <vector>
#include "GameObject.h"
#include <stdlib.h>
#include <time.h>

class GameLoop
{
	public:
		GameLoop();
		void run(); //runs the game
		int fps;
		
		void CheckBounds(GameObject* object); //bounds checking to prevent player object from going off screen
		void loadGameObjects();
		int getScore();
		void setScore(int);
		void BulletRealloc(GameObject* object);

	private:
		std::vector<GameObject*> gameObjects;
		int score;

		//input flags
		bool upPressed;
		bool downPressed;
		bool spacePressed;
};



#endif
