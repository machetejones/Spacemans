#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include "SDL.h"
#include "SDL_image.h"
#include <string>

class Texture{
public:	
	SDL_Texture* image;
	SDL_Rect position;
	bool shown;
	Texture();
	~Texture();
	void load(SDL_Renderer *, std::string,int,int);
	void move(int, int);
	void render(SDL_Renderer *);
};

#endif