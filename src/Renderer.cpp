#include <Renderer.h>

void Renderer::run(WindowManager& windowManager)
{
	while (!windowManager.shouldClose()) {
		Renderer::clearColor(1.0f, 1.0f, 1.0f, 1.0f);
		Renderer::clearBuffer(GL_COLOR_BUFFER_BIT);

		windowManager.swapBuffers();
		windowManager.pullEvents();
	}

}

void Renderer::clearColor(const float& v1, const float& v2, const float& v3, 
	const float& v4)
{
	glClearColor(v1, v2, v3, v4);
}

void Renderer::clearBuffer(GLenum buffer)
{
	glClear(buffer);
}
