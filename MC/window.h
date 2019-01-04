#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <fstream>
#include <string>

#include <glew.h>
#include <glfw3.h>

namespace engine {
	class Window {
	private:
		int window_height, window_width;
		const char* window_name;

		void GLEWInit();
		void OpenglOptInit(bool is_fill);
	public:
		GLFWwindow* window;

		Window(int window_width, int window_height, const char* window_name);
		~Window();
		void Init(int context_major, int context_minor, bool is_full_screen);
		bool ShouldClose();
		void Update();
	};
}

#endif