#include <GameInput.h>
#include "GameEngine.h"

GameEngine::GameEngine(const std::string& title, int width, int height)
{
	windowManager = std::make_unique<WindowManager>(title, width, height);
}

GameEngine::~GameEngine()
{

}

void GameEngine::run()
{

}
