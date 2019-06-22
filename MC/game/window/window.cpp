#include "window.h"

#include "../controllers/commands/include_command.h"
#include "../controllers/keyboard_controller.h"
#include "../../game/entity_type.h"

namespace game {
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
		delete world;

		shaders[0]->unuse();

		for (Shader* it : shaders) {
			delete it;
		}

		for (Material* it : materials) {
			delete it;
		}

		for (Mesh2D* it : meshes) {
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
		initControllers();
	}

	void Window::initControllers() {
		mc.addController(new MouseController(window, camera));
		
		KeyboardController* kc = new KeyboardController(window);
		kc->addInputCommand(GLFW_KEY_ESCAPE, new CloseWindowCommand(window));
		kc->addInputCommand(GLFW_KEY_W, new MoveFrontCommand(camera));
		kc->addInputCommand(GLFW_KEY_S, new MoveBackCommand(camera));
		kc->addInputCommand(GLFW_KEY_A, new MoveLeftCommand(camera));
		kc->addInputCommand(GLFW_KEY_D, new MoveRightCommand(camera));
		kc->addInputCommand(GLFW_KEY_SPACE, new MoveUpCommand(camera));
		kc->addInputCommand(GLFW_KEY_Q, new MoveDownCommand(camera));

		mc.addController(kc);
	}

	void Window::initCamera() {
		camera = new Camera();
		camera->setDirectionUp(0.f, 1.f, 0.f);
		camera->setCameraFront(0.f, 0.f, -1.f);
		camera->setCameraPosition(0.f, 0.f, 3.f);
	}

	void Window::initProjectionMatrix() {
		proj_matrix = new ProjectionMatrix(90.f, 0.1f, 100.f);
	}

	void Window::initShaders() {
		this->shaders.push_back(new Shader("resources/shaders/vertex_fix.glsl", 
			"resources/shaders/fragment_core.glsl"));
	}

	void Window::initTexturesOpt() {
		Texture2D::initTextureOpt2D();
	}

	void Window::initMaterials() {
		materials.push_back(new Material(glm::vec3(0.1f), glm::vec3(1.f), glm::vec3(1.f)));
	}

	void Window::initMeshes() {
		world = new World(shaders[0], materials[0]);

		//RectPrism* rp = new RectPrism(0, -1, 0, 1);
		//mr->addModel(game::EntityType::SOIL, rp);

		Cube* g = new Grass(0,0,0);
		world->addObj(g);

		//for (int i = -5; i < 20; ++i) {
		//	for (int j = -5; j < 20; ++j) {
		//		Grass* g = new Grass(i, -1, j);
		//		world->addObj(g);
		//	}
		//}	

		//for (int i = 0; i < 5; ++i) {
		//	for (int j = -5; j < 0; ++j) {
		//		Grass* g = new Grass(j, i, -5);
		//		world->addObj(g);
		//	}
		//}
	}

	void Window::initLights() {
		lights.push_back(camera->camera_position);
	}

	void Window::initUniform() {

		shaders[0]->setUniformMat4fv(camera->getViewMatrix(), "view_matrix");
		shaders[0]->setUniformMat4fv(proj_matrix->getMatrix(frame_buffer_width, frame_buffer_height), "projection_matrix");
		shaders[0]->setUniform3fv(*lights[0], "light_pos0");

		shaders[0]->setUniform3fv(*(camera->camera_position), "camera_pos");

	}

	void Window::updateInput() {
		mc.updateInput();
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
		updateInput();
	}

	void Window::render() {
		glClearColor(0.f, 0.f, 0.f, 1.f); // rgba
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT); // clear the three buffers
		shaders[0]->use();

		updateUniforms();

		world->draw();

		glfwSwapBuffers(window);
		glFlush();

		shaders[0]->unuse();
	}

	void Window::initShader(Shader* shader) {
		//this->shader = shader;
	}
}
