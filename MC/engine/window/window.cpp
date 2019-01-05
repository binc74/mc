#include "window.h"

namespace engine {
	static void framebuffer_resize_callback(GLFWwindow* window, int width, int height) {
		glViewport(0, 0, width, height);
	}

	Window::Window(int window_width, int window_height, const char* window_name) {	
		this->window_height = window_height;
		this->window_width = window_width;
		this->window_name = window_name;	
	}

	Window::~Window() {
		glfwTerminate();
		glfwDestroyWindow(window);
	}

	void Window::initGLEW() {
		// Init GREW which links opengl functions to driver
		glewExperimental = GL_TRUE;

		// check error
		if (glewInit() != GLEW_OK) {
			std::cerr << "Error init GLEW!" << std::endl;
			glfwTerminate();
		}
	}

	void Window::openglOptInit(bool is_fill) {
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_CULL_FACE);			// enable z coordinate
		glCullFace(GL_BACK);			// don't draw back of a face
		glFrontFace(GL_CCW);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glPolygonMode(GL_FRONT_AND_BACK, is_fill? GL_FILL : GL_LINE);
	}

	void Window::init(int context_major, int context_minor, bool is_full_screen) {
		glfwInit();

		// Opengl target: major.minor
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, context_major);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, context_minor);
		glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

		GLFWmonitor* monitor = is_full_screen? glfwGetPrimaryMonitor() : NULL;
		window = glfwCreateWindow(window_width, window_height, window_name, monitor, NULL);

		glfwGetFramebufferSize(window, &frame_buffer_width, &frame_buffer_height);

		// Set the width and height of framebuffer same as the window
		glfwSetFramebufferSizeCallback(window, framebuffer_resize_callback);

		// Make game context current
		glfwMakeContextCurrent(window);

		// Init GLEW;
		this->initGLEW();

		// Init Opengl option
		this->openglOptInit(true);
	}

	bool Window::shouldClose() {
		return glfwWindowShouldClose(window);
	}

	void Window::update() {
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	void Window::initShader(engine::Shader* shader) {
		this->shader = shader;
	}
}
