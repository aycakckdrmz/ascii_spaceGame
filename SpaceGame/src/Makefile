
spaceGame: main.o GameLoop.o GameObject.o imageLoader.o 
	g++ main.o GameLoop.o GameObject.o imageLoader.o -o spaceGame -lSDL2

main.o: main.cpp
	g++ -c main.cpp

GameLoop.o: GameLoop.cpp GameLoop.h
	g++ -c GameLoop.cpp 

imageLoader.o: imageLoader.cpp imageLoader.h
	g++ -c imageLoader.cpp 

GameObject.o: GameObject.cpp GameObject.h
	g++ -c GameObject.cpp

clean:
	rm *.o spaceGame
