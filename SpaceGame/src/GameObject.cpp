#include "GameObject.h"

GameObject::GameObject(std::string imageFilename)
{
	surf = SDL_LoadBMP(imageFilename.c_str());
	isAbleToShoot = true;
	isShooting = false;
	isAlive = true;
	collapsed = false; 
	isBullet = false; 
	isMovable = true; 
	isPlayer = false; 
	isEnemy = false; 
	value = 0;
}

SDL_Surface* GameObject::getSurface()
{
	return surf;
}

void GameObject::setSurface(std::string imageFilename)
{
	surf = SDL_LoadBMP(imageFilename.c_str());
}

void GameObject::Move(int newX, int newY)// this acts as a setter for both x and y
{
	x = newX;
	y = newY;
}
//GETTERS
int GameObject::getX()
{
	return x;
}
int GameObject::getY()
{
	return y;
}
bool GameObject::getisAbleToShoot()
{
	return isAbleToShoot;
}	
bool GameObject::getisShooting()
{
	return isShooting;
}
bool GameObject::getisAlive()
{
	return isAlive;
}
bool GameObject::getcollapsed()
{
	return collapsed;
} 
bool GameObject::getisBullet()
{
	return isBullet;
}
bool GameObject::getisEnemy()
{
	return isEnemy;
}
bool GameObject::getisPlayer()
{
	return isEnemy;
}
int GameObject::getValue()
{
	return value;
}
//SETTERS
void GameObject::setisAbleToShoot(bool a)
{
	isAbleToShoot = a;
}
void GameObject::setisShooting(bool a)
{
	isShooting = a;
}
void GameObject::setisAlive(bool a)
{
	isAlive = a;
}
void GameObject::setcollapsed(bool a)
{
	collapsed = a;
}
void GameObject::setisBullet(bool a)
{
	isBullet = a;
}
void GameObject::setisEnemy(bool a){
	isEnemy = a;
}
void GameObject::setValue(int a){
	value = a;
}
/*~GameObject::GameObject(){
	std::cout<<"object destroyed"<<endl;
}*/