#ifndef _INPUT_H_
#define _INPUT_H_

#include "SDL.h"

class KeyInput{
public:	
	bool left, right, up, down, space, escape, enter;
	SDL_Event event;
	KeyInput();
	~KeyInput();
	void get_input();
};

#endif