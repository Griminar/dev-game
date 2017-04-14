#include "GameEngine.h"

GameEngine::GameEngine()
{
}


GameEngine::~GameEngine()
{
}

bool GameEngine::init()
{
	bool success = true;

	

	return success;
}

bool GameEngine::initDraw(int screenWidth, int screenHeight)
{
	bool success = true;

	//init SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
		success = false;
	}
	else
	{
		//create window
		this->gWindow = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
		if (this->gWindow == NULL)
		{
			std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
			success = false;
		}
		else
		{
			//create renderer
			this->gRenderer = SDL_CreateRenderer(this->gWindow, -1, SDL_RENDERER_ACCELERATED); // | SDL_RENDERER_ACCELERATED)
			if (this->gRenderer == NULL)
			{
				std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
				success = false;
			}
			else
			{
				//set background draw colour
				SDL_SetRenderDrawColor(this->gRenderer, 0x00, 0x00, 0x00, 0xFF);
			}
		}
	}

	return success;
}

void GameEngine::tick()
{

}

bool GameEngine::getQuitFlag()
{
	return true;
}

void GameEngine::setDrawingColour(int r, int g, int b, int alpha)
{
	//sets render draw colour
	SDL_SetRenderDrawColor(this->gRenderer, r, g, b, alpha);
}

void GameEngine::render()
{
	//present renderer
	SDL_RenderPresent(this->gRenderer);
}

void GameEngine::clearRenderer()
{
	//clear renderer
	SDL_RenderClear(this->gRenderer);
}

void GameEngine::exit()
{
	//free all textures

	//destroy renderer
	SDL_DestroyRenderer(this->gRenderer);
	//destroy window
	SDL_DestroyWindow(this->gWindow);

	//Set pointers to null
	this->gRenderer = NULL;
	this->gWindow = NULL;

	//close SDL and SDL ext lib
	IMG_Quit();
	SDL_Quit();
}

//testing only
void GameEngine::drawQuad(int x, int y, int w, int h)
{
	SDL_Rect fillRect = { x,y,w,h };
	SDL_RenderFillRect(this->gRenderer, &fillRect);
}