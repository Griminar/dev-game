#include <SDL.h>
#include <SDL_image.h>
#include "GameEngine.h"

//screen size constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char *args[])
{
	GameEngine* testEngine = new GameEngine();

	testEngine->init();
	testEngine->initDraw(640, 480);

	return 0;
}