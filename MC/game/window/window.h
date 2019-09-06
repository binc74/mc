#ifndef WINDOW_H
#define WINDOW_H

#include <vector>
#include <glew.h>
#include <glfw3.h>

#include "../graphics/material.h"
#include "../graphics/shader.h"
#include "../graphics/core/projection_matrix.h"

#include "../world/world.h"
#include "../player/player.h"

#include "../graphics/renderer/font_renderer.h"

namespace mc {
	class Window {
	private:
		int window_height, window_width;
		const char* window_name;
		mc::ProjectionMatrix* proj_matrix;
		mc::Shader* shader;
		mc::Material* material;
		std::vector<glm::vec3> lights;

		mc::Player* player;

		void initGLEW();
		void initOpenglOpt(bool is_fill);
		void initProjectionMatrix();
		void initTexturesOpt();
		void initLights();		
		void updateUniforms();

	public:
		GLFWwindow* window;
		int frame_buffer_width, frame_buffer_height;

		Window(int window_width, int window_height, const char* window_name);
		~Window();

		void initUniform();
		void init(int context_major, int context_minor, bool is_full_screen);
		void setShader(mc::Shader* shader);
		void setMaterial(mc::Material* material);
		void setPlayer(mc::Player* player);
		bool shouldClose();
		void update();
		void render(mc::World* world);
	};
}

#endif