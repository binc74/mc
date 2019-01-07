#include "game.h"

namespace engine {
	static void framebuffer_resize_callback(GLFWwindow* window, int width, int height) {
		glViewport(0, 0, width, height);
	}

	Game::Game(int window_width, int window_height, const char* window_name) {
		this->window_height = window_height;
		this->window_width = window_width;
		this->window_name = window_name;		
	}

	Game::~Game() {
		delete camera;
		delete proj_matrix;

		for (Shader* it : shaders) {
			delete it;
		}

		for (Texture* it : textures) {
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

	void Game::initGLEW() {
		// Init GREW which links opengl functions to driver
		glewExperimental = GL_TRUE;

		// check error
		if (glewInit() != GLEW_OK) {
			std::cerr << "Error init GLEW!" << std::endl;
			glfwTerminate();
		}
	}

	void Game::initOpenglOpt(bool is_fill) {
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_CULL_FACE);			// enable z coordinate
		glCullFace(GL_BACK);			// don't draw back of a face
		glFrontFace(GL_CCW);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glPolygonMode(GL_FRONT_AND_BACK, is_fill? GL_FILL : GL_LINE);
	}

	void Game::init(int context_major, int context_minor, bool is_full_screen) {
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
		initTextures();
		initMaterials();
		initMeshes();
		initLights();
		initUniform();
	}

	void Game::initCamera() {
		camera = new Camera();
		camera->setDirectionUp(0.f, 1.f, 0.f);
		camera->setCameraFront(0.f, 0.f, -1.f);
		camera->setCameraPosition(0.f, 0.f, 1.f);
	}

	void Game::initProjectionMatrix() {
		proj_matrix = new ProjectionMatrix(90.f, 0.1f, 1000.f);
	}

	void Game::initShaders() {
		this->shaders.push_back(new Shader("resources/shaders/vertex_core.glsl", 
			"resources/shaders/fragment_core.glsl"));
	}

	void Game::initTextures() {
		Texture::initTextureOpt2D();

		textures.push_back(new Texture2D("resources/textures/123.png"));
		textures.push_back(new Texture2D("resources/textures/234.png"));
	}

	void Game::initMaterials() {
		materials.push_back(new Material(glm::vec3(0.1f), glm::vec3(1.f),
			glm::vec3(1.f), 0, 1));
	}

	void Game::initMeshes() {
		meshes.push_back(new Square(0, 0, 0, 2, 2, 1, 1));
	}

	void Game::initLights() {
		lights.push_back(new glm::vec3(0.f, 0.f, 1.f));
	}

	void Game::initUniform() {
		shaders[0]->use();
		shaders[0]->setUniformMat4fv(meshes[0]->model_matrix->getMatrix(), "model_matrix");
		shaders[0]->setUniformMat4fv(camera->getViewMatrix(), "view_matrix");
		shaders[0]->setUniformMat4fv(proj_matrix->getMatrix(frame_buffer_width, frame_buffer_height), "projection_matrix");
		shaders[0]->setUniform3fv(*lights[0], "light_pos0");

		shaders[0]->setUniform3fv(camera->camera_position, "camera_pos");
		shaders[0]->unuse();
	}

	void Game::updateInput() {
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

	void Game::updateUniforms() {
		materials[0]->sendToShader(*shaders[0]);

		glfwGetFramebufferSize(window, &frame_buffer_width, &frame_buffer_height);

		shaders[0]->setUniformMat4fv(proj_matrix->getMatrix(
			frame_buffer_width, frame_buffer_height), "projection_matrix");
	}

	bool Game::shouldClose() {
		return glfwWindowShouldClose(window);
	}

	void Game::update() {
		glfwPollEvents();

		updateInput();
	}

	void Game::render() {
		glClearColor(0.f, 0.f, 0.f, 1.f); // rgba
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT); // clear the three buffers

		materials[0]->sendToShader(*shaders[0]);

		shaders[0]->setUniform1i(0, "texture0");
		shaders[0]->setUniform1i(1, "texture1");
		
		updateUniforms();

		shaders[0]->use();

		textures[0]->bind(0);
		textures[1]->bind(1);

		meshes[0]->update(shaders[0]);
		meshes[0]->render();

		glfwSwapBuffers(window);
		glFlush();

		glBindVertexArray(0);
		shaders[0]->unuse();
		glActiveTexture(0);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void Game::initShader(engine::Shader* shader) {
		//this->shader = shader;
	}
}
