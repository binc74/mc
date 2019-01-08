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
		delete camera;
		delete proj_matrix;

		for (Shader* it : shaders) {
			delete it;
		}

		for (Material* it : materials) {
			delete it;
		}

		for (Mesh* it : meshes) {
			delete it;
		}

		for (glm::vec3* it : lights) {
			delete it;
		}

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

		initCamera();
		initProjectionMatrix();
		initShaders();
		initTexturesOpt();
		initMeshes();
		initLights();
		initUniform();
	}

	void Window::initCamera() {
		camera = new Camera();
		camera->setDirectionUp(0.f, 1.f, 0.f);
		camera->setCameraFront(0.f, 0.f, -1.f);
		camera->setCameraPosition(0.f, 0.f, 3.f);
	}

	void Window::initProjectionMatrix() {
		proj_matrix = new ProjectionMatrix(90.f, 0.1f, 1000.f);
	}

	void Window::initShaders() {
		this->shaders.push_back(new Shader("resources/shaders/vertex_core.glsl", 
			"resources/shaders/fragment_core.glsl"));
	}

	void Window::initTexturesOpt() {
		Texture::initTextureOpt2D();
	}

	void Window::initMaterials() {
		materials.push_back(new Material(glm::vec3(0.1f), glm::vec3(1.f), glm::vec3(1.f)));
	}

	void Window::initMeshes() {
		engine::Rectangle* sq = new Rectangle(glm::vec3(0, 0, 0), glm::vec3(0, -1, 0), glm::vec3(1, -1, 0), 1, 1);

		sq->addTexture(new Texture2D("resources/textures/1.png"));
		sq->addTexture(new Texture2D("resources/textures/2.png"));
		
		meshes.push_back(sq);
	}

	void Window::initLights() {
		lights.push_back(new glm::vec3(0.f, 0.f, 3.f));
	}

	void Window::initUniform() {
		shaders[0]->use();
		shaders[0]->setUniformMat4fv(meshes[0]->model_matrix->getMatrix(), "model_matrix");
		shaders[0]->setUniformMat4fv(camera->getViewMatrix(), "view_matrix");
		shaders[0]->setUniformMat4fv(proj_matrix->getMatrix(frame_buffer_width, frame_buffer_height), "projection_matrix");
		shaders[0]->setUniform3fv(*lights[0], "light_pos0");

		shaders[0]->setUniform3fv(camera->camera_position, "camera_pos");
		shaders[0]->unuse();
	}

	void Window::updateInput() {
		ModelMatrix* mm = meshes[0]->model_matrix;

		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			glfwSetWindowShouldClose(window, GLFW_TRUE);
		}
		else if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
			mm->position.z -= 0.1f;
		}
		else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
			mm->position.z += 0.1f;
		}
		else if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
			mm->position.x -= 0.1f;
		}
		else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
			mm->position.x += 0.1f;
		}
		else if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
			mm->rotation.z += 0.1f;
		}
		else if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {
			mm->rotation.z -= 0.1f;
		}
		else if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS) {
			mm->rotation.y += 0.5f;
		}
		else if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS) {
			mm->rotation.y -= 0.5f;
		}
	}

	void Window::updateUniforms() {
		glfwGetFramebufferSize(window, &frame_buffer_width, &frame_buffer_height);

		shaders[0]->setUniformMat4fv(proj_matrix->getMatrix(
			frame_buffer_width, frame_buffer_height), "projection_matrix");
	}

	bool Window::shouldClose() {
		return glfwWindowShouldClose(window);
	}

	void Window::update() {
		glfwPollEvents();

		updateInput();
	}

	void Window::render() {
		glClearColor(0.f, 0.f, 0.f, 1.f); // rgba
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT); // clear the three buffers
		updateUniforms();

		shaders[0]->use();

		for (auto it: meshes) {
			it->update(shaders[0]);
			it->render(shaders[0], materials[0]);
		}		

		glfwSwapBuffers(window);
		glFlush();

		glBindVertexArray(0);
		shaders[0]->unuse();
		glActiveTexture(0);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void Window::initShader(engine::Shader* shader) {
		//this->shader = shader;
	}
}
