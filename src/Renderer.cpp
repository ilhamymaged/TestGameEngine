#include <Renderer.h>

Camera Renderer::camera;
void Renderer::render(WindowManager& windowManager, Scene& scene)
{
	while (!windowManager.shouldClose()) {
        glEnable(GL_DEPTH_TEST);
        Renderer::clearColor(1.0f, 1.0f, 1.0f, 1.0f);
        Renderer::clearBuffer(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        if (glfwGetKey(windowManager.getWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(windowManager.getWindow(), true);

        for (Entity& entity : scene.getEntities()) {
            Shader& shader = entity.getShader();
            shader.use(); 

            glm::mat4 view = camera.getViewMat();
            glm::mat4 projection = glm::perspective(camera.getFOV(),
                (float)windowManager.getWidth() / windowManager.getHeight(),0.1f, 100.0f);
            glm::mat4 model = entity.getTransform().getModelMatrix();

            shader.setMat4(model, "model");
            shader.setMat4(view, "view");
            shader.setMat4(projection, "projection");

            entity.getMesh().render();
        }

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
