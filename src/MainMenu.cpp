#include "../inc/MainMenu.h"
#include "../inc/Game.h"

void MainMenu::load()
{

}

void MainMenu::input(std::vector<SDL_Event>* events)
{

}

void MainMenu::update()
{

}

void MainMenu::render(Transform2d offset)
{
	offset << trans;
	offset.size *= Scene::getScale();

	SDL_Rect rec = { static_cast<int>(offset.pos.x),
					 static_cast<int>(offset.pos.y),
					 static_cast<int>(offset.size.x),
					 static_cast<int>(offset.size.y) };

	SDL_SetRenderDrawColor(game.win.getSdlRenderer(), 255, 0, 0, 0);
	SDL_RenderDrawRect(game.win.getSdlRenderer(), &rec);
}

void MainMenu::unload()
{
}
