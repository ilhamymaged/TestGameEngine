#pragma once

#include <WindowManager.h>

class Renderer
{
public:
	static void run(WindowManager& windowManager);
	
private:
	static void clearColor(const float& v1, const float& v2, const float& v3,
	const float& v4);
	static void clearBuffer(GLenum buffer);
};