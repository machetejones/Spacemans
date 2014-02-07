#ifndef _GAME_H_
#define _GAME_H_

#include "SDL.h"
#include "Texture.h"
#include "Input.h"
#include "Network.h"
#include <string>

enum { TITLE, MAIN, PAUSE, QUIT };

class Game{
public:

	Game();
	~Game();

	bool fired, fired2;
	int speed, state;

	SDL_Window *window; 
	SDL_Renderer *renderer;
	KeyInput keyboard;

	Texture background;
	Texture main_menu;
	Texture pause_menu;
	Texture arrow;
	Texture player;
	Texture player2;
	Texture bullet;
	Texture bullet2;

	void initialize();
	void run();
	void reset();
	void handle_input();
	void handle_packet();
	void send_packet();

};

#endif