#include "SDL.h"
#include "Game.h"
#include "Network.h"

int main(int argc, char** argv){

	Game main_game;
	Socket netsock;

	main_game.initialize();
	netsock.init_socket();

	bool quit = false;
	while (!quit){

	main_game.run();

	if (main_game.state == QUIT){
			quit = true;
		}

	}

	netsock.send_data("this is a test");

	IMG_Quit();
	SDL_Quit();

	return 0;
}

