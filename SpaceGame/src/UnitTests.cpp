#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GameLoop.h"
#include "GameObject.h" //it has all the h files we need

int add( int a, int b){
	return a+b;
}

TEST_CASE("test the test"){ //tested tests failed first
	REQUIRE(add(2,3)==5);
}
//game object constructor test

GameObject *ship ("images/PlayerShip.bmp");
TEST_CASE(" test gameObject constructor"){
	bool test = ship->getisAlive();
	REQUIRE(test == true);
}

//abc test 
//using game object class on its child classes
//test setters of game object
//test getters for game object
//test both with child classes with its supers pointer

