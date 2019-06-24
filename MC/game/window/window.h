#ifndef WINDOW_H
#define WINDOW_H

#include <vector>
#include <glew.h>
#include <glfw3.h>

#include "../graphics/mesh2d.h"
#include "../graphics/material.h"
#include "../graphics/texture2d.h"
#include "../graphics/shader.h"
#include "../graphics/core/projection_matrix.h"
#include "../camera/camera.h"

#include "../objects/cube.h"
#include "../objects/cubeobjs/soil.h"
#include "../objects/cubeobjs/grass.h"

#include "../world/world.h"
#include "../controllers/main_controller.h"
#include "../controllers/mouse_controller.h"
#include "../controllers/keyboard_controller.h"

namespace game {
	class Window {
	private:
		int window_height, window_width;
		const char* window_name;
		game::Camera* camera;
		game::ProjectionMatrix* proj_matrix;
		std::vector<Shader*> shaders;
		std::vector<Material*> materials;
		std::vector<Mesh2D*> meshes;
		std::vector<glm::vec3*> lights;

		game::World* world;
		game::MainController mc;

		void initGLEW();
		void initOpenglOpt(bool is_fill);
		void initControllers();
		void initCamera();
		void initProjectionMatrix();
		void initShaders();
		void initTexturesOpt();
		void initMeshes();
		void initMaterials();
		void initLights();
		void initUniform();
		void updateInput();
		void updateUniforms();

	public:
		GLFWwindow* window;
		int frame_buffer_width, frame_buffer_height;

		Window(int window_width, int window_height, const char* window_name);
		~Window();
		void init(int context_major, int context_minor, bool is_full_screen);
		bool shouldClose();
		void update();
		void render();
		void initShader(Shader* shader);
	};
}

#endif