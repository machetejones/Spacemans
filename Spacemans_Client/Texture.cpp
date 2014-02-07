#include "SDL.h"
#include "SDL_image.h"
#include "Texture.h"
#include <string>


Texture::Texture(){
	image = NULL;
	shown = false;
	position.x = 0; position.y = 0; position.w = 0, position.h = 0;
}

Texture::~Texture(){
	SDL_DestroyTexture(image);
}

void Texture::load(SDL_Renderer *renderer, std::string path, int x, int y){
	image = IMG_LoadTexture(renderer, path.c_str());
	SDL_QueryTexture(image, NULL, NULL, &position.w, &position.h);
	move(x,y);
}

void Texture::move(int x, int y){
	position.x = x; position.y = y;
}

void Texture::render(SDL_Renderer *renderer){
	SDL_RenderCopy(renderer, image, NULL, &position);
}