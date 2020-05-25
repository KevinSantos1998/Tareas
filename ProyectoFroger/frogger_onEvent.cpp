#include <SDL.h>
#include "frogger.h"


void Game::onEvent(SDL_Event* event)
{
    if(event->type == SDL_QUIT) {
        running = false;
    }

    if (event->type == SDL_KEYDOWN){
        switch (event->key.keysym.sym){
        case SDLK_ESCAPE:
            running = false;
            break;

        case SDLK_LEFT:
            if (!player.isInMotion() && player.getX() != 0 && squash.getAlpha() == 0){
                player.rotateSprite(270);
                if (player.getX() - 50 <= 0) {
                    player.setDest(0, player.getY());
                } else {
                    player.setDest(player.getX() - 50, player.getY());
                }
                player.setMotion(-2, 0);
            }
            break;

        case SDLK_RIGHT:
            if (!player.isInMotion() && player.getX() != SCREEN_WIDTH - 50 && squash.getAlpha() == 0){
                player.rotateSprite(90);
                if (player.getX() + 50 >= SCREEN_WIDTH) {
                    player.setDest(SCREEN_WIDTH - 50, player.getY());
                } else {
                    player.setDest(player.getX() + 50, player.getY());
                }
                player.setMotion(2, 0);
            }
            break;

        case SDLK_DOWN:
            if (!player.isInMotion() && player.getY() != 500 && squash.getAlpha() == 0){
                player.rotateSprite(180);
                player.setDest(player.getX(), player.getY()+50);
                player.setMotion(0, 2);

            }
            break;

        case SDLK_UP:
            if (!player.isInMotion() && player.getY() != 100 && squash.getAlpha() == 0){
                player.rotateSprite(0);
                player.setDest(player.getX(), player.getY()-50);
                if (farthestLane > player.getY() - 50){
                    score += 10;
                    farthestLane -= 50;
                }
                player.setMotion(0, -2);

            }
            break;


        case SDLK_RETURN:
            break;
        }
    }
}
