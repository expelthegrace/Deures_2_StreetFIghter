#include "Globals.h"
#include "Application.h"
#include "ModuleSceneKen.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "SDL/include/SDL.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleSceneKen::ModuleSceneKen(bool start_enabled) : Module(start_enabled)
{
	// ground
	ground.x = 8;
	ground.y = 391;
	ground.w = 896;
	ground.h = 72;

	// TODO 2 : setup the foreground (red ship) with
	// coordinates x,y,w,h from ken_stage.png
	foreGround.x = 8;
	foreGround.y = 23;
	foreGround.w = (530 - 8);
	foreGround.h = (204 - 23);

	// Background / sky
	background.x = 72;
	background.y = 208;
	background.w = 768;
	background.h = 176;

	// flag animation
	flag.frames.push_back({848, 208, 40, 40});
	flag.frames.push_back({848, 256, 40, 40});
	flag.frames.push_back({848, 304, 40, 40});
	flag.speed = 0.08f;

	girl.frames.push_back({ 625, 16,  656 - 625,  71 - 16 });
	girl.frames.push_back({ 625, 80,  656 - 625,  71 - 16 });
	girl.frames.push_back({ 625, 144, 656 - 625,  71 - 16 });
	girl.speed = 0.06f;

	barcoFlotacio = 0;
	maxBarcoFlotacio = 7;
	direccio = 1;


	framesAcc = 0;


	// TODO 4: Setup Girl Animation from coordinates from ken_stage.png

}

ModuleSceneKen::~ModuleSceneKen()
{}

// Load assets
bool ModuleSceneKen::Start()
{
	LOG("Loading ken scene");
	
	graphics = App->textures->Load("ken_stage.png");

	// TODO 7: Enable the player module
	
	return true;
}

// UnLoad assets
bool ModuleSceneKen::CleanUp()
{
	LOG("Unloading ken scene");

	App->textures->Unload(graphics);
	//App->player->Disable();
	
	return true;
}

// Update: draw background
update_status ModuleSceneKen::Update()
{
	barcoFlotacio = (framesAcc) - maxBarcoFlotacio / 2;

	// TODO 5: make sure the ship goes up and down

	// Draw everything --------------------------------------
	// TODO 1: Tweak the movement speed of the sea&sky + flag to your taste
	App->renderer->Blit(graphics, 0, 0, &background, 1.0f); // sea and sky
	App->renderer->Blit(graphics, 560, 8, &(flag.GetCurrentFrame()), 1.0f); // flag animation

	// TODO 3: Draw the ship. Be sure to tweak the speed.
	App->renderer->Blit(graphics, 0, 0 + barcoFlotacio, &foreGround, 1.05f);

	// TODO 6: Draw the girl. Make sure it follows the ship movement!
	App->renderer->Blit(graphics, 192, 105 + barcoFlotacio, &(girl.GetCurrentFrame()), 1.05f);


	App->renderer->Blit(graphics, 0, 170, &ground);

	// TODO 10: Build an entire new scene "honda", you can find its
	// and music in the Game/ folder

	// TODO 11: Make that pressing space triggers a switch to honda logic module
	// using FadeToBlack module

	
	framesAcc += (1 / 35.) * direccio; // divisor = velocitat de balanceig
	if (framesAcc >= maxBarcoFlotacio) direccio *= -1;
	else if (framesAcc <= 0) direccio *= -1;


	return UPDATE_CONTINUE;
}