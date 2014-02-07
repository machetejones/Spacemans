#include "SDL.h"
#include "SDL_image.h"
#include "Game.h"
#include "Texture.h"
#include "Input.h"
#include "Network.h"
#include <string>

Game::Game(){
	fired = false; fired2 = false;
}

Game::~Game(){
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

void Game::handle_input(){
	
	switch(state){
		
		case TITLE:
			if (keyboard.up == true && arrow.position.y <= 255){
				arrow.position.y = 385;
				SDL_Delay(200);
			}
			else if (keyboard.up == true && arrow.position.y > 255){
				arrow.position.y = arrow.position.y - 65;
				SDL_Delay(200);
			}
			else if (keyboard.down == true && arrow.position.y < 385){
				arrow.position.y = arrow.position.y + 65;
				SDL_Delay(200);
			}
			else if (keyboard.down == true && arrow.position.y >= 385){
				arrow.position.y = 255;
				SDL_Delay(200);
			}
			else if (keyboard.enter == true && arrow.position.y == 255){
				state = MAIN;
				arrow.move(435,380);
			}
			else if (keyboard.enter == true && arrow.position.y == 385){
				state = QUIT;
			}
			else if (keyboard.escape == true){
				state = QUIT;
			}
			break;

		case MAIN:
			if (keyboard.left == true && player.position.x > 18){
				player.position.x-=5;
			}
			if (keyboard.right == true && player.position.x < 750){
				player.position.x+=5;
			}
			if (keyboard.up == true && player.position.y > 400){
				player.position.y-=5;
			}
			if (keyboard.down == true && player.position.y < 550){
				player.position.y+=5;
			}
			if (keyboard.escape == true){
				state=PAUSE;
			}
			if (keyboard.space == true && fired == false){
				fired = true;
				bullet.move(player.position.x, player.position.y);
			}
			break;

		case PAUSE:
			if (keyboard.left == true && arrow.position.x == 435){
				arrow.position.x = 280;
			}
			if (keyboard.right == true && arrow.position.x == 280){
				arrow.position.x = 435;
			}
			if (keyboard.enter == true && arrow.position.x == 435){
				state = MAIN;
			}
			if (keyboard.enter == true && arrow.position.x == 280){
				state = TITLE;
				arrow.move(280,255);
				SDL_Delay(200);
			}
			break;

		case QUIT:
			break;

		default:
			break;
	}
}

void Game::handle_packet(){

}

void Game::send_packet(){

}

void Game::initialize(){

	state = TITLE;
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);

	window = SDL_CreateWindow("Spessmans: Pew Pew", 200,200, 800,600, SDL_WINDOW_OPENGL);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	background.load(renderer, "images/background.png",0,0);
	main_menu.load(renderer, "images/main_menu.png",190,200);
	pause_menu.load(renderer, "images/pause_menu.png",190,200);
	arrow.load(renderer, "images/arrow.png",280,255);
	player.load(renderer, "images/player.png",384,550);
	player2.load(renderer, "images/player2.png",384,18);
	bullet.load(renderer, "images/bullet.png",0,0);
	bullet.load(renderer, "images/bullet2.png",0,0);

   // reset();

}

void Game::run(){
	
	keyboard.get_input();
	handle_input();
	background.render(renderer);

	switch(state){
	case TITLE:
		main_menu.render(renderer);
		arrow.render(renderer);
		break;
	case MAIN:
		player.render(renderer);
		player2.render(renderer);
		if (fired == true){
			bullet.position.y-=10;
			bullet.render(renderer);
		}
		if (bullet.position.y < 0){
			bullet.move(0,0);
			fired = false;
		}
		if (fired2 == true){
			bullet2.position.y+=10;
			bullet2.render(renderer);
		}
		if (bullet2.position.y > 600){
			bullet2.move(0,0);
			fired2 = false;
		}
		break;
	case PAUSE:
		pause_menu.render(renderer);
		arrow.render(renderer);
		break;
	default:
		break;
	}
	SDL_RenderPresent(renderer);
}

void Game::reset(){

}

