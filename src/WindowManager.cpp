#include <WindowManager.h>

WindowManager::WindowManager(const std::string& title, int width, int height)
{
	if (glfwInit())
		std::cout << "DEBUG: FAILED TO INIT GLFW" << std::endl;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	if (!window) {
		std::cerr << "DEBUG: FAILED TO CREATE A GLFW WINDOW" << std::endl;
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "Failed to initialize GLAD" << std::endl;
		glfwTerminate();
	}
}

WindowManager::~WindowManager()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}
