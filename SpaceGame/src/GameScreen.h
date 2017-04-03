#ifndef GAMESCREEN_H
#define GAMESCREEN_H
#include "SDL2/SDL.h"
#include "imageLoader.h"
#include <vector>
#include "GameObject.h"

class GameScreen //this class will handle everything that ll be displayed on screen 
{			     // it'll destruct every game object we dont see 
	public:		//,clean after collisions, create new object on the screen
		GameScreen(std::vector<GameObject*>);
		void updateScreen(); // mainfunction cycle will have everything below
		void loadImages();
		void cleanOuttaScreen(); //loop thru gameObject x & y's
		void gameDisplayBuffer(); //will decide new object have them ready
		void collisionCleaning(); //loop the bool collapssed 	
		//cases: playervsenemy >> end of game pl.bulletvsenermyship updateScore &health() 
		void updateScore(); //

 	private:
 		std::vector<GameObject*> gameObjects;
 		int score;
 		int screenSpeed; //aka difficulty 



};

#endif
