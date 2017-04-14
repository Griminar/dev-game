#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class GameEngine
{
private:
	SDL_Event e;
	void clearRenderer();
	void render();

	SDL_Renderer* gRenderer;
	SDL_Window* gWindow;
	void setDrawingColour(int, int, int, int);

	//testing only
	void drawQuad(int x, int y, int w, int h);
	
public:
	GameEngine();
	~GameEngine();

	void tick();
	bool init();
	bool initDraw(int, int);
	void exit();
	bool getQuitFlag();
};

