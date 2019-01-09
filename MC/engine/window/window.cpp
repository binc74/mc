#include "window.h"

namespace engine {
	static void framebuffer_resize_callback(GLFWwindow* window, int width, int height) {
		glViewport(0, 0, width, height);
	}

	Window::Window(int window_width, int window_height, const char* window_name) {
		this->window_height = window_height;
		this->window_width = window_width;
		this->window_name = window_name;		

		dt = 0.f;
		curr_time = 0.f;
		last_time = 0.f;
		last_mouse_x = 0.0;
		last_mouse_y = 0.0;
		mouse_x = 0.0;
		mouse_y = 0.0;
		mouse_offset_x = 0.0;
		mouse_offset_y = 0.0;
		is_first_mouse = true;
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

		initCamera();
		initProjectionMatrix();
		initShaders();
		initTexturesOpt();
		initMaterials();
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
		RectPrism* rp1 = new RectPrism(0, 0, 0, 1);
		RectPrism* rp2 = new RectPrism(1, 0, 0, 1);
		RectPrism* rp3 = new RectPrism(2, 0, 0, 1);

		Texture* t1 = new Texture2D("resources/textures/1.png");
		Texture* t2 = new Texture2D("resources/textures/2.png");

		rp1->addTextureAll(t1);
		rp1->addTextureAll(t2);
		rp2->addTextureAll(t1);
		rp2->addTextureAll(t2);
		rp3->addTextureAll(t1);
		rp3->addTextureAll(t2);

		meshes.push_back(rp1);
		meshes.push_back(rp2);
		meshes.push_back(rp3);
	}

	void Window::initLights() {
		lights.push_back(camera->camera_position);
	}

	void Window::initUniform() {
		shaders[0]->use();
		shaders[0]->setUniformMat4fv(camera->getViewMatrix(), "view_matrix");
		shaders[0]->setUniformMat4fv(proj_matrix->getMatrix(frame_buffer_width, frame_buffer_height), "projection_matrix");
		shaders[0]->setUniform3fv(*lights[0], "light_pos0");

		shaders[0]->setUniform3fv(*(camera->camera_position), "camera_pos");
		shaders[0]->unuse();
	}

	void Window::updateTime() {
		curr_time = (float)glfwGetTime();
		dt = curr_time - last_time;
		last_time = curr_time;
	}

	void Window::updateInput() {
		updateTime();
		updateKeyboardInput();
		updateMouseInput();
	}

	void Window::updateKeyboardInput() {
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			glfwSetWindowShouldClose(window, GLFW_TRUE);
		}
		else if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
			camera->goFront(dt);
		}
		else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
			camera->goBack(dt);
		}
		else if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
			camera->goLeft(dt);
		}
		else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
			camera->goRight(dt);
		}
		else if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
			camera->goUp(dt);
		}
		else if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {
			camera->goDown(dt);
		}
		else if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS) {

		}
		else if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS) {

		}
	}

	void Window::updateMouseInput() {
		glfwGetCursorPos(window, &mouse_x, &mouse_y);

		if (is_first_mouse) {
			last_mouse_x = mouse_x;
			last_mouse_y = mouse_y;
			is_first_mouse = false;
		}

		mouse_offset_x = mouse_x - last_mouse_x;
		mouse_offset_y = mouse_y - last_mouse_y;
		last_mouse_x = mouse_x;
		last_mouse_y = mouse_y;
	}

	void Window::updateUniforms() {
		glfwGetFramebufferSize(window, &frame_buffer_width, &frame_buffer_height);

		shaders[0]->setUniformMat4fv(camera->getViewMatrix(), "view_matrix");
		shaders[0]->setUniform3fv(*(camera->camera_position), "camera_pos");
		shaders[0]->setUniform3fv(*(camera->camera_position), "light_pos0");

		shaders[0]->setUniformMat4fv(proj_matrix->getMatrix(
			frame_buffer_width, frame_buffer_height), "projection_matrix");
	}

	bool Window::shouldClose() {
		return glfwWindowShouldClose(window);
	}

	void Window::update() {
		glfwPollEvents();

		updateInput();
		camera->updateByMouseInput(dt, mouse_offset_x, mouse_offset_y);
	}

	void Window::render() {
		glClearColor(0.f, 0.f, 0.f, 1.f); // rgba
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT); // clear the three buffers
		shaders[0]->use();

		updateUniforms();

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
