
#include <SDL.h>
#include <string>
#include "frogger.h"
#include "scrollbg.h"


Game::Game()
{
    score = 0;
    lives = 5;
    farthestLane = 500;
    running = true;
    numSmall = START_SMALL_VEHICLES;
    numMed = START_MED_VEHICLES;
}

int Game::onExecute()
{
    if (!onInit()) return -1;

    while(running)
    {

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            onEvent(&event);
        }

        onLoop();

        onRender();

        SDL_RenderPresent(renderer);

        SDL_Delay(7);

    }

    if (lives == 0)
    {
        fadeOut();

        SDL_Delay(4000);
    }


    onQuit();

    return 0;
}


void Game::fadeOut()
{

    int op = 0;

    SDL_Texture *fadeTex = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_TARGET, 800, 600);
    SDL_SetTextureBlendMode(fadeTex, SDL_BLENDMODE_BLEND);
    SDL_SetRenderTarget(renderer, fadeTex);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderTarget(renderer, NULL);

    while (op < 255)
    {

        SDL_SetTextureAlphaMod(fadeTex, op);

        onRender();

        SDL_RenderCopy(renderer, fadeTex, NULL, NULL);

        renderText("Game Over", SCREEN_WIDTH/2 - 100, op, 60, 28, (SDL_Color){200, 20, 20});
        renderText("SCORE", 5 + 350*op/255, 5 + 375*op/255, 28, 15, (SDL_Color){255, 255, 255});
        renderText(scoreToString(score), 5 + 350*op/255, 30 + 375*op/255, 36, 20,(SDL_Color){255, 255, 255});

        SDL_RenderPresent(renderer);

        SDL_Delay(5);

        op++;
    }

}


void Game::onQuit()
{
    TTF_Quit();
    SDL_Quit();
}

int main(int argc, char* argv[])
{
    while(true)
    {
        Game froggerGame;

        return froggerGame.onExecute();
    }
}
