
#include <SDL.h>
#include <vector>

#include "frogger.h"
#include "header.h"

using namespace std;

void Game::onLoop()
{

    player.onBoat = false;
    player.onUpperLog = false;
    player.onLowerLog = false;

    water.bgScroll(1);
    topWater.bgScroll(2);

    for (int i = 0; i < 15 + numSmall + numMed; i++)
    {
        allGameObjects[i]->moveSprite();
        allGameObjects[i]->animate();
    }

    processVehicles();

    if (squash.getAlpha() > 0)
    {
        squash.setAlpha(squash.getAlpha() - 2);
        if (squash.getAlpha() == 0) {
            player.reset();
            squash.setPosition(0,0);
        }
    } else {
        player.animate();
        if (player.isInMotion())
        {
            player.moveFrog();
        }
        checkCollisions();
    }

    if (player.allPadsOccupied())
    {
        score += 1000;
        player.resetPads();
        if (numSmall < MAX_SMALL_VEHICLES){
            allGameObjects.insert(allGameObjects.begin() + 14 + numSmall, &small[numSmall]);
            numSmall++;
        }
        if (numSmall % 2 == 1 && numMed < MAX_MED_VEHICLES){
            allGameObjects.insert(allGameObjects.begin() + 14 + numSmall + numMed, &med[numMed]);
            numMed++;
        }

    }
}

void Game::processVehicles()
{

    for (int i = 0; i < numSmall; i++)
    {

        if (small[i].active == false) {
            int clearance = 75;

            do {

                if (small[i].getY() == 400) {
                    small[i].randomPosition(SCREEN_WIDTH, SCREEN_WIDTH + clearance, small[i].getY(), small[i].getY(), 1, 1);
                } else {
                    small[i].randomPosition(-1 * clearance, -50, small[i].getY(), small[i].getY(), 1, 1);
                }

                clearance += 10;

            } while (vehicleCollide(small[i].getX(), small[i].getY(), 50));

            small[i].active = true;
        }
    }


    for (int i = 0; i < numMed; i++)
    {

        if (med[i].active == false) {
            int clearance = 90;

            do {

                if (med[i].getY() == 400) {
                    med[i].randomPosition(SCREEN_WIDTH, SCREEN_WIDTH + clearance, med[i].getY(), med[i].getY(), 1, 1);
                } else {
                    med[i].randomPosition(-1 * clearance, -75, med[i].getY(), med[i].getY(), 1, 1);
                }

                clearance += 10;

            } while (vehicleCollide(med[i].getX(), med[i].getY(), 75));

            med[i].active = true;
        }
    }
}

void Game::Collisions()
{


    for (int i = 0; i < 3; i++)
    {
        if (player.getX() + 20 >= boat[i].getX() && player.getX() + 30 <= boat[i].getX() + 75 && player.getY() == boat[i].getY())
        {
            player.translate(-1 * BOAT_SPEED, 0);
            player.setDest(player.getDestX() - 1 * BOAT_SPEED, 0);

            if (player.getX() < 0)
            {
                player.setPosition(0, player.getY());
                player.setDest(player.getDestX() + 1 * BOAT_SPEED, 0);
            }
            player.onBoat = true;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (player.getX() + 20 >= logs[i].getX() && player.getX() + 30 <= logs[i].getX() + 125 && player.getY() == logs[i].getY())
        {
            player.translate(UPPER_LOG_SPEED, 0);
            player.setDest(player.getDestX() + UPPER_LOG_SPEED, 0);

            if (player.getX() + 50 > SCREEN_WIDTH)
            {
                player.setPosition(SCREEN_WIDTH - 50, player.getY());
                player.setDest(player.getDestX() - 1 * UPPER_LOG_SPEED, 0);
            }
            player.onUpperLog = true;
        }
    }

    for (int i = 3; i < 7; i++)
    {
        if (player.getX() + 20 >= logs[i].getX() && player.getX() + 30 <= logs[i].getX() + 125 && player.getY() == logs[i].getY())
        {
            player.translate(LOWER_LOG_SPEED, 0);
            player.setDest(player.getDestX() + LOWER_LOG_SPEED, 0);

            if (player.getX() + 50 > SCREEN_WIDTH)
            {
                player.setPosition(SCREEN_WIDTH - 50, player.getY());
                player.setDest(player.getDestX() - 1 * LOWER_LOG_SPEED, 0);
            }
            player.onLowerLog = true;
        }
    }


    if (player.getY() >= 350)
    {
        for (int i = 0; i < numSmall; i++)
        {

            if (player.getY() == small[i].getY() && player.getX() + 40 > small[i].getX() && player.getX() + 10 < small[i].getX() + 50) loseLife();
        }
        for (int i = 0; i < numMed; i++)
        {

            if (player.getY() == med[i].getY() && player.getX() + 40 > med[i].getX() && player.getX() + 10 < med[i].getX() + 75) loseLife();
        }

    } else if (player.getY() == 150 && !player.isInMotion()) {
        if (!player.onUpperLog) loseLife();

    } else if (player.getY() == 200 && !player.isInMotion()) {
        if (!player.onBoat) loseLife();

    } else if (player.getY() == 250 && !player.isInMotion()){
        if (!player.onLowerLog) loseLife();
    }

    if (player.getY() == fly.getY() && player.getX() < fly.getX() + 50 && player.getX() + 50 > fly.getX() && squash.getX() != player.getX() && squash.getY() != player.getY())
    {
        score += 100;

        fly.setAlpha(0);
        fly.setPosition(0, 0);
    }


    if (player.getY() == 100)
    {

        score += 200;
        farthestLane = 500;
        player.setOccupied(player.getX()/200);
        player.reset();
        fly.setAlpha(255);
        fly.randomPosition(0, SCREEN_WIDTH, 150, 350, 50, 50);
    }
}

void Game::loseLife()
{
    lives -= 1;
    player.setAlpha(0);
    squash.setPosition(player.getX(), player.getY());
    squash.setAlpha(220);

    if (lives == 0) running = false;
}
