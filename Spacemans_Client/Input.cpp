#include "SDL.h"
#include "Input.h"

KeyInput::KeyInput(){
	left = false; right = false; up = false; down = false; enter = false; space = false; escape = false; 
}

KeyInput::~KeyInput(){
}

void KeyInput::get_input(){
	while (SDL_PollEvent(&event)) {
	    switch (event.type) {
            case SDL_QUIT:
                break;
            case SDL_KEYDOWN:
				switch(event.key.keysym.sym) {
					case SDLK_LEFT:
                        left = true;
                        break;
                    case SDLK_RIGHT:
                        right = true;
                        break;
                    case SDLK_DOWN:
                        down = true;
                        break;
                    case SDLK_UP:
                        up = true;
                        break;
                    case SDLK_SPACE:
                        space = true;
                        break;
					case SDLK_RETURN:
						enter = true;
						break;
                    case SDLK_ESCAPE:
						escape = true;
						break;
                    default:
                        break;
                }
                break;
            case SDL_KEYUP:
                switch(event.key.keysym.sym) {
                    case SDLK_LEFT:
                        left = false;
                        break;
                    case SDLK_RIGHT:
                        right = false;
                        break;
                    case SDLK_DOWN:
                        down = false;
                        break;
                    case SDLK_UP:
                        up = false;
                        break;
                    case SDLK_SPACE:
                        space = false;
                        break;
					case SDLK_RETURN:
						enter = false;
						break;
					case SDLK_ESCAPE:
						escape = false;
						break;
                    default:
                        break;
                }
                break;
            default:
                break;
		}
	}
}