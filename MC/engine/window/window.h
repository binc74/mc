#ifndef WINDOW_H
#define WINDOW_H

#include <vector>
#include <glew.h>
#include <glfw3.h>

#include "../graphics/mesh.h"
#include "../graphics/material.h"
#include "../graphics/texture2d.h"
#include "../graphics/shader.h"
#include "../graphics/core/projection_matrix.h"
#include "../camera/camera.h"
#include "../graphics/shapes/rect_prism.h"

#include "../../game/renderer/master_renderer.h"

namespace engine {
	class Window {
	private:
		int window_height, window_width;
		const char* window_name;
		engine::Camera* camera;
		engine::ProjectionMatrix* proj_matrix;
		std::vector<engine::Shader*> shaders;
		std::vector<engine::Material*> materials;
		std::vector<engine::Mesh*> meshes;
		std::vector<glm::vec3*> lights;

		game::MasterRenderer* mr;

		// Cursor
		float dt;
		float curr_time;
		float last_time;
		double last_mouse_x;
		double last_mouse_y;
		double mouse_x;
		double mouse_y;
		double mouse_offset_x;
		double mouse_offset_y;
		bool is_first_mouse;

		void initGLEW();
		void initOpenglOpt(bool is_fill);
		void initCamera();
		void initProjectionMatrix();
		void initShaders();
		void initTexturesOpt();
		void initMeshes();
		void initMaterials();
		void initLights();
		void initUniform();
		void updateMouseInput();
		void updateKeyboardInput();
		void updateInput();
		void updateUniforms();
		void updateTime();

	public:
		GLFWwindow* window;
		int frame_buffer_width, frame_buffer_height;

		Window(int window_width, int window_height, const char* window_name);
		~Window();
		void init(int context_major, int context_minor, bool is_full_screen);
		bool shouldClose();
		void update();
		void render();
		void initShader(engine::Shader* shader);
	};
}

#endif