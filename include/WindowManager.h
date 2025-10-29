#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

class WindowManager
{
public:
	WindowManager(const std::string& title, int width, int height);
	~WindowManager();

	inline void swapBuffers() { glfwSwapBuffers(window); }
	inline void pullEvents() { glfwPollEvents(); }
	inline bool shouldClose() { return glfwWindowShouldClose(window); }

	inline GLFWwindow* getWindow() { return window; };
	inline int getWidth() { return width; }
	inline int getHeight() { return height; }

private:
	GLFWwindow* window;
	int width;
	int height;
};