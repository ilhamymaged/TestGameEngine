#include "GameEngine.h"

GameEngine::GameEngine(const std::string& title, int width, int height)
{
	windowManager = std::make_unique<WindowManager>(title, width, height);
	scene = std::make_unique<Scene>(ResourceManager::getEntitiesScene());
	ResourceManager::loadAssets();
}

GameEngine::~GameEngine()
{

}

void GameEngine::run()
{
	Renderer::render(*windowManager, *scene);
}
