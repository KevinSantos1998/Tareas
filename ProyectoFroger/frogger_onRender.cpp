
#include <SDL.h>
#include <string>
#include <sstream>
#include "frogger.h"
#include "scrollbg.h"

void Game::onRender()
{

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderClear(renderer);


    for (int i = 0; i < 600; i+=50) grass.bgRender(renderer, i);


    water.bgRender(renderer, 150);

    road.bgRender(renderer, 350);

    for (int i = 0; i < 4; i++) allGameObjects[i]->render(renderer);

    for (int i = 0; i < 4; i++){

        if (player.isOccupied(i))
        {
            frogIcon.setPosition(pad[i].getX(), pad[i].getY());
            frogIcon.render(renderer);
        }
    }

    squash.render(renderer);
    topWater.bgRender(renderer, 150);

    for (int i = 4; i < 15; i++) allGameObjects[i]->render(renderer);

    player.render(renderer);

    for (int i = 15; i < 15 + numSmall + numMed; i++) allGameObjects[i]->render(renderer);

    updateScore();

    for (int i = 0; i < lives; i++)
    {
        frogIcon.setPosition(5 + i * 40, SCREEN_HEIGHT - 55);
        frogIcon.render(renderer);
    }

}

void Game::updateScore()
{
    std::string stringScore;


    renderText(scoreToString(score), 5, 30, 36, 20, textColor);


    stringScore = "Score";
    renderText(stringScore, 5, 5, 28, 15, textColor);

    stringScore = "Frogger";
    renderText(stringScore, SCREEN_WIDTH/2-(stringScore.length() * 20)/2, 5, 36, 20, textColor);


}

std::string Game::scoreToString(int score)
{

    std::string stringScore;
    std::stringstream ss;

    ss << score;
    stringScore = ss.str();
    ss.str("");

    return stringScore;
}

void Game::renderText(std::string text, int x, int y, int height, int charWidth, SDL_Color color)
{
    textSurface = TTF_RenderText_Blended(font, text.c_str(), color);
    scoreTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);
    scoreRect = {x, y, (int)(text.length() * charWidth), height};
    SDL_RenderCopy(renderer, scoreTexture, NULL, &scoreRect);
    SDL_DestroyTexture(scoreTexture);
}
