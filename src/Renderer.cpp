#include <Renderer.h>

void Renderer::render(WindowManager& windowManager, Scene& scene)
{
	while (!windowManager.shouldClose()) {
		Renderer::clearColor(1.0f, 1.0f, 1.0f, 1.0f);
		Renderer::clearBuffer(GL_COLOR_BUFFER_BIT);

		for (int i = 0; i < scene.getEntities().size(); i++) {
			Renderer::renderEntity(scene.getEntities().at(i));
		}

		windowManager.swapBuffers();
		windowManager.pullEvents();
	}

}

void Renderer::renderEntity(Entity& entity)
{
	entity.getShader().use();
	glm::mat4& model = entity.getTransform().getModelMatrix();
	entity.getShader().setMat4(model, "model");
	entity.getMesh().render();
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
