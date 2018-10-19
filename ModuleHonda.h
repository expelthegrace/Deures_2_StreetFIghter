#ifndef _MODULEHONDA_
#define _MODULEHONDA_

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleHonda :
	public Module
{
public:
	ModuleHonda(bool enabled);
	virtual ~ModuleHonda();


	bool Start();
	update_status Update();
	bool CleanUp();

	SDL_Texture* graphics = nullptr;
	SDL_Rect ground;
	SDL_Rect background;
	SDL_Rect foreGround;
	SDL_Rect sostre;


	unsigned int backMusic;
};

#endif