#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

class WindowManager
{
public:
	WindowManager(const std::string& title, int width, int height);
	~WindowManager();

	inline GLFWwindow* getWindow() { return window; };

private:
	GLFWwindow* window;
};