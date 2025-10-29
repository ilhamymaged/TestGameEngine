#pragma once

#include <WindowManager.h>
#include <Scene.h>
#include <Entity.h>
#include <Camera.h>

class Scene;

class Renderer
{
public:
	static void render(WindowManager& windowManager, Scene& scene);
	
private:
	static Camera camera;

private:
	static void clearColor(const float& v1, const float& v2, const float& v3,
	const float& v4);
	static void clearBuffer(GLenum buffer);
};