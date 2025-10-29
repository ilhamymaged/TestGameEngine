#pragma once
#include <WindowManager.h>
#include <Renderer.h>
#include <Scene.h>
#include <vector>
#include <ResourceManager.h>

class GameEngine
{
public:
	GameEngine(const std::string& title, int width, int height);
	~GameEngine();

	void run();
private:
	std::unique_ptr<WindowManager> windowManager;
	std::unique_ptr<Scene> scene;
};