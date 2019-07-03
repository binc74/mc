#include "window.h"

#include "../controllers/commands/include_command.h"
#include "../controllers/keyboard_controller.h"

namespace mc {
	static void framebuffer_resize_callback(GLFWwindow* window, int width, int height) {
		glViewport(0, 0, width, height);
	}

	Window::Window(int window_width, int window_height, const char* window_name) {
		this->window_height = window_height;
		this->window_width = window_width;
		this->window_name = window_name;		
	}

	Window::~Window() {
		delete proj_matrix;

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

	void Window::initOpenglOpt(bool is_fill) {
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_CULL_FACE);			// enable z coordinate
		glCullFace(GL_BACK);			// don't draw back of a face
		glFrontFace(GL_CCW);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glPolygonMode(GL_FRONT_AND_BACK, is_fill? GL_FILL : GL_LINE);

		// Enable cursor input and hide the cursor inside the window
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
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
		glViewport(0, 0, frame_buffer_width, frame_buffer_height);

		// Set the width and height of framebuffer same as the window
		glfwSetFramebufferSizeCallback(window, framebuffer_resize_callback);

		// Make game context current
		glfwMakeContextCurrent(window);

		// Init GLEW;
		initGLEW();

		// Init Opengl option
		initOpenglOpt(true);

		initProjectionMatrix();
		initTexturesOpt();
		initLights();
		//initUniform();
	}

	void Window::initProjectionMatrix() {
		proj_matrix = new ProjectionMatrix(90.f, 0.1f, 100.f);
	}

	void Window::initTexturesOpt() {
		Texture2D::initTextureOpt2D();
	}

	void Window::initLights() {
		lights.push_back(player->pos);
	}

	void Window::initUniform() {

		shader->setUniformMat4fv(player->getViewMatrix(), "view_matrix");
		shader->setUniformMat4fv(proj_matrix->getMatrix(frame_buffer_width, frame_buffer_height), "projection_matrix");
		shader->setUniform3fv(lights[0], "light_pos0");

		shader->setUniform3fv(player->pos, "camera_pos");

	}

	void Window::updateUniforms() {
		glfwGetFramebufferSize(window, &frame_buffer_width, &frame_buffer_height);

		shader->setUniformMat4fv(player->getViewMatrix(), "view_matrix");
		shader->setUniform3fv(player->pos, "camera_pos");
		shader->setUniform3fv(player->pos, "light_pos0");

		shader->setUniformMat4fv(proj_matrix->getMatrix(
			frame_buffer_width, frame_buffer_height), "projection_matrix");
	}

	bool Window::shouldClose() {
		return glfwWindowShouldClose(window);
	}

	void Window::update() {	
	}

	void Window::render(mc::World* world) {
		glClearColor(0.f, 0.f, 0.f, 1.f); // rgba
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear the buffers
		shader->use();

		updateUniforms();

		world->draw();

		glfwSwapBuffers(window);
		glFlush();

		shader->unuse();
	}

	void Window::setPlayer(mc::Player* player) {
		this->player = player;
	}

	void Window::setShader(mc::Shader* shader) {
		this->shader = shader;
	}

	void Window::setMaterial(mc::Material* material) {
		this->material = material;
	}
}
