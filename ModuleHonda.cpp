#include "Globals.h"
#include "ModuleHonda.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "SDL/include/SDL.h"

ModuleHonda::ModuleHonda(bool start_enabled) : Module(start_enabled)
{
	// ground
	ground.x = 13;
	ground.y = 378;
	ground.w = 856 - 13;
	ground.h = 442 - 378;

	// Background / sky
	background.x = 121;
	background.y = 129;
	background.w = 790 - 121;
	background.h = 327 - 129;

	sostre.x = 93;
	sostre.y = 10;
	sostre.w = 855 - 93;
	sostre.h = 56 - 10;

}

ModuleHonda::~ModuleHonda()
{
}

bool ModuleHonda::Start() {
	graphics = App->textures->Load("honda_stage2.png");
	backMusic = App->audio->LoadFx("./ken.wav");

	return true;
}
update_status ModuleHonda::Update() {

	//ground
	App->renderer->Blit(graphics, -65, 162, &ground);

	//background
	App->renderer->Blit(graphics, -10, -10, &background);

	//sostre
	App->renderer->Blit(graphics, -60, -5, &sostre);


	return UPDATE_CONTINUE;
}


bool ModuleHonda::CleanUp() {
	LOG("Unloading honda scene");

	App->textures->Unload(graphics);
	App->player->Disable();
	return true;
}