#include <SDL.h>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <vector>

#include "header.h"
#include "frogger.h"
#include "scrollbg.h"
#include "vehicle.h"

using namespace std;

bool Game::onInit()
{
    srand(time(0));

    if(!initializeSDL()) return false;


    for (int i = 0; i < 4; i++){
        pad[i] = GameObject(50, 50, 4, 1);
        pad[i].loadSprite(renderer, "images/pad.bmp");
        pad[i].setPosition(100 + i * 200, 100);
    }


    grass.loadBG(renderer, "images/grass.bmp");


    road.loadBG(renderer, "images/road.bmp");


    water = ScrollBG({0, 0, 255, 160});
    water.loadBG(renderer, "images/bottomwater.bmp");

    topWater = ScrollBG({0, 0, 255, 100});
    topWater.loadBG(renderer, "images/topwater.bmp");


    for (int i = 0; i < MAX_SMALL_VEHICLES; i++){
        small[i] = Vehicle(50, 50, 4, 4);
        small[i].loadSprite(renderer, "images/vehicleSmall.bmp");
    }


    for (int i = 0; i < MAX_MED_VEHICLES; i++){
        med[i] = Vehicle(75, 50, 4, 4);
        med[i].loadSprite(renderer, "images/vehicleMed.bmp");
    }


    initializeVehicles();


    for (int i = 0; i < 3; i++){
        boat[i] = WaterVehicle(true, 75, 50, 4, 2);
        boat[i].loadSprite(renderer, "images/boat.bmp");
        boat[i].setPosition(100 + i * 325, 200);
    }


    for (int i = 0; i < 7; i++){
        logs[i].loadSprite(renderer, "images/log.bmp");
        logs[i].setSprite(125, 50, 1, 1);
    }


    for (int i = 0; i < 3; i++) logs[i].setPosition(100 + i * 325, 150);
    for (int i = 3; i < 7; i++) logs[i].setPosition(i * 250 - 600, 250);


    player = Frog(50, 50, 4, 2);
    player.loadSprite(renderer, "images/frogSheet.bmp");


    frogIcon = GameObject(50, 50, 1, 1);
    frogIcon.loadSprite(renderer, "images/frogIcon.bmp");


    squash = GameObject(50, 50, 1, 1);
    squash.loadSprite(renderer, "images/squash.bmp");
    squash.setAlpha(0);


    fly = GameObject(50, 50, 4, 1);
    fly.loadSprite(renderer, "images/flysmall.bmp");
    fly.randomPosition(0, SCREEN_WIDTH, 150, 340, 50, 50);

    for (int i = 0; i < 4; i++) allGameObjects.push_back(&pad[i]);
    for (int i = 0; i < 7; i++) allGameObjects.push_back(&logs[i]);
    for (int i = 0; i < 3; i++) allGameObjects.push_back(&boat[i]);
    allGameObjects.push_back(&fly);
    for (int i = 0; i < numSmall; i++) allGameObjects.push_back(&small[i]);
    for (int i = 0; i < numMed; i++) allGameObjects.push_back(&med[i]);

    return true;
}


bool Game::initializeSDL()
{
    SDL_SetHint(SDL_HINT_WINDOWS_DISABLE_THREAD_NAMING, "1");

    if(SDL_Init(SDL_INIT_VIDEO || SDL_INIT_AUDIO) < 0) return false;

    if (!(window = SDL_CreateWindow("FroggerGame", 400, 50, SCREEN_WIDTH, SCREEN_HEIGHT, 0))) return false;
    if (!(renderer = SDL_CreateRenderer(window, -1, 0))) return false;

    if (TTF_Init() < 0) return false;


    return true;
}

void Game::initializeVehicles()
{
    for (int i = 0; i < numSmall; i++)
    {
        do {
            small[i].randomPosition(-100, SCREEN_WIDTH + 100, small[i].getY(), small[i].getY(), 1, 1);
            small[i].active = true;
        } while (vehicleCollide(small[i].getX(), small[i].getY(), 50));
    }
    for (int i = 0; i < numMed; i++)
    {
        do {
            med[i].randomPosition(-100, SCREEN_WIDTH + 100, med[i].getY(), med[i].getY(), 1, 1);
            med[i].active = true;
        } while (vehicleCollide(med[i].getX(), med[i].getY(), 75));
    }

}

bool Game::vehicleCollide(int x, int y, int width)
{
    for (int i = 0; i < numSmall; i++)
    {
        if (!(y == small[i].getY() && x == small[i].getX()))
        {
            if (y == small[i].getY())
            {
                if (x + width >= small[i].getX() - SMALL_CLEARANCE && x <= small[i].getX() + 50 + SMALL_CLEARANCE)
                {
                    return true;
                }
            }
        }
    }
    for (int i = 0; i < numMed; i++)
    {
        if (!(y == med[i].getY() && x == med[i].getX()))
        {
            if (y == med[i].getY())
            {
                if (x + width >= med[i].getX() - MED_CLEARANCE && x <= med[i].getX() + 75 + MED_CLEARANCE)
                {
                    return true;
                }
            }
        }
    }

    return false;
}
