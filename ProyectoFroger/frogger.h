
#ifndef froggerGame_h
#define froggerGame_h

#include <SDL.h>

#include <SDL_ttf.h>
#include <string>
#include <vector>

#include "scrollbg.h"
#include "vehicle.h"
#include "header.h"
#include "frog.h"
#include "watervehicle.h"

using namespace std;

class Game
{
private:

    bool running;

    int score, farthestLane, lives;

    int numSmall, numMed;

    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *textSurface;
    SDL_Texture *scoreTexture;
    TTF_Font *font;

    SDL_Rect scoreRect;
    SDL_Color textColor;

    GameObject pad[4];
    GameObject frogIcon;
    GameObject fly;

    ScrollBG water, topWater, road;
    StaticBG grass;

    Vehicle small[MAX_SMALL_VEHICLES];
    Vehicle med[MAX_MED_VEHICLES];
    WaterVehicle boat[3];
    WaterVehicle logs[6];
    WaterVehicle lowerLogs[3];

    Frog player;
    GameObject squash;

    vector<Sprite*> allGameObjects;


public:

    Game();

    int onExecute();

    bool onInit();
    bool initializeSDL();

    void initializeVehicles();

    void onLoop();
    void processVehicles();
    void checkCollisions();
    void updateScore();
    void onEvent(SDL_Event* event);
    void loseLife();
    bool vehicleCollide(int x, int y, int width);

    void onRender();
    std::string scoreToString(int score);
    void renderText(std::string text, int x, int y, int height, int charWidth, SDL_Color color);

    void fadeOut();

    void onQuit();

};


#endif
