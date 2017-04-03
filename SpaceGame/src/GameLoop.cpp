#include "GameLoop.h"
#include <iostream>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
GameLoop::GameLoop()
{
    score = 0;
}
int GameLoop::getScore()
{
    return score;
}
void GameLoop::setScore(int newScore)
{
    score = newScore;
}
void GameLoop::run()
{
    //Setup game resources (images, sounds, etc.)
    SDL_Window* window = 0; //create a window

    SDL_Surface* screenSurface = 0; //create a surface to apply images

    SDL_Init(SDL_INIT_EVERYTHING); //initialize SDL

    window = SDL_CreateWindow( "Space Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    
    screenSurface = SDL_GetWindowSurface(window);

    //load image stuff
    //loadGameObjects(gameObjects*);
    GameObject *ship;
    ship = new GameObject("images/PlayerShip.bmp"); //PlayerShip
    ship->Move(0, SCREEN_HEIGHT - 310); //start playerShip halfway down the screen
    ship->setValue(80); //Player's health 
    gameObjects.push_back(ship);

    GameObject* divider = new GameObject("images/divider.bmp"); //divider for heads-up display thing
    divider->Move(0, SCREEN_HEIGHT - 110); //set the divider bar at the location of 530px down
    gameObjects.push_back(divider);

    GameObject* health = new GameObject("images/HealthBar/Full.bmp"); //full HP bar
    health->Move(0, SCREEN_HEIGHT - 105); //set health bar at this position
    gameObjects.push_back(health);
    

    GameObject* score = new GameObject("images/score1.bmp"); // score marker
    score->Move(SCREEN_WIDTH - 150, SCREEN_HEIGHT - 105); //set score at this posion
    gameObjects.push_back(score);

    GameObject* scoreVal = new GameObject("images/Score.bmp"); // score marker
    score->Move(SCREEN_WIDTH - 100, SCREEN_HEIGHT - 105); //set score at this posion
    gameObjects.push_back(score);

    GameObject* bullet1 = new GameObject("images/bulletRightNew.bmp"); 
    bullet1->Move(SCREEN_WIDTH+55, SCREEN_HEIGHT - 310); 
    gameObjects.push_back(bullet1);

    GameObject* bullet2 = new GameObject("images/bulletRightNew.bmp"); 
    bullet2->Move(SCREEN_WIDTH+55, SCREEN_HEIGHT - 310); 
    gameObjects.push_back(bullet2); //all bullets are being created outta bounds

    GameObject* bullet3 = new GameObject("images/bulletRightNew.bmp"); 
    bullet3->Move(SCREEN_WIDTH+70, SCREEN_HEIGHT - 310); 
    gameObjects.push_back(bullet3);

    GameObject* bigBullet1 = new GameObject("images/bigBulletRight.bmp"); 
    bigBullet1->Move(SCREEN_WIDTH+85, SCREEN_HEIGHT - 310); 
    gameObjects.push_back(bigBullet1);

    GameObject* enemy1 = new GameObject("images/newEnemyI.bmp"); 
    enemy1->Move(SCREEN_WIDTH-50, SCREEN_HEIGHT - 310); 
    gameObjects.push_back(enemy1);

    GameObject* enemyBullet1 = new GameObject("images/bulletLeftNew.bmp"); 
    enemyBullet1->Move(-52, SCREEN_HEIGHT - 310); 
    enemyBullet1->setValue(10);
    gameObjects.push_back(enemyBullet1);

    GameObject* enemyBullet2 = new GameObject("images/bulletLeftNew.bmp"); 
    enemyBullet2->Move(-52, SCREEN_HEIGHT - 310); 
    enemyBullet2->setValue(10);
    gameObjects.push_back(enemyBullet2);

    GameObject* enemyBullet3 = new GameObject("images/bulletLeftNew.bmp"); 
    enemyBullet3->Move(-52, SCREEN_HEIGHT - 310); 
    enemyBullet3->setValue(10);
    gameObjects.push_back(enemyBullet3);
    

    bool quit = false;
    unsigned int lastTime = 0, currentTime;
    unsigned int lastShotTime = 0, currentTimeShooting;
    unsigned int lastGotShot = 0, currentTimeGettingShot;
    int curY = 0;
    int curX = 0;
    int move = -5;
    int h = 0;
    int eh1 = 0; 
    int eh2 = 0;
    int eh3 = 0;
    bool isMoving = false;
    int shootingRandomizer1 = 0;
    int shootingRandomizer2 = 0;
    int shootingRandomizer3 = 0;
    bool notShooted = false;
    bool playerGotShot = false;
    bool gameOver = false;
    srand(time(NULL)); //init random seed 
    while(!quit)
    {
        SDL_Event e;
        //Get and handle SDL events (input, errors, etc)
        while( SDL_PollEvent( &e ) != 0 ) 
        { 
            if( e.type == SDL_QUIT ) //to close the window
            { 
                quit = true; 
            } 
            else if( e.type == SDL_KEYDOWN)
            {
                switch( e.key.keysym.sym ) //Keyboard events
                {
                    case SDLK_UP: //up
                        std::cout << "Up Pressed" << std::endl;
                        upPressed = true;
                    break;

                    case SDLK_DOWN: //down
                        std::cout << "Down Pressed" << std::endl;
                        downPressed = true;
                    break;

                    case SDLK_SPACE: //spacebar
                        std::cout << "Space Pressed" << std::endl;
                        spacePressed = true;
                    break;
                }
            }
            else if( e.type == SDL_KEYUP)
            {
                switch( e.key.keysym.sym ) //Keyboard events
                {
                    case SDLK_UP: //up
                        std::cout << "Up Released" << std::endl;
                        upPressed = false;
                    break;

                    case SDLK_DOWN: //down
                        std::cout << "Down Released" << std::endl;
                        downPressed = false;
                    break;

                    case SDLK_SPACE: //spacebar
                        std::cout << "Space Released" << std::endl;
                        spacePressed = false;
                    break;
                }
            }

        }

        if(upPressed)
        {
            ship->Move(ship->getX(), ship->getY() - 2); //2 is the optimal movement speed
        }
        
        if(downPressed)
        {
            ship->Move(ship->getX(), ship->getY() + 2);            
        }
        if(spacePressed) //player Shootings
        { 
            notShooted = true;
            if( bullet1->getX()>SCREEN_WIDTH){
                bullet1->Move(ship->getX()+50, ship->getY()+10); 
                notShooted == false;
            }
            else if (bullet2->getX()>SCREEN_WIDTH && notShooted){
                bullet2->Move(ship->getX()+50, ship->getY()+10);
                notShooted == false;
            }
            else if (bullet3->getX()>SCREEN_WIDTH && notShooted){
                bullet3->Move(ship->getX()+50, ship->getY()+10); 
                notShooted == false;          
            }
            else if (bigBullet1->getX()>SCREEN_WIDTH && notShooted){
                bigBullet1->Move(ship->getX()+50, ship->getY()+10); 
                notShooted == false;          
            }

        }
        currentTime = SDL_GetTicks();
        currentTimeShooting = SDL_GetTicks();
        shootingRandomizer1 = rand() % 100 + 100; //enemy Shootings
        while (currentTimeShooting > lastShotTime + shootingRandomizer1 && enemyBullet1->getX()<-11)
        {
            enemyBullet1->Move(enemy1->getX()-30, enemy1->getY()+10); 
            lastShotTime = currentTimeShooting;
        }
        shootingRandomizer2 = rand() % 200 + 100;
        while (currentTimeShooting > lastShotTime + shootingRandomizer2 && enemyBullet2->getX()<-11)
        {
            enemyBullet2->Move(enemy1->getX()-30, enemy1->getY()+10);
            lastShotTime = currentTimeShooting;
        }
        shootingRandomizer3 = rand() % 150 + 100;
        while (currentTimeShooting > lastShotTime + shootingRandomizer3 && enemyBullet3->getX()<-11)
        {
            enemyBullet3->Move(enemy1->getX()-30, enemy1->getY()+10); 
            lastShotTime = currentTimeShooting;
        }
        if (currentTime > lastTime + 20){
            isMoving  = true;
        } 
        while(isMoving){   //moves everything but player
            enemy1->Move(enemy1->getX(), enemy1->getY()+move);             
            if( bullet1->getX()<SCREEN_WIDTH  ){
                bullet1->Move(bullet1->getX()+3, bullet1->getY());
            }
            if (bullet2->getX()<SCREEN_WIDTH){
                bullet2->Move(bullet2->getX()+4, bullet2->getY());
            }
            if (bullet3->getX()<SCREEN_WIDTH ){
                bullet3->Move(bullet3->getX()+6, bullet3->getY());       
            }    
            if (bigBullet1->getX()<=SCREEN_WIDTH ){
                bigBullet1->Move(bigBullet1->getX()+5, bigBullet1->getY());       
            }    
            if( enemyBullet1->getX()>-20 ){
                enemyBullet1->Move( enemyBullet1->getX()-5, enemyBullet1->getY());
            }
            if( enemyBullet2->getX()>-20 ){
                enemyBullet2->Move( enemyBullet2->getX()-4, enemyBullet2->getY());
            }
            if( enemyBullet3->getX()>-20 ){
                enemyBullet3->Move( enemyBullet3->getX()-2, enemyBullet3->getY());
            }
            if(enemy1->getY() >= 370 - enemy1->getSurface()->h) //bottom of screen
                move *= (-1); //change direction 
            if(enemy1->getY() < 0) 
                move *= (-1);
            
            lastTime = currentTime;
            isMoving = false;
        }
        //64 is where the tip of the ship located 
        h = ship->getY();
        eh1 = enemyBullet1->getY(); 
        eh2 = enemyBullet2->getY();
        eh3 = enemyBullet3->getY();
        if( ( enemyBullet1->getX() == 64 && (eh1<h+20 && eh1>h-20))  
         || ( enemyBullet2->getX() == 64 && (eh2<h+20 && eh2>h-20))  
         || ( enemyBullet3->getX() == 64 && (eh3<h+20 && eh3>h-20)) )
        {
            playerGotShot = true;
            currentTimeGettingShot = SDL_GetTicks();
            if( currentTimeGettingShot - lastGotShot > 50)
            {
                playerGotShot = true;
                lastGotShot = currentTime;
            }

        }
        //collision check playervsEnemyBullets
    
        if(ship->getValue() == 10 && playerGotShot)  //got shot full health 
        {   
            gameOver == true;
            health -> setSurface("images/HealthBar/Empty.bmp"); 
            enemyBullet1->setSurface("images/gameOverSmall.bmp");
            enemyBullet2->setSurface("images/gameOverSmall.bmp");
            enemyBullet3->setSurface("images/gameOverSmall.bmp");
            ship->setSurface("images/black.bmp");


        }
        if(ship->getValue() == 20 && playerGotShot)  //got shot full health 
        {   
            ship->setValue(ship->getValue()-10);
            health -> setSurface("images/HealthBar/hit7.bmp"); 
            playerGotShot = false;
        }
        else if(ship->getValue() == 30 && playerGotShot) //got second hit 
        {   
            ship->setValue(ship->getValue()-10);
            health -> setSurface("images/HealthBar/hit6.bmp"); ;
            playerGotShot = false;
        }
        else if(ship->getValue() == 40 && playerGotShot) //got third hit
        {   
            ship->setValue(ship->getValue()-10);
            health -> setSurface("images/HealthBar/hit5.bmp"); 
            playerGotShot = false;
        }
        else if(ship->getValue() == 50 && playerGotShot)  //got 4th hit
        {   
            ship->setValue(ship->getValue()-10);
            health -> setSurface("images/HealthBar/hit4.bmp"); 
            playerGotShot = false;
        }
        else if(ship->getValue() == 60 && playerGotShot)  //got 5th hit
        {   
            ship->setValue(ship->getValue()-10);
            health -> setSurface("images/HealthBar/hit3.bmp"); 
            playerGotShot = false;
        }
        else if(ship->getValue() == 70 && playerGotShot)  //got 6th hit
        {   
            ship->setValue(ship->getValue()-10);
            health -> setSurface("images/HealthBar/hit2.bmp");  //got 7th hit
            playerGotShot = false;
        }
        else if(ship->getValue() == 80 && playerGotShot)  //got 8th hit
        {   
            ship->setValue(ship->getValue()-10);
            health -> setSurface("images/HealthBar/hit1.bmp"); 
            playerGotShot = false;
        }       
        if(gameOver)                   
        {
            enemyBullet1->setSurface("images/gameOverSmall.bmp");
            enemyBullet2->setSurface("images/gameOverSmall.bmp");
            enemyBullet3->setSurface("images/gameOverSmall.bmp");
            ship->setSurface("images/black.bmp");

        }


        //Draw stuff

        for(int i = 0; i < gameObjects.size(); i++)
        {
            GameObject* currentObj = gameObjects.at(i); //draw a rectangle around the image.

            SDL_Rect currentRect;
            currentRect.x = currentObj->getX();
            currentRect.y = currentObj->getY();
            currentRect.w = currentObj->getSurface()->w;
            currentRect.h = currentObj->getSurface()->h;
            SDL_BlitSurface(currentObj->getSurface(), 0, screenSurface, &currentRect); //rectangle continually blitted
        }


        SDL_UpdateWindowSurface(window);    
        CheckBounds(ship);
        CheckBounds(enemy1);

        SDL_Delay(1000.0 / (float)fps);
    }

}

void GameLoop::CheckBounds(GameObject* object)
{

    if(object->getY() >= 370 - object->getSurface()->h) //bottom of screen
    {
        object->Move(object->getX(), 370 - object->getSurface()->h);
    }

    else if(object->getY() <= 0) // top of screen
    {
        object->Move(object->getX(), 0);
    }
}
void GameLoop::BulletRealloc(GameObject* object)
{
    if(object->getX() >= SCREEN_WIDTH+100 || object->getY() <= 0) 
    {
        object->Move(SCREEN_WIDTH+50, object->getY());
    }//if outta bounds store them in one spot background 
}


