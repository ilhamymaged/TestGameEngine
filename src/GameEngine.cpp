#include "GameEngine.h"

GameEngine::GameEngine(const std::string& title, int width, int height)
{
	windowManager = std::make_unique<WindowManager>(title, width, height);
	ResourceManager::loadAssets();
	scene = std::make_unique<Scene>(ResourceManager::getEntitiesScene());
}

GameEngine::~GameEngine()
{

}

void GameEngine::run()
{
	Renderer::render(*windowManager, *scene);
}
