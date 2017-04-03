#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
 
#include "SDL2/SDL.h"
#include <string>

class GameObject
{
	public:
		GameObject(std::string imageFilename);
		virtual void Move(int newX, int newY); // handles moving objects
		virtual SDL_Surface* getSurface();
		virtual int getX();
		virtual int getY();
		virtual bool getisAbleToShoot();	
		virtual bool getisShooting();
		virtual bool getisAlive();
		virtual bool getcollapsed();
		virtual bool getisBullet();
		virtual bool getisEnemy();
		virtual bool getisPlayer();
		virtual int getValue();
		virtual void setisAbleToShoot(bool);
		virtual void setisShooting(bool);
		virtual void setisAlive(bool);
		virtual void setcollapsed(bool);
		virtual void setisBullet(bool);
		virtual void setisEnemy(bool);
		virtual void setValue(int);
		virtual void setSurface(std::string);

		
	protected:

		SDL_Surface* surf;
		int x;
		int y;
		bool isAbleToShoot; //1> for shooting objects 0>not shooting 		
		bool isShooting; //if true create bullet Objects
		bool isAlive; //if false self destruct 
		bool collapsed; 
		bool isBullet; // ex: if that gameObject "isBullet" and player.collapsed() then player.value -= bullet.value
		bool isMovable; //F for meteors and such 
		bool isPlayer; //everything needs to or may need to be modified it the GO is player
		bool isEnemy;
		int value; //health for player and ships damage for bullets

};

#endif
