#ifndef WINDOW_H
#define WINDOW_H

#include <glew.h>
#include <glfw3.h>
#include "../graphics/shader.h"

namespace engine {
	class Window {
	private:
		int window_height, window_width;
		const char* window_name;
		engine::Shader* shader;

		void initGLEW();
		void openglOptInit(bool is_fill);

	public:
		GLFWwindow* window;
		int frame_buffer_width, frame_buffer_height;

		Window(int window_width, int window_height, const char* window_name);
		~Window();
		void init(int context_major, int context_minor, bool is_full_screen);
		bool shouldClose();
		void update();
		void initShader(engine::Shader* shader);
	};
}

#endif