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
#include "../graphics/shapes/square.h"

namespace engine {
	class Game {
	private:
		int window_height, window_width;
		const char* window_name;
		engine::Camera* camera;
		engine::ProjectionMatrix* proj_matrix;
		std::vector<engine::Shader*> shaders;
		std::vector<engine::Texture*> textures;
		std::vector<engine::Material*> materials;
		std::vector<engine::Mesh*> meshes;
		std::vector<glm::vec3*> lights;

		void initGLEW();
		void initOpenglOpt(bool is_fill);
		void initCamera();
		void initProjectionMatrix();
		void initShaders();
		void initTextures();
		void initMaterials();
		void initMeshes();
		void initLights();
		void initUniform();
		void updateInput();
		void updateUniforms();
	public:
		GLFWwindow* window;
		int frame_buffer_width, frame_buffer_height;

		Game(int window_width, int window_height, const char* window_name);
		~Game();
		void init(int context_major, int context_minor, bool is_full_screen);
		bool shouldClose();
		void update();
		void render();
		void initShader(engine::Shader* shader);
	};
}

#endif